#include<stdio.h>
#include<string.h>

char coder[20]={0}, jammer[20]={0};
long long ans_coder,ans_jammer;
char ans_pcoder[20]={0}, ans_pjammer[20]={0};
long long ans=-1;
int len;
void f(int idx, int mod){
    if(idx == len){
        long long t1=0, t2=0, t3=0;
        int i;
        for(i=0;i<len;i++){
            t1 *= 10;
            t1 += coder[i]-'0';
            t2 *= 10;
            t2 += jammer[i]-'0';
        }
        t3 = t1 - t2;
        if(t3<0) t3 = -t3;
        if(ans == -1 || ans>t3){
            ans = t3;
            ans_coder = t1;
            ans_jammer = t2;
            for(i=0;i<len;i++){
                ans_pcoder[i] = coder[i];
                ans_pjammer[i] = jammer[i];
            }
        }
        else if(ans == t3){
            if(ans_coder>t2 || (ans_coder==t2 && ans_jammer>t3)){
                ans_coder = t1;
                ans_jammer = t2;
                for(i=0;i<len;i++){
                    ans_pcoder[i] = coder[i];
                    ans_pjammer[i] = jammer[i];
                }
            }
        }
        return;
    }
    if(coder[idx]=='?' && jammer[idx] == '?'){
        if(mod == 0){
            coder[idx] = '0';
            jammer[idx] = '0';
            f(idx+1,mod);
            coder[idx] = '1';
            jammer[idx] = '0';
            f(idx+1,1);
            coder[idx] = '0';
            jammer[idx] = '1';
            f(idx+1,2);
        }
        else if(mod == 1){
            coder[idx] = '0';
            jammer[idx] = '9';
            f(idx+1,mod);
        }
        else{
            coder[idx] = '9';
            jammer[idx] = '0';
            f(idx+1,mod);
        }
        coder[idx] = '?';
        jammer[idx] = '?';
    }
    else if(coder[idx]=='?'){
        if(mod == 0){
            coder[idx]=jammer[idx];
            f(idx+1,mod);
            if(jammer[idx]!='9'){
                coder[idx]=jammer[idx]+1;
                f(idx+1,1);
            }
            if(jammer[idx]!='0'){
                coder[idx]=jammer[idx]-1;
                f(idx+1,2);
            }
            coder[idx]='?';
        }
        else if(mod == 1){
            coder[idx] = '0';
            f(idx+1,mod);
            coder[idx] = '?';
        }
        else{
            coder[idx] = '9';
            f(idx+1,mod);
            coder[idx] = '?';
        }
    }
    else if(jammer[idx]=='?'){
        if(mod == 0){
            jammer[idx]=coder[idx];
            f(idx+1,mod);
            if(coder[idx]!='9'){
                jammer[idx]=coder[idx]+1;
                f(idx+1,2);
            }
            if(jammer[idx]!='0'){
                jammer[idx]=coder[idx]-1;
                f(idx+1,1);
            }
            jammer[idx]='?';
        }
        else if(mod == 1){
            jammer[idx] = '9';
            f(idx+1,mod);
            jammer[idx] = '?';
        }
        else{
            jammer[idx] = '0';
            f(idx+1,mod);
            jammer[idx] = '?';
        }
    }
    else{
        if(mod == 0){
            if(jammer[idx] < coder[idx]){
                f(idx+1,1);
            }
            else if(coder[idx] < jammer[idx]){
                f(idx+1,2);
            }
            else f(idx+1,0);
        }
        else f(idx+1,mod);
    }
}
int main()
{
    int t,test,i;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%s%s",coder,jammer);
        len = strlen(coder);
        for(i=0;i<20;i++){
            ans_pcoder[i] = 0;
            ans_pjammer[i] = 0;
        }
        ans = -1;
        //printf("%s %s\n",coder,jammer);
        f(0,0);
        printf("Case #%d: %s %s\n",t,ans_pcoder,ans_pjammer);
    }
    return 0;
}
