#include <bits/stdc++.h>

using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define pull(x) printf("%llu",x)
#define pll(x) printf("%lld",x)

#define pn() printf("\n")
#define loop(i, a, b) for (int i = int(a); i < int(b); i++)
#define MAXN 1000005
typedef long long int ll;
typedef unsigned long long int ull;
ll f[3000];
int main()
{
freopen("B-large.in","r",stdin);
freopen("out0_large.txt","w",stdout);

    int t,n,tmp;
    sd(t);
    loop(k,1,t+1){

        sd(n);
        loop(i,0,3000)f[i]=0;
        loop(i,0,(2*n-1)*n){
            cin>>tmp;
            f[tmp]++;
        }
        cout<<"Case #"<<k<<": ";
        loop(i,0,3000){
            if(f[i]%2==1)cout<<i<<" ";
        }
        cout<<endl;
    }









    return 0;
}

