#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, inp[1010][2], str, lvl[1010], ans;
int main(){
    int cas;
    scanf("%d",&cas);
    for(int iii=0;iii<cas;iii++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&inp[i][0],&inp[i][1]);
        }
        str = 0;
        memset(lvl, 0, sizeof(lvl));
        ans=0;
        while(str<2*n){
            int one=-1, oneS = -1, two=-1;
            for(int j=0;j<n;j++){
                if(lvl[j]==0){
                    if(inp[j][1]<=str){
                        two = j;
                        break;
                    }
                    if(inp[j][0]<=str && oneS < inp[j][1]){
                        one = j;
                        oneS = inp[j][1];
                    }   
                }else if(lvl[j]==1){
                    if(inp[j][1]<=str){
                        one = j;
                        oneS = 10000000;
                    }
                }
            }
            if(two!=-1){
                str+=2;
                lvl[two]+=2;   
                ans++;
            }else if(one!=-1){
                str++;
                lvl[one]+=1;
                ans++;
            }else break;
        }
        if(str==2*n)printf("Case #%d: %d\n", iii+1, ans);
        else printf("Case #%d: Too Bad\n", iii+1);
    }
    scanf(" ");
    return 0;
}
