//#define __DEBUG_MOD__
//#define __ONLINE__  //定义了online后就自动注释掉了__DEVCPP_GETCHAR__


#include "Header.h"
//#incluide "CrackCode.h"
#include <queue>
using namespace std;



namespace NS_G2012R1C
{
    const int MAXN = 1010;
    int g[MAXN][MAXN];
    int indegree[MAXN];
    int visit[MAXN];


    
    bool BFS (int u,int N)
    {
        queue<int> Q;
	Q.push(u);
        int i,v;
	while (!Q.empty())
	{
            v =Q.front();
            Q.pop();
            if(visit[v]==true){
                DEBUG("v true:visit[%d]=1:u=%d\n",v,u);
                return true;
            }
            visit[v] = true;
            for (i=1; i<=N; ++i)
            {
                if (g[v][i]!=0){
                    if(visit[i]){ //说明i已经有其他的路径了，存在diamond path
                        DEBUG("true:visit[%d]=1:v=%d\n",i,v);
                        return true;
                    }else{
                        //visit[i]=true;
                        DEBUG("push:visit[%d]=%d:v=%d\n",i,visit[i],v);
                        Q.push(i);
                    }
                }
            }
	}
        return false;
    }

    bool Find(int N)
    {
        int i,j;
        for(i=1;i<=N;i++){
            if(indegree[i]==0){
                //森林中的不同树之间避免相互影响。
                memset(visit,0,sizeof(visit));
                DEBUG("indegree[%d]=0\n",i);
                if(!visit[i]){
                    if(BFS(i,N)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int main()
    {
        int  T,nCase=1;
        int i,j,t,M,N;
        double f[MAXN];
        SetFileInOutName("A-small-practice.in");//NS_google2008R1B");
        ReopenStdinStdout();

        scanf("%d",&T);
        while((T--)>0){
            printf("Case #%d: ",nCase++);
            scanf("%d",&N);
            DEBUG("N=%d\n",N);
            memset(g,0,sizeof(g));
            memset(indegree,0,sizeof(indegree));
            memset(visit,0,sizeof(visit));
            for(i=1;i<=N;i++){
                scanf("%d",&M);
                for(j=0;j<M;j++){
                    scanf("%d",&t);
                    g[i][t]= 1;
                    indegree[t]++;
                }
            }
            /*
            for(i=1;i<=N;i++){
                for(j=1;j<=N;j++){
                    printf("%d ",g[i][j]);
                }
                printf("\n");
                }*/
            bool ret = Find(N);
            if(ret){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }            
}
int main()
{
    //NS_G2008R1CC::main();
    //NS_G2008R1CC_Net::main();
    //NS_G2012R1A::main();
    //NS_CCI_SetOfStacks::main();
    NS_G2012R1C::main();
#ifdef __DEVCPP_GETCHAR__
    getchar();
#endif
}


    
