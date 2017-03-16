#include<stdio.h>
#include<string.h>
#include<map>

char first[16][25]={{0}}, second[16][25]={{0}};
int fcnt, scnt, n;
int ans=0;
int num[16][2]={0};
bool fake[16]={0};
void f(int idx,int cnt){
    if(idx == n){
        int i,j,k;
        bool check=false;
        for(i=0;i<n;i++){
            if(fake[i]){
                bool check2 = false;
                for(j=0;j<n;j++){
                    if(i==j || fake[j]) continue;
                    for(k=j+1;k<n;k++){
                        if(i==k || fake[k]) continue;
                        if(num[i][0] == num[j][0] && num[i][1] == num[k][1]){
                            check2 = true;
                            break;
                        }
                        if(num[i][0] == num[k][0] && num[i][1] == num[j][1]){
                            check2 = true;
                            break;
                        }
                    }
                    if(check2) break;
                }
                if(!check2){
                    check = true;
                    break;
                }
            }
            for(j=i+1;j<n;j++){
                if(num[i][0] == num[j][0] && num[i][1] == num[j][1]){
                    check = true;
                    break;
                }
                if(fake[j]) continue;
                for(k=j+1;k<n;k++){
                    if(fake[k]) continue;
                    if(num[i][0] == num[j][0] && num[i][1] == num[k][1]){
                        check = true;
                        break;
                    }
                    if(num[i][0] == num[k][0] && num[i][1] == num[j][1]){
                        check = true;
                        break;
                    }
                    if(num[j][0] == num[i][0] && num[j][1] == num[k][1]){
                        check = true;
                        break;
                    }
                    if(num[j][0] == num[k][0] && num[j][1] == num[i][1]){
                        check = true;
                        break;
                    }
                    if(num[k][0] == num[i][0] && num[k][1] == num[j][1]){
                        check = true;
                        break;
                    }
                    if(num[k][0] == num[j][0] && num[k][1] == num[i][1]){
                        check = true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
        }
        if(!check){
            if(cnt > ans) ans = cnt;
        }
        return;
    }
    fake[idx] = 0;
    f(idx+1,cnt);
    fake[idx] = 1;
    f(idx+1,cnt+1);
}
int main()
{
    int t,test;
    int i,j;
    char temp[2][25]={{0}};
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%d",&n);
        fcnt=scnt=0;
        ans = 0;
        for(i=0;i<16;i++){
            for(j=0;j<25;j++){
                first[i][j] = second[i][j] = 0;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<25;j++) temp[0][j] = temp[1][j] = 0;
            scanf("%s %s",temp[0],temp[1]);
            for(j=0;j<fcnt;j++){
                if(!strcmp(first[j],temp[0])){
                    num[i][0] = j;
                    break;
                }
            }
            if(j==fcnt){
                for(j=0;j<strlen(temp[0]);j++){
                    first[fcnt][j] = temp[0][j];
                }
                num[i][0] = fcnt;
                fcnt++;
            }
            for(j=0;j<scnt;j++){
                if(!strcmp(second[j],temp[1])){
                    num[i][1] = j;
                    break;
                }
            }
            if(j==scnt){
                for(j=0;j<strlen(temp[1]);j++){
                    second[scnt][j] = temp[1][j];
                }
                num[i][1] = scnt;
                scnt++;
            }
        }
        f(0,0);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
