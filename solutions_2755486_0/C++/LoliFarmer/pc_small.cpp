#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long int wall[500];
struct S{
    long long int d;
    long long int lef;
    long long int L,R;
    long long int str;
    long long int d_d;
    long long int d_p;
    long long int d_s;
}s[20];
bool cmp(S a,S b){
    return a.d > b.d;
}

long long int att[500];


int main(){
    int T,n;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        memset(wall,0,sizeof(wall));
        memset(att,0,sizeof(att));
        long long int ans = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&s[i].d,&s[i].lef,&s[i].L,&s[i].R,&s[i].str,&s[i].d_d,&s[i].d_p,&s[i].d_s);
            s[i].L += 250;
            s[i].R += 250;
        }
        long long int now_day = -1;
        make_heap(s,s+n,cmp);
        S tmp;
        while( n>0 ){
            if( now_day != s[0].d ){
                for(int i=0;i<500;i++){
                    if(wall[i] < att[i]){
                        wall[i] = att[i];
                    }
                }
                now_day = s[0].d;
                memset(att,0,sizeof(att));
            }
            tmp = s[0];
            pop_heap(s,s+n,cmp);
            n--;
            int chk = 0;
            for(long long int i=tmp.L;i<tmp.R;i++){
                if(wall[i] < tmp.str){
                    chk = 1;
                }
                if(att[i] < tmp.str){
                    att[i] = tmp.str;
                }
            }
//            for(int i=0;i<15;i++){
//                fprintf(stderr,"%lld ",wall[i+250]);
//            }
//            fprintf(stderr,"\n");
//            fprintf(stderr,"Day %d (%lld,%lld) %lld %d\n",tmp.d,tmp.L-250,tmp.R-250,tmp.str,chk);
            if(chk==1) ans++;
            
            tmp.d += tmp.d_d;
            tmp.lef--;
            tmp.L += tmp.d_p;
            tmp.R += tmp.d_p;
            tmp.str += tmp.d_s;
            if(tmp.lef > 0 && tmp.str>0){
                s[n++] = tmp;
                push_heap(s,s+n,cmp);
            }
        }
        printf("Case #%d: %lld\n",f,ans);
    }
    return 0;
}
