#include<stdio.h>
#include<string.h>
#include<memory.h>
FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/2/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/2/output.txt","w");
char first[20],second[20];
int len;
long long int ans[2],min;
void find(int now,long long int f,long long int s){
    if(now == len){
        long long int dif;
        if(f < s) dif = s - f;
        else dif = f - s;
        if(dif < min ||
                (dif == min && ans[0] > f) ||
                (dif == min && ans[0] == f && ans[1] > s)){
            min = dif;
            ans[0] = f;
            ans[1] = s;
        }
    }else{
        long long int nf = f * 10,ns = s * 10;
        if(f == s){
            if(first[now] == '?' && second[now] == '?'){
                find(now+1,nf,ns);
                find(now+1,nf,ns+1);
                find(now+1,nf+1,ns);
            }else if(first[now] == '?' && second[now] != '?'){
                int gap = second[now] - '0';
                find(now+1,nf+gap,ns+gap);
                if(gap < 9){
                    find(now+1,nf+gap+1,ns+gap);
                }
                if(gap > 0){
                    find(now+1,nf+gap-1,ns+gap);
                }
            }else if(first[now] != '?' && second[now] == '?'){
                int gap = first[now] - '0';
                find(now+1,nf+gap,ns+gap);
                if(gap < 9){
                    find(now+1,nf+gap,ns+gap+1);
                }
                if(gap > 0){
                    find(now+1,nf+gap,ns+gap-1);
                }
            }else{
                find(now+1,nf+(first[now]-'0'),ns+(second[now]-'0'));
            }
        }else{
            if(f < s){
                if(first[now] == '?'){
                    nf += 9;
                }else{
                    nf += first[now] - '0';
                }
                if(second[now] == '?'){
                    ns += 0;
                }else{
                    ns += second[now] - '0';
                }
            }else{
                if(first[now] == '?'){
                    nf += 0;
                }else{
                    nf += first[now] - '0';
                }
                if(second[now] == '?'){
                    ns += 9;
                }else{
                    ns += second[now] - '0';
                }
            }
            find(now+1,nf,ns);
        }
    }
}
int main(){
    int t,T;
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(first,0,sizeof(first));
        memset(second,0,sizeof(second));
        memset(ans,0,sizeof(ans));
        min = 0x7fffffffffffffff;
        fscanf(fo,"%s %s",first,second);
        len = strlen(first);
        find(0,0,0);
        fprintf(fp,"Case #%d: ",t);
        long long int z = 1,zero;
        for(int i=1;i<len;i++){
            z *= 10;
        }
        zero = z;
        while(ans[0]/zero == 0){
            if(zero == 1 && ans[0] == 0)break;
            fprintf(fp,"0");
            zero /= 10;
        }
        fprintf(fp,"%lld ",ans[0]);
        zero = z;
        while(ans[1]/zero == 0){
            if(zero == 1 && ans[1] == 0)break;
            fprintf(fp,"0");
            zero /= 10;
        }
        fprintf(fp,"%lld\n",ans[1]);
    }
    return 0;
}