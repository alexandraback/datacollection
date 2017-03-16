#include<stdio.h>
#include<string.h>

#define MOD 1000000007

int T,n;
char t[100][101];
long long f[101],ans;
int g[30][30];
int chk[30];
int deg[30];
int wrong,have,cnt;
int a,b,c,d;

int main() {
    int i,j,k;
    // factorial
    f[0]=1;
    for(i=1;i<=100;i++)f[i]=(f[i-1]*((long long)i))%MOD;
    // GO
    scanf("%d",&T);
    for(int TC=1;TC<=T;TC++){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%s",t[i]);
        wrong=0;
        ans=1;
        memset(g,0,sizeof(g));
        // check inside
        for(i=0;i<n;i++){
            if(strlen(t[i])==1)continue;
            memset(chk,0,sizeof(chk));
            for(j=1;t[i][j];j++){
                if(chk[t[i][j]-'a'])wrong=1;
                if(t[i][j-1]==t[i][j])continue;
                chk[t[i][j-1]-'a']=1;
                g[t[i][j-1]-'a'][t[i][j]-'a']=1;
            }
        }
        if(wrong){
            printf("Case #%d: 0\n",TC);continue;
        }
        // check abc
        for(k=0;k<26;k++){
            a=b=c=d=0;
            for(i=0;i<n;i++){
                // a
                if(t[i][0]-'a'!=k && t[i][strlen(t[i])-1]-'a'==k)
                    a++;
                // b
                for(j=0;t[i][j];j++)if(t[i][j]-'a'!=k)break;
                if(!t[i][j])b++;
                // c
                if(t[i][0]-'a'==k && t[i][strlen(t[i])-1]-'a'!=k)
                    c++;
                // d
                if(t[i][0]-'a'!=k && t[i][strlen(t[i])-1]-'a'!=k){
                    for(j=0;t[i][j];j++)if(t[i][j]-'a'==k){
                        d++;
                        break;
                    }
                }
            }
            if(d && (a || b || c))wrong=1;
            if(a>1 || c>1 || d>1)wrong=1;
            ans=(ans*f[b])%MOD;
        }
        if(wrong){
            printf("Case #%d: 0\n",TC);continue;
        }
        // check cycle
        for(k=0;k<26;k++)
            for(i=0;i<26;i++)if(i!=k)
                for(j=0;j<26;j++)if(j!=k && j!=i)
                    if(g[i][k]&&g[k][j])g[i][j]=1;
        for(i=0;i<26;i++)for(j=0;j<26;j++)
            if(g[i][j]&&g[j][i])wrong=1;
        if(wrong){
            printf("Case #%d: 0\n",TC);continue;
        }
        // OK
        memset(chk,0,sizeof(chk));
        cnt=0;
        for(i=0;i<n;i++)for(j=0;t[i][j];j++)chk[t[i][j]-'a']=1;
        memset(deg,0,sizeof(deg));
        for(i=0;i<26;i++)for(j=0;j<26;j++)if(g[i][j])deg[j]++;
        for(i=0;i<26;i++){
            for(k=0;k<26;k++)if(chk[k]&&!deg[k])break;
            if(k==26)break;
            chk[k]=0;
            for(j=0;j<26;j++)if(g[k][j]){
                deg[j]--;
                chk[j]=0;
            }
            cnt++;
        }

        ans=(ans*f[cnt])%MOD;
        printf("Case #%d: %I64d\n",TC,ans);
    }
    return 0;
}
