#ifdef VX_PRECOMPILED
#include "precomp.h"
typedef mpz_class big;
#else
#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>
#include<sys/stat.h>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
// http://gmplib.org/ (uncomment if solution does not use big nums)
#include "gmpxx.h"
#define big mpz_class
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64
const bool ENABLE_MULTI_PROCESS = true;
using namespace std;

//=========================================================
// program:
//
long solve(int A, int B) {
    long res = 0;
    for (int x=A; x<=B; x++) {
        ostringstream st;
        st << x;
        string s = st.str();
        set<int> seen; //is this needed?
        // OVERHEAD WITHOUT GUILT!!!
        // The fun of not having to care about constant factor or other arbitrary non-sense
        // Codejam pwns codeforces and topcoder for this.
        for (int d=1; d<s.length(); d++) {
            string t = s.substr(d) + s.substr(0,d);
            istringstream st2(t);
            int y;
            st2 >> y;
            if ( (y > x) && (B >= y) ) {
                seen.insert(y);
            }
        }
        res += seen.size();
    }
    return res;
}

inline void init(){}
//=========================================================
// I/O:
//
#define assert(x) x==0
int main(int argc, const char* argv[])
{
    int mode = 0;
    if(argc >= 2) sscanf(argv[1],"%d",&mode);
    if ( ( mode == 0 ) && ENABLE_MULTI_PROCESS )
    {
        string inputfile = ".input";
        assert( system("cat > .input") );
        /* I use a dual core CPU, so for long solutions I might use this
         multi-process thing, splitting the input in halves effectively
         halving execution time of slow solutions. But due to overhead it
         increases the time of fast solutions, so it is optional... */
        mode = 1;
        remove(".finished");
        cerr<<"--Multi process mode--"<<endl;
        //string inputfile = argv[2];
        string command = argv[0];
        command += " 2 < "+inputfile+" > .tem &";
        assert( system(command.c_str()) );
        assert( freopen(inputfile.c_str(),"r",stdin) );
    }
    
    init();
    int TestCases;
    cin>>TestCases;

    for (int _i=1;_i<=TestCases;_i++) {
        /* read input goes here */
        int A,B;
        cin >> A >> B;
        
        if( (mode==0) || ( (mode!=2)== (_i*2<=TestCases) ) ) {            
            cerr<<"["<<_i<<" / "<<TestCases<<"]"<<endl;
            /* program call goes here */
            long res = solve(A,B);
            /* output result goes here */
            cout<<"Case #"<<_i<<": "<< res<<endl;            
        }
        else if(mode!=2) break;
        
        assert(cin);
    }
    if(mode==2) {
        assert( system("echo done > .finished") );
    } else if(mode==1) {
        struct stat stFileInfo;
        while( stat(".finished",&stFileInfo)!=0);
        assert( system("cat .tem") );
    }
    return 0;
}
