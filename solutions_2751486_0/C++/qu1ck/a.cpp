#include <cstdio>
#include <cstring>

char s[1000010];
int  v[1000010];
int n,l;
int c[256];

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    c['a']=c['e']=c['i']=c['o']=c['u']=1;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        scanf("%s %d",s,&n);
        l=strlen(s);
        for(int i=0;i<l;i++){
            if(!c[s[i]]){
                v[i]=(i?v[i-1]:0)+1;
            }else v[i]=0;
        }
        long long ans=0;
        int last=-1;
        for(int i=0;i<l;i++){
            if(v[i]>=n)last=i;
            if(last!=-1){
                ans+=last-n+2;
            }
        }
        printf("Case #%d: %lld\n",C,ans);
    }
    return 0;
}