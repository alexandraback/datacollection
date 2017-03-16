#include<cstdio>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        printf("Case #%d: ", i+1);
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        for(int j=0;j<K;j++){
            printf("%d ", j+1);
        }
        printf("\n");
    }
}
