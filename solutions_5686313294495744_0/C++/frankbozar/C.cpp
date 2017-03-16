#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int solve(const vector<pair<string, string>>& a)
{
    int n=a.size(), ans=0;
    
    for(int i=(1<<n)-1; i>=0; i--)
    {
        int cnt=0;
        bool suc=true;
        set<string> L, R;
        
        for(int j=0; j<n; j++)
        {
            if( (i>>j)%2==1 )
            {
                L.insert(a[j].first);
                R.insert(a[j].second);
            }
        }
        
        for(int j=0; j<n; j++)
        {
            if( (i>>j)%2==0 )
            {
                cnt++;
                
                if( L.find(a[j].first)==L.end() || R.find(a[j].second)==R.end() )
                    suc=false;
            }
        }
        
        if( suc )
            ans=max(ans, cnt);
    }
    
    return ans;
}
/*
struct disjoint_set
{
    vector<int> p;
    disjoint_set(const int n) : p(n, -1){}
    
    int find(int x)
    {
        return p[x]==-1 ? x  : p[x]=find(p[x]);
    }
    
    bool join(int x, int y)
    {
        x=find(x);
        y=find(y);
        
        if( x==y )
            return false;
        
        p[x]=y;
        return true;
    }
};
*/
int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        int n, ans=0;
        scanf("%d", &n);
        //disjoint_set S(n);
        vector<pair<string, string>> a;
        
        for(int i=0; i<n; i++)
        {
            char l[32]={0}, r[32]={0};
            scanf("%s%s", l, r);
            a.push_back(pair<string, string>(l ,r));
            /*
            for(int j=0; j<i; j++)
                if( a[i].first==a[j].first || a[i].second==a[j].second )
                    S.join(i, j);
            */
        }
        /*
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            set<string> L, R;
            
            for(int j=0; j<n; j++)
            {
                if( S.find(j)==i )
                {
                    cnt++;
                    L.insert(a[j].first);
                    R.insert(a[j].second);
                }
            }
            
            ans+=cnt-max(L.size(), R.size());
        }
        
        if( ans>solve(a) )
        {
            for(int i=0; i<n; i++)
                printf("\t%s %s\n", a[i].first.c_str(), a[i].second.c_str());
            
            printf("\t%d %d\n", ans, solve(a));
        }
        */
        printf("Case #%d: %d\n", cases, solve(a));
    }
}