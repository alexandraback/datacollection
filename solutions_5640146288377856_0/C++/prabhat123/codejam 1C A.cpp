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
int main()
{
    ifstream IF;
    ofstream OF;
    int t,ans;
    IF.open("input.txt");
    OF.open("output.txt");
    IF >> t;
    for(int i=1;i<=t;i++)
    {
        int r,c,w;
        IF >> r >> c >> w;
        if(c%w==0)
            ans=c/w-1+w;
        else
            ans=c/w+w;
        OF << "Case #" << i << ": ";
        OF << ans << " \n";
    }
    IF.close();
    OF.close();
    return 0;
}


