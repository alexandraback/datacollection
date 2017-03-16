#include<stdio.h>
#include<stdlib.h>
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, A, B, index = 0;
    int freq[1002] = {0}, num[6] = {1, 4, 9, 121, 484,1001};
    scanf("%d",&T);
    for(int j=1;j<1001;j++){
        freq[j] = freq[j-1];
        if(j == num[index]){
            freq[j]++;
            index++;
        }
    }
    for(int i=0;i<T;i++){
        scanf("%d%d",&A,&B);
        printf("Case #%d: %d\n", i+1, freq[B] - freq[A-1]);
    }
}
