#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int code[100];
int mp[100][100];
bool inG[100];

int main()
{
    int T;
    scanf("%d",&T);
    for(int _ = 1; _<=T; _++)
    {
        printf("Case #%d: ",_);

        memset(inG,0,sizeof(inG));
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i = 0; i < N;i++)
            scanf("%d",&code[i]);
        for(int i = 0; i < M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            mp[a][b] = 1;
            mp[b][a] = 1;
        }
        int gSize = 0;
        for(int xi = 0; xi<N;xi++){
            int minC = 1000000;
            int minId = -1;
            for(int i = 0 ; i<N;i++)
            if(inG[i] == false){
                bool exist = false;
                for(int j = 0; j <N;j++)
                if(inG[j] && mp[i][j]){
                    exist = true;
                    break;
                }
                if(gSize == 0 || exist){
                    if(minC > code[i]){
                        minC = code[i];
                        minId = i;
                    }
                }
            }
            printf("%d",code[minId]);
            inG[minId] = true;
            gSize++;
        }
        puts("");
    }
}
