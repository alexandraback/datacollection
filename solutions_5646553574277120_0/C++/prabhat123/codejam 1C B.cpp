#include<bits/stdc++.h>
#define D 1000000007
#define gcd __gcd
#define getcx getchar
#define pc putchar
#define mp make_pair
#define get(x) scanf("%d",&x)
#define getl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
#define bitcount __builtin_popcount
using namespace std;
typedef long long ll;
int m[500];
int main()
{
    ifstream IF;
    ofstream OF;
    int t,ans,c,d,v,i,j,k,kk;
    IF.open("input.txt");
    OF.open("output.txt");
    IF >> t;
    for(k=1;k<=t;k++)
    {
        IF >> c >> d >> v;ans=0;
        int a[d+100];kk=d;
        for(j=0;j<d;j++)
            IF >> a[j];
        for(int M=1;M<=v;M++){
        memset(m,0,sizeof m);
        m[0]=1;
        for(i=0; i<kk; i++)
            for(j=M; j>=a[i]; j--)
                m[j] |= m[j-a[i]];
        if (!m[M])
        {
            ans++;a[kk++]=M;
            sort(a,a+kk);
        }
        }
        OF << "Case #" << k << ": ";
        OF << ans << " \n";
    }
    IF.close();
    OF.close();
    return 0;
}



