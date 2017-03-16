#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int adj[1010][1010];
int route[1010][1010];
int N, M;
int que[1000010], h, t;

int main(){
    int T;
    int i, j;
    int a, b;
    int from;
    int count = 0, flag;
    scanf("%d", &T);
    while(T--){
        memset(adj, 0, sizeof(adj));
        memset(route, 0, sizeof(route));
        scanf("%d", &N);
        for(i = 1; i <= N; i++){
            scanf("%d", &M);
            for(j = 0; j < M; j++){
                scanf("%d", &a);
                adj[i][a] = 1;
            }
        }
/*        printf("adj list:\n");
        for(i = 1; i <= N; i++){
            for(j = 1; j <= N; j++){
                printf("%3d", adj[i][j]);
            }
            printf("\n");
        }*/
        for(i = 1; i <= N; i++){
            h = t = 0;
            que[t++] = i;
//            printf("source: %d\n", i);
            while(h != t){
                from = que[h++];
//                printf("from: %d\n", from);
                for(j = 1; j <= N; j++){
                    if(adj[from][j]){
//                        printf("to %d\t", j);
                        route[i][j]++;
                        que[t++] = j;
                    }
                }
//                printf("\n");
            }
        }
/*        for(i = 1; i <= N; i++){
            for(j = 1; j <= N; j++){
                printf("%3d", route[i][j]);
            }
            printf("\n");
        }*/
        flag = 0;
        for(i = 1; i <= N && !flag; i++){
            for(j = 1; j <= N && !flag; j++){
                if(route[i][j] > 1) flag = 1;
            }
        }
        printf("Case #%d: ", ++count);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
