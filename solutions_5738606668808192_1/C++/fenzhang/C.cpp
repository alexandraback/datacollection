#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);++i)
#define FB(i,n) for(int i=(n)-1;i>=0;--i)
#define FV(i,st,ed) for(int i=(st);i<(ed);++i)
#define FZU(i,n) for(ust i=0;i<(n);++i)
#define FVU(i,st,ed) for(ust i=(st);i<(ed);++i)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
#define N 100514
typedef long long int lnt;
typedef unsigned long long int unt;
typedef unsigned ust;
typedef double dou;
typedef pair<int,int> P;
ust ansp[514][16],ans[514],at = 0;
int main(){
    freopen("CLout.txt","w",stdout);
    ust lb = (1u<<15)+1, ub = (1u<<16)-1;
    FVU(i,lb,ub)if(i&1){
        ust res[16]; bool flag = 1;
        FVU(b,2u,11u){
            auto s = 0llu;
            for(auto t=i;t;t>>=1){
               s*=b;
               s+=t&1;
            }
            if(s&1){
                res[b]=-1u;
                for(unt x=3u;x*x<=s;x+=2)if(s%x==0){
                    res[b]=x;
                    break;
                }
                if(res[b]==-1u){
                    flag = 0;
                    break;
                }
            }else{
                res[b]= 2u;
            }
        }
        if(flag){
            memcpy(ansp[at],res,sizeof(res));
            ans[at++] = i;
            if(at==500)break;
        }
    }
    //printf("%u\n",at); fflush(stdout);
    /*
    int n,J; RI(n); RI(n); RI(J);
    */
    puts("Case #1:");
    FZ(k,500){
        FZU(i,16)printf("%u",(ans[k]>>i)&1u);
        FZU(i,16)printf("%u",(ans[k]>>i)&1u);
        FVU(i,2u,11u){
            printf(" %u",ansp[k][i]);
        }puts("");
    }
	return 0;
}

