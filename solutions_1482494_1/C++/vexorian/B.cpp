/* ******************************************************************************
ooooo      ooo   .oooooo.        ooooooooooooo   .oooooo.   
`888b.     `8'  d8P'  `Y8b       8'   888   `8  d8P'  `Y8b  
 8 `88b.    8  888      888           888      888      888 
 8   `88b.  8  888      888           888      888      888 
 8     `88b.8  888      888           888      888      888 
 8       `888  `88b    d88'           888      `88b    d88' 
o8o        `8   `Y8bood8P'           o888o      `Y8bood8P'  

  .oooooo.   ooooo  .oooooo..o ooooooooo.         .o.       .o. 
 d8P'  `Y8b  `888' d8P'    `Y8 `888   `Y88.      .888.      888 
888           888  Y88bo.       888   .d88'     .8"888.     888 
888           888   `"Y8888o.   888ooo88P'     .8' `888.    Y8P 
888           888       `"Y88b  888           .88ooo8888.   `8' 
`88b    ooo   888  oo     .d8P  888          .8'     `888.  .o. 
 `Y8bood8P'  o888o 8""88888P'  o888o        o88o     o8888o Y8P 
                                                                
   
   https://www.eff.org/deeplinks/2012/04/eff-condemns-cispa-vows-take-fight-senate
   
   https://www.eff.org/deeplinks/2012/04/even-rogers-amendments-cispa-still-surveillance-bill
   
   https://www.eff.org/deeplinks/2012/04/cispa-national-security-and-nsa-ability-read-your-emails
   
   Google is not only supporting this mess. Worse, they are doing it backstage,
   avoiding the public light.
   
     
   http://thenextweb.com/insider/2012/04/23/google-admits-to-lobbying-on-cispa-but-wont-say-which-way/
   
     Google supports CISPA like most companies who own user data:
   https://plus.google.com/112352920206354603958/posts/Zp48oiuAYcC
   
*/
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
#define make_triple(a,b,c) make_pair(a, make_pair(b,c))
int solve(int N, int* a, int* b) {
    int stars = 0, games = 0;
    int got[N];
    fill(got, got+N, 0);
    const int INF = 3*N;
    while (stars < 2*N) {
        pair<int, pair<int,int> > best = make_triple(0,0,-1);
        for (int i=0; i<N; i++) {
            if (got[i] == 1) {
                if (b[i] <= stars) {
                    //can do...
                    best = std::max(best, make_triple(1, INF, i) );
                }
            } else if (got[i] == 0) {
                if (b[i] <= stars) {
                    best = std::max(best, make_triple(2, INF, i) );
                } else if (a[i] <= stars) {
                    best = std::max(best, make_triple(1, b[i], i) );
                }
            }
        }
        int p = best.second.second;
        if (p == -1) {
            return -1;
        }
        games++;
        //cout << "game "<<games<<" : "<<p<<endl;
        if (got[p] == 1) {
            got[p] = 2;
            stars++;
        } else if (got[p] == 0) {
            got[p] = best.first;
            stars += got[p];
        }
        
    }
    return games;
}

inline void init()
{
}
//=========================================================
// I/O:
//
void run(const char* x)
{
    int r = system(x);
    cerr<<x<<" "<<"("<<r<<")"<<endl;
}
int main(int argc, const char* argv[])
{
    int mode = 0;
    if(argc >= 2) sscanf(argv[1],"%d",&mode);
    if ( ( mode == 0 ) && ENABLE_MULTI_PROCESS )
    {
        string inputfile = ".input";
        run("cat > .input");
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
        run(command.c_str());
        assert( freopen(inputfile.c_str(),"r",stdin) );
    }
    
    init();
    int TestCases;
    cin>>TestCases;

    for (int _i=1;_i<=TestCases;_i++) {
        /* read input goes here */
        int N;
        cin >> N;
        int a[N], b[N];
        for (int i=0; i<N; i++) {
            cin >> a[i] >> b[i];
        }
        
        if( (mode==0) || ( (mode!=2)== (_i*2<=TestCases) ) ) {            
            cerr<<"["<<_i<<" / "<<TestCases<<"]"<<endl;
            /* program call goes here */
            int res = solve(N, a, b);
            /* output result goes here */
            cout<<"Case #"<<_i<<": ";
            if (res == -1) {
                cout << "Too Bad";
            } else {
                cout << res;
            }
            
            cout<<endl;            
        }
        else if(mode!=2) break;
        
        assert(cin);
    }
    if(mode==2) {
        run("echo done > .finished");
    } else if(mode==1) {
        struct stat stFileInfo;
        while( stat(".finished",&stFileInfo)!=0);
        run("cat .tem");
    }
    return 0;
}
