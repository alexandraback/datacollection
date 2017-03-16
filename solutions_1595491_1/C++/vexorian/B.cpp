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
const bool ENABLE_MULTI_PROCESS = false;
using namespace std;

//=========================================================
// program:
//
/* score, max score , surprising */ 
bool couldBe[31][11][2];

int N, S, p;
int t[100];

const int INF = 1000;
int solve() {
    int dp[N+1][S+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for (int s=1; s<=S; s++) {
        dp[0][s] = -INF;
    }
    for (int n=1; n<=N; n++) {
        for (int s=0; s<=S; s++) {
            dp[n][s] = -INF;
            for (int surp = 0; surp < 2; surp ++) {
                if (s - surp >= 0) {
                    dp[n][s] = max(dp[n][s], couldBe[t[n-1]][p][surp] + dp[n-1][s-surp] );
                }
            }
            
        }
    }
    return dp[N][S];
}

void init()
{
    memset(couldBe, 0, sizeof(couldBe));
    // the maximum score is 30.
    for (int a=0; a<=10; a++) {
        for (int b=0; b<=10; b++) {
            for (int c=0; c<=10; c++) {
                int maxdif = 0;
                maxdif = max(maxdif, abs(a-b));
                maxdif = max(maxdif, abs(b-c));
                maxdif = max(maxdif, abs(a-c));
                int p = max(a, max(b,c));
                for (int i=p; i>=0; i--) {
                    if (maxdif == 2) {
                        couldBe[a+b+c][i][1] = true;
                    } else if (maxdif < 2) {
                        couldBe[a+b+c][i][0] = true;
                    }
                }
            }
        }
    }
    
}
//=========================================================
// I/O:
//
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
        cin >> N >> S >> p;
        for (int i=0; i<N; i++) {
            cin >> t[i];
        }
        
        if( (mode==0) || ( (mode!=2)== (_i*2<=TestCases) ) ) {            
            cerr<<"["<<_i<<" / "<<TestCases<<"]"<<endl;
            /* program call goes here */
            int x = solve();
            /* output result goes here */
            cout<<"Case #"<<_i<<": "<<x << endl;            
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
