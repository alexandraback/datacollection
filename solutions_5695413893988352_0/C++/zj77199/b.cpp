#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vec1, vec2;
char a[10],b[10];
int ans,J,C;
void dfs(int cur,char*p,vector<int>&vec)
{
    if(!*p)
    {
        vec.push_back(cur);
        return;
    }
    if('0'<=*p&&*p<='9')
    {
        dfs(cur*10+*p-'0',p+1,vec);
        return;
    }
    for(int i=0;i<10;++i)
        dfs(cur*10+i,p+1,vec);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf(" %s %s",a,b);
        vec1.clear();
        vec2.clear();
        dfs(0,a,vec1);
        dfs(0,b,vec2);
        ans=0x7fffffff;
        C=J=0x7fffffff;
        int i,j,u,v,l1,l2;
        l1=vec1.size();
        l2=vec2.size();
        for(i=0;i<l2;++i)
            for(j=0;j<l1;++j)
            {
                if(abs(vec2[i]-vec1[j])<ans)
                {
                    ans=abs(vec2[i]-vec1[j]);
                    J=vec2[i];
                    C=vec1[j];
                }
                else if(abs(vec2[i]-vec1[j])==ans)
                {
                    if(J>vec2[i])
                    {
                        J=vec2[i];
                        C=vec1[j];
                    }
                }
            }
        printf("Case #%d: %0*d %0*d\n",t,strlen(a),C,strlen(b),J);
    }
    return 0;
}
