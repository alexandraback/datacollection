#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef unsigned long long llu;

#define author ayushtomar
#define rf freopen("in52.in", "r", stdin)
#define wf freopen("out.txt", "w", stdout)
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define f first
#define s second
#define mp make_pair
#define pb push_back
int pos[1<<21];
int main()
{
    rf;wf;
    int t,n;
    scanf("%d",&t);
for (int tt=1;tt<=t;tt++){
    fill(pos,pos+2500+10,0);
    cin>>n;
for(int i=1;i<=2*n-1;i++)
{
    for(int j=1;j<=n;j++)
    {
        int x;
        scanf("%d",&x);
        pos[x]++;
        pos[x]=pos[x]%2;
    }
}
printf("Case #%d: ",tt);
for(int i=1;i<=2500;i++)
if(pos[i])
    printf("%d ",i);
    printf("\n");
}
 return 0;
}
