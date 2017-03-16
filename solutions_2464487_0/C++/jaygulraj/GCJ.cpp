#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>

 
using namespace std;
 
#define INF (1<<29)

#define LL long long

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked

using namespace std;
int main()
{
    int t;
        LL r,n,p;
        inp(t);
        for(int i=0;i<t;i++)
        {
                inpll(r);
                inpll(p);
                n=((-1*(2*r-1))+ (long long)sqrt((2*r-1)*(2*r-1)+8*p));
                n=n/4;
                printf("Case #%d: %lld\n",i+1,n);
        }
        return 0;
}
