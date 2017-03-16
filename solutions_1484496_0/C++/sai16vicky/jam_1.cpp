#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<limits.h>
#include<numeric>
#include<stack>
#include<queue>
#include<ctype.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<math.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mkp(x,y) make_pair(x,y)

vector<int> v[2000010];

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
            int n;
            scanf("%d",&n);

            int a[n];

            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
            
        
            map< int,vector<int> > f1;
            map<int,int> f;
            vector<int> ans1,ans2;
            for(int i=0;i<2*(int)1e6;i++)v[i].clear();
            
            printf("Case #%d:\n",tt);
            int chk=1;
            for(int i=0;i<(int)(1<<n);i++)
            {
                    int sum=0;
                    vector<int> res;
                    for(int j=0;j<n;j++)
                        if(i & (1<<j))
                        {
                            sum+=a[j];
                    
                            res.pb(a[j]);
                        }
                    
                    if(f.find(sum)==f.end())
                    {
                            f[sum]+=1;
                            for(int k=0;k<(int)res.size();k++)            
                                v[sum].pb(res[k]);
                            
                    }
                    else
                    {
                        if((int)res.size() and (int)v[sum].size())
                        {
                            chk=0;
                    
                            for(int k=0;k<(int)res.size();k++)
                                    cout<<res[k]<<" ";
                            cout<<"\n";
                            for(int k=0;k<(int)v[sum].size();k++)
                                    cout<<v[sum][k]<<" ";
                            cout<<"\n";
                            break;
                        }
                    }        
            }
            if(chk)printf("Impossible\n");
            
    }
    return 0;
}
