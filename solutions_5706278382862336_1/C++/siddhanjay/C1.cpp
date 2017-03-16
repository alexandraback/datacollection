// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pl(n)                       printf("%lld",n)
#define pln(n)                      printf("%lld\n",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)
#define pn(n)                       printf("%d\n",n)


#define forall(i,a,b)               for(int i=a;i<=b;i++)
#define pb                          push_back
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())


#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map <string, int> msi;



int main()
{
	 #ifndef ONLINE_JUDGE
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
	#endif
    int t;
    s(t);
    for(int i=1;i<=t;i++)
    {
        ll p, q,gen; char c;
        scanf("%lld%c%lld",&p,&c,&q);
        if(q%2!=0)
        {
            printf("Case #%d: impossible\n",i);
        }
        else
        {
            bool fl = true;
            gen = 0;
            while(fl)
            {
                q = q/2;
                if(p/q - 1 >= 0)
                {
                    gen = gen + 1;
                    printf("Case #%d: %lld\n", i,gen);
                    fl = false;
                }
                else
                {
                    gen = gen+1;
                }
            }
        }

    }
return 0;
}
	





