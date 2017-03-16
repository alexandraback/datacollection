#include<stdio.h>
#include<stdlib.h>

int N,T;
int n,m;
long long a[105],at[105];
long long b[105],bt[105];
long long ans;
long long mem[101][101];
long long max(long long a,long long b) {return (a>b)?a:b;}
long long min(long long a,long long b) {return (a>b)?b:a;}


long long dfs(int x,int y)
{  // printf("%d %d\n",x,y);
    if(x>=n||y>=m) return 0;
    if(mem[x][y]!=0) return mem[x][y];
    if(at[x]!=bt[y]) 
    {
        mem[x][y]=max(dfs(x+1,y),dfs(x,y+1));   
    }
    else
    {   long long k=min(b[y],a[x]);
        b[y]-=k;
        a[x]-=k;        
        long long j=max(dfs(x+1,y),dfs(x,y+1));
        b[y]+=k;
        a[x]+=k;
        long long l=max(dfs(x+1,y),dfs(x,y+1));
        mem[x][y]= max(j+k,l);
    }        
            return mem[x][y];
}

long long go()
{   
    scanf("%d %d",&n,&m);  
    for(int i=0;i<n;i++)
    scanf("%I64d %I64d",&a[i],&at[i]);
    for(int i=0;i<m;i++)
    scanf("%I64d %I64d",&b[i],&bt[i]);    
    return dfs(0,0);        

}

int main(){
    freopen("output2.txt","w",stdout);
    scanf("%d",&N);
    for(int T=1;T<=N;T++)
    {
        printf("Case #%d: ",T);
        printf("%I64d\n",go());
        for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        mem[i][j]=0;
    }
//    system("pause");
    return 0;   
}
