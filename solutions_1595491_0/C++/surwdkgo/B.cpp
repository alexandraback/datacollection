#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cas, n, sup, lin, inp, ans;
int main(){
    scanf("%d",&cas);
    for(int iii=0;iii<cas;iii++){
        scanf("%d%d%d",&n,&sup,&lin);
        ans = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&inp);
            int ma1 = (inp+2)/3, ma2 = (inp-2)/3 + 2;
            if(ma1 >= lin) ans++;
            else if(ma2 >= lin && sup > 0 && inp>=2){
                sup--;
                ans++;
            }
        }
        printf("Case #%d: %d\n", iii+1, ans);
    }
    scanf(" ");
    return 0;
}
