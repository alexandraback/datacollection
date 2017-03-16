#define FROM_FILE
#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
void* __VERY__LONG__FROM=freopen("in.txt","r",stdin);
#endif

#ifdef TO_FILE
void* __VERY__LONG__TO=freopen("out.txt","w",stdout);
#endif

const int MAXN=10000*10000 + 10;
//const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;

int bst[MAXN];

int aks(int x)
{
    int y=0;
    while(x)
    {
        y*=10;
        y+=x%10;
        x/=10;
    }
    return y;
}

int main()
{
	ios::sync_with_stdio(false);
	memset(bst,-1,sizeof bst);
    vector<int> v;
    v.PB(1);
    bst[1]=1;
    for(int i=0;i<v.size();i++)
    {
        int x=v[i];
        int y1=x+1;
        if(y1<MAXN && bst[y1]==-1)
        {
            bst[y1]=bst[x]+1;
            v.PB(y1);
        }
        y1=aks(x);
        if(y1<MAXN && bst[y1]==-1)
        {
            bst[y1]=bst[x]+1;
            v.PB(y1);
        }
    }
	int tt;
	cin>>tt;
	for(int _z=1;_z<=tt;_z++)
	{
        int n;
        cin>>n;
        printf("Case #%d: %d\n",_z,bst[n]);
	}
    return 0;
}
