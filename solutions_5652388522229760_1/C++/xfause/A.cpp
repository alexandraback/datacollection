#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e10

using namespace std;

bool flag[10];
int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=1,n;
    scanf("%d",&T);
    while (T--){
        char s[210];
        int flag1=0,ans=0;
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        sprintf(s,"%d",n);
        for (int i=1;i<=5000;i++){
            int tmp=n*i;
            sprintf(s,"%d",tmp);
            int len=strlen(s);
            for (int j=0;j<len;j++){
                flag[s[j]-'0']=1;
            }
            //for (int j=0;j<=9;j++) printf("%d ",flag[j]);
            //puts("");
            flag1=0;
            for (int j=0;j<=9;j++){
                if (flag[j]==0) continue;
                else {
                    flag1+=1;
                }
            }
            if (flag1==10) {ans=i;break;}
        }
        if (ans!=0)
            printf("Case #%d: %d\n",cas++,ans*n);
        else printf("Case #%d: INSOMNIA\n",cas++);
    }
    return 0;
}
