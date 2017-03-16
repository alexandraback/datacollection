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
/*Main Solution*/
int d[6];

int solve(int C, int D, int V)
{
    uset<int>rem;
    uset<int>keep;
    vector<int>v;
    int arr[V+1],i,k,j,cst;
    rep(i,1,V+1)
        arr[i]=0;
    rep(i,1,1<<D)
    {
        k = 1<<(D-1);
        j=D-1;
        cst=0;
        while(k!=0)
        {
            if(k&i)
                cst+=d[j];
            k>>=1;
            j--;
        }
        if(cst<=V)
            arr[cst]=1;
    }
    rep(i,1,V+1)
        if(!arr[i])
            rem.insert(i);
    if(rem.size()<=1)
        return rem.size();
    static bool present[6];
    rep(i,0,6)
        present[i]=false;
    rep(i,0,D)
        present[d[i]]=true;
    rep(i,1,6)
        if(!present[i])
            v.pb(i);
    tr(it,v)
        rep(i,0,D)
            if(rem.find(*it+d[i])!=rem.end())
            {
                rem.erase(*it+d[i]);
                keep.insert(*it);
                d[D]=*it;
                D++;
            }
    if(rem.size()!=0)
    rep(i,6,9)
        rep(j,0,D)
            if(rem.find(i+d[j])!=rem.end())
            {
                rem.erase(i+d[j]);
                keep.insert(i);
                d[D]=i;
                D++;
            }
    return keep.size();
}
int solve2(int C, int D, int V)
{
    int arr[V+1],i,k,j,cst;
    set<int>v;
    vector<int>keep;
    rep(i,1,V+1)
        arr[i]=0;
    rep(i,1,1<<D)
    {
        k = 1<<(D-1);
        j=D-1;
        cst=0;
        while(k!=0)
        {
            if(k&i)
                cst+=d[j];
            k>>=1;
            j--;
        }
        if(cst<=V)
            arr[cst]=1;
    }
    rep(i,1,V+1)
        if(!arr[i])
            v.insert(i);
    while(!v.empty())
    {
        int x = *v.begin();
        v.erase(v.begin());
        rep(i,1,V+1)
            if(x+i<=V&&arr[i]&&!arr[x+i])
            {
                arr[i+x]=1;
                if(v.find(i+x)!=v.end())
                    v.erase(i+x);
            }
        arr[x]=1;
        keep.pb(x);
    }
   // tr(it,keep)
  //      cout<<"Used "<<*it<<endl;
    return keep.size();
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);

   int T,i,R,C,W;
   cin>>T;
   for(int tt=1;tt<=T;tt++)
   {
       cout<<"Case #"<<tt<<": ";
       cin>>R>>C>>W;
       rep(i,0,C)
        cin>>d[i];
       cout<<solve2(R,C,W)<<endl;
   }
}
