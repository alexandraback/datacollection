#include<cstdio>
#include<cstring>
using namespace std;
char s[5000],dict[522196][15];
int T,ac,l[522196],len,dp[5000][10],k,cnt,ok,p,kk,tk;
int mn(int a,int b){
    return (a<b?a:b);    
}
int main(){
    //copy the dictionary to input file
    for (int i=0; i<521196; i++){
        scanf("%s",dict[i]);
        l[i]=strlen(dict[i]);
    }
    scanf("%d",&T);
    for (int o=1; o<=T; o++){
        scanf("%s",s);
        len=strlen(s);
        for (int i=0; i<len; i++)
            for (int j=0; j<=5; j++)
                dp[i][j]=len+1;
        ac=len+1;
        for (int i=0; i<len; i++){
            for (int j=0; j<521196; j++){
                if (l[j]>i+1) continue;
                k=i-l[j]; cnt=0; ok=1; kk=0; p=-10;
                if (k==-1){
                   for (int x=0; x<l[j]; x++){
                       if (dict[j][x]!=s[x]&&(x-p<5)) ok=0;
                       else if (dict[j][x]!=s[x]) p=x,tk=l[j]-1-x,++cnt;
                   }
                }
                else{
                     for (int x=0; x<l[j]; x++){
                         if (dict[j][x]!=s[x+k+1]&&(x-p<5)) ok=0;
                         else if (dict[j][x]!=s[x+k+1]){
                              ++cnt;
                              if (kk==0){kk=4-x; if (kk<0) kk=0;}
                              p=x,tk=l[j]-1-x;
                              if (tk>4) tk=4;
                         }
                     }
                }
                if (ok){
                   for (int y=kk; y<=4; y++){
                       dp[i][tk]=mn(dp[i][tk],dp[k][y]+cnt);
                   }
                }
            }
        }
        for (int i=0; i<=4; i++)
            ac=mn(ac,dp[len-1][i]);
        printf("Case #%d: %d\n",o,ac);
    }
    return 0;    
}
