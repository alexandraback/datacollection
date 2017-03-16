#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1000010];

long long int LL[1000010];
long long int RR[1000010];

int main(){
    int T,p;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%s %d",str,&p);
        int L = strlen(str);
        long long int ans = 0;

        int from = -1, to;
        int cnt = 0;
        int now = 0;
        for(int i=0;i<L;i++){
            LL[i] = RR[i] = -1;
        }

        for(int i=0;i<L;i++){
            if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'){
                if(cnt == 0){
                    from = i;
                }
                cnt++;
                if(cnt > p){
                    cnt--;
                    from++;
                }
            }else{
                cnt = 0;
            }            
            if(cnt >= p){
                while(now<=from){
                    LL[now] = i;
                    now++;
                }
            }
        }
        if(cnt >= p){
            while(now<=from){
                LL[now] = L-1;
                now++;
            }
        }
        for(int i=0;i<L;i++){
            if(LL[i]!=-1){
                ans += (long long int)L - LL[i];
            }
//            fprintf(stderr,"=>%d: %lld %lld\n",i,LL[i],ans);
        }

        printf("Case #%d: %lld\n",f,ans);
    }
    return 0;
}
