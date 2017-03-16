#include<stdio.h>
#include<string.h>
#define ts printf("test\n")
#define ll long long
char s[222];
int k[33];
ll m[33][33];
ll p[33];
ll in[33];
ll out[33];
ll ans=1;
int n;
int oux;
void ex(){
    printf("Case #%d: 0\n",oux);
}
ll fg(ll v){
    if(!v)return 1;
    return (fg(v-1)*v)%1000000007;
}
void proc(int xx){
    oux=xx;
    scanf("%d",&n);
    int i,j;
    int l;
    int cd;
    for(i=0;i<n;i++){
        scanf("%s",s);
        l=strlen(s);
        cd=0;
        for(j=1;j<l-1;j++){
            if(s[j]==s[j-1])continue;
            if(s[j]!=s[0]&&s[j]!=s[l-1]){
                if(k[s[j]-'a'])return ex();
                k[s[j]-'a']=1;
                cd++;
            }
            if(s[j]==s[0])return ex();
            if(s[j]==s[l-1]&&s[j]!=s[j+1])return ex();
        }
        if(!cd&&s[0]==s[l-1]){
            p[s[0]-'a']++;
        }
        else if(s[0]==s[l-1]&&cd){
            return ex();
        }
        else{
            m[s[0]-'a'][s[l-1]-'a']++;
            in[s[l-1]-'a']++;
            out[s[0]-'a']++;
        }
    }
    ll ct=0;
    for(i=0;i<=26;i++){
        if(out[i]>1)return ex();
        if(in[i]>1)return ex();
        if((out[i]||in[i])&&k[i])return ex();
        if(out[i]&&!in[i])ct++;
        if(!in[i]&&p[i])ct++;
    }
    for(i=0;i<=26;i++){
        if(p[i]){
            ans*=fg(p[i])%1000000007;
        }
    }
    ans*=fg(ct)%1000000007;
    printf("Case #%d: %I64d\n",xx,ans);
}
int main(){
    int xxx;
    scanf("%d",&xxx);
    int i;
    for(i=0;i<xxx;i++)proc(i+1);
}
