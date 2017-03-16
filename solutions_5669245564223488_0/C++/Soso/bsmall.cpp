#include<cstdio>
#include<cstring>
int T,n,perm[15],ac,b[30],len[15];
char s[15][105];
void p(int x){
     if (x==n){
        int ok=1; char c;
        for (int i=1; i<30; i++) b[i]=1;
        for (int i=1; i<=n; i++){
            for (int j=0; j<len[perm[i]]; j++){
                if (i==1&&j==0) c=s[perm[i]][j],b[c-'a'+1]=0;
                else if (((j==0)&&(s[perm[i]][0]!=c))||((j>0)&&(s[perm[i]][j]!=s[perm[i]][j-1]))){
                     if (b[s[perm[i]][j]-'a'+1]==0) {ok=0; break;}
                }
                c=s[perm[i]][j]; b[c-'a'+1]=0;
            }
            if (!ok) break;
        }
        ac+=ok;
        return;          
     }
     int tmp;
     for (int i=x; i<=n; i++){
         tmp=perm[i];
         perm[i]=perm[x];
         perm[x]=tmp;
         p(x+1);
         tmp=perm[i];
         perm[i]=perm[x];
         perm[x]=tmp;
     }
}
int main(){
    scanf("%d",&T);
    for (int o=1; o<=T; o++){
        scanf("%d",&n);
        for (int i=1; i<=n; i++) scanf("%s",s[i]),len[i]=strlen(s[i]);
        for (int i=1; i<=n; i++) perm[i]=i;
        ac=0;
        p(1);
        printf("Case #%d: %d\n",o,ac);
    }
    return 0;    
}
