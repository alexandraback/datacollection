#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<list>

using namespace std;

int N,T;
set<int> s;
int n;
int m[1001][1001];

bool dfs(int x)
{  // printf("%d-",x);
    for(int i=1;i<=m[x][0];i++)
    {
        if(s.find(m[x][i])!=s.end()) return 1;
        s.insert(m[x][i]);
        if(dfs(m[x][i])) return 1;
    }
    return 0;
}

bool go()
{   
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)
    {   
        scanf("%d",&m[i][0]);
        for(int j=0;j<m[i][0];j++)
        scanf("%d",&m[i][j+1]);
    }  
    
    for(int i=1;i<=n;i++)
    {
        s.clear();
        if(dfs(i)) return 1;        
    }            
    return 0;
}

int main(){
    freopen("output.txt","w",stdout);
    scanf("%d",&N);
    for(int T=1;T<=N;T++)
    {
        bool ans=go();        
        printf("Case #%d: ",T);
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
  //  system("pause");
    return 0;   
}
