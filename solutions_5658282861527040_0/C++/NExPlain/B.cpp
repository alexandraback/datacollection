#include <stdio.h>
int A,B,K;
int answer;

int main() {
    int T;
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(int t = 1 ;t <= T; ++t) {
        scanf("%d%d%d",&A,&B,&K);
        answer = 0;
        for(int i = 0 ; i < A ; ++i) {
            for(int j = 0 ; j < B ; ++j) {
                if((i&j)<K)++answer;
            }
        }
        printf("Case #%d: %d\n",t,answer);
    }
}
