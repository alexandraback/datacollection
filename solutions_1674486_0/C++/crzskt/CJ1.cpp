
# include <iostream>
# include <map>
# include <queue>

# define p push_back

using namespace std;

int main()
{
    int t,cnt=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n,m,a;
        map <int,bool> mp;
        scanf("%d",&n);
        vector <vector <int> > al(n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                mp[a-1] = 1;
                al[i].p(a-1);
            }
        }
        bool yes = false;
        for(i=0;i<n;i++)
        {
            if(mp[i]) continue;
            queue <int> q;
            int visi[1001] = {0};
            visi[i] = 1;
            q.push(i);
            while(!q.empty() && !yes)
            {
                int tp = q.front();
                q.pop();
                int sz = al[tp].size();
                for(j=0;j<sz;j++)
                {
                    if(visi[al[tp][j]])
                    {
                        yes = true;
                        break;    
                    }
                    else
                    {
                        visi[al[tp][j]] = 1;
                        q.push(al[tp][j]);   
                    }
                }    
            }    
        }
        if(yes)
            printf("Case #%d: Yes\n",cnt++);
        else
            printf("Case #%d: No\n",cnt++);
    }    
}
