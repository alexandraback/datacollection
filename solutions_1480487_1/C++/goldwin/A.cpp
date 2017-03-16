#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 210

using namespace std;

int n;
double data[MAX];
double ans[MAX];
bool flags[MAX];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        scanf("%d",&n);
        double sums = 0;
        FOR(i,0,n-1) 
        {
            scanf("%lf",&data[i]);
            sums += data[i];
        }
        printf("Case #%d:",ca);
        int n2 = n;
        memset(flags,false,sizeof(flags));
        bool _b = false;
        double sums2 = 0;
        do
        {
            _b = false;
            double avg = (2 * sums - sums2)/ n2;
            //cerr << avg << " " << n2 << " " << sums2 << endl;
            FOR(i,0,n-1)
            {
                if(flags[i]) continue;
                double x = avg - data[i];
                ans[i] = x * 100 / sums;
                if(ans[i] < 0) 
                {
                    _b = true;
                    flags[i] = true;
                    ans[i] = 0;
                    n2--;
                    sums2 += (double)data[i];
                }
            }
        }while(_b);
        sums2 = 0;
        FOR(i,0,n-1) 
        {
            sums2 += ans[i];
            printf(" %.6lf",ans[i]);
        }
        puts("");
        //if(sums2 > 100.000001) cout << "err" << sums2<< endl;
    }
    FOR(i,0,1)getchar();
    return 0;
}
