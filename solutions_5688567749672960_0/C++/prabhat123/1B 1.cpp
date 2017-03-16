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
int ans[1000005];
int reverse1(int n)
{
    int ans1=0;
    while(n)
    {
        ans1=ans1*10+n%10;
        n/=10;
    }
    return ans1;
}
void precompute()
{
    for(int i=1;i<=20;i++)
        ans[i]=i;
    for(int i=21;i<1000004;i++)
    {
        if(reverse1(i)<i && i%10!=0)
            ans[i]=1+min(ans[i-1],ans[reverse1(i)]);
        else
            ans[i]=1+ans[i-1];
    }
}
int main()
{
    precompute();
    ifstream IF;
    ofstream OF;
    int t,n,l,i,j,k,f,x;
    IF.open("input.txt");
    OF.open("output.txt");
    IF >> t;
    for(i=1;i<=t;i++)
    {
        IF >> n;
        OF << "Case #" << i << ": " << ans[n] << endl;
    }
    IF.close();
    OF.close();
    return 0;
}

