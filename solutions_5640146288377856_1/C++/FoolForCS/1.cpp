#include<bits/stdc++.h>

#define gcd __gcd
#define bitcount __builtin_popcountll
#define getcx getchar
#define rep(i,j,n) for(i=j;i<n;i++)
#define tr(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define hell 1000000007
#define uset unordered_set
#define umap unordered_map

using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
const int MAXN = 1e6;
/*Binary Search*/
bool p(int x, int N)
{
    return true;
}
int bin_search(int low, int high, int N)
{
    int mid;
    while(low<high)
    {
        mid = low + (high-low)/2;
        if(p(mid,N))
            high=mid;
        else
            low=mid+1;
    }
    if(!p(low,N))
        return -1;
    return low;
}
int solve(int C, int D, int V)
{
}

int main()
{
   freopen("A-Large.in","r",stdin);
   freopen("out.txt","w",stdout);

   int T,i,R,C,W;
   cin>>T;
   for(int tt=1;tt<=T;tt++)
   {
       cout<<"Case #"<<tt<<": ";
       cin>>R>>C>>W;
       cout<<R*(C/W)+(C%W?1:0)+W-1<<endl;
   }
}
