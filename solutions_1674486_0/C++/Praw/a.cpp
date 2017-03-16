#include <stdio.h>

int e[1000][10];
int m[1000];
bool v[1000];
bool f(int i)
{
    if(v[i])return true;
    v[i]=true;
    for(int j=0;j<m[i];j++)
        if(f(e[i][j]))return true;
    return false;
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out","w",stdout);
    int a;
    scanf("%d",&a);
    for(int b=0;b<a;b++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
            for(int j=0;j<m[i];j++){
                scanf("%d",&e[i][j]);
                e[i][j]--;
            }
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[j]=false;
            }
            if(f(i))
                ans=true;
        }
        printf("Case #%d: ",b+1);
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
}
