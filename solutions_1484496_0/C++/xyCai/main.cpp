#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int zongshu;
int a[215],S;
map<int,vector<int> > ArguC;

int main()
{
//    freopen("C-small-attempt0.in","r",stdin);
//    freopen("C-small-attempt0.out","w",stdout);
    int t,ca=1;scanf("%d",&t);
    int kaoAgru;
    bool flag;
    while (t--)
    {
        flag = false;
        printf("Case #%d:\n",ca++);
        scanf("%d",&zongshu);
        for(int i=0; i<zongshu; ++i)
        {
            scanf("%d",&a[i]);
        }
        ArguC.clear();
        kaoAgru=1<<zongshu;
        for(int i=0; i<kaoAgru; ++i)
        {
            int sum=0;
            for(int j=0; j<zongshu; ++j)
                if(i&(1<<j)) sum+=a[j];
            ArguC[sum].push_back(i);
        }
        for(map<int,vector<int> >::iterator it=ArguC.begin(); it!=ArguC.end(); it++)
        {
            vector<int> now=it->second;
            if(now.size()==1)
                continue;
            for(int j=0; j<(int)now.size(); ++j)
            {
                for(int k=j+1; k<(int)now.size(); ++k)
                {
                    if((now[k]|now[j]) == (now[j]+now[k]))
                    {
                        vector<int> ans;
                        for(int u=0; u<zongshu; ++u)
                            if(now[j]&(1<<u))ans.push_back(u);
                        for(int u=0; u<(int)ans.size(); ++u)
                            printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                        ans.clear();

                        for(int u=0; u<zongshu; ++u)
                            if(now[k]&(1<<u))ans.push_back(u);
                        for(int u=0; u<(int)ans.size(); ++u)
                            printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                        flag = true;break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) printf("Impossible\n");
    }
    return 0;
}
