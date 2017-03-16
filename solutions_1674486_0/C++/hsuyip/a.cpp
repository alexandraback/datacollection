#include<iostream>
#include<cstdio>
#include<cstring>
int n,a[1010][1010],v[1010];
bool ans;
int dfs(int k)
{
    int i;
    v[k]=1;
    for(i=0;i<n;i++)
    {
                    if(a[k][i]==1 && v[i]==1)
                    {ans=true;return 0;}
                    if(v[i]==0 && a[k][i]==1)
                    dfs(i);
                    }
return 0;
}
int main()
{
    int t,T,i,j,k,x,y,z;
    
    freopen("C:/inputa.in","r",stdin);
    freopen("C:/outputa.txt","w",stdout);
    
    scanf("%d",&T);
    t=0;
    while(t++<T)
    {
                scanf("%d",&n);
                memset(a,0,sizeof(a));
                ans=false;
                for(i=0;i<n;i++)
                {
                                scanf("%d",&k);
                                for(j=0;j<k;j++){scanf("%d",&x);a[i][x-1]=1;}
                }
                for(i=0;i<n && !ans;i++)
                {
                            memset(v,0,sizeof(v));
                            dfs(i);
                                }
                if(ans)
                printf("Case #%d: Yes\n",t);
                else
                printf("Case #%d: No\n",t);
                }
    fclose(stdin);
    fclose(stdout);
    
    system("pause");
    return 0;
}
