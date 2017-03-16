/*
	jsrkrmciB
 */
    using namespace std;
#include <bits/stdc++.h> // precompiled headers
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define eps 1e-9
#define getnum(x) scanf("%d",&x);
#define dprintf(x...) fprintf(stderr,x);
#define lld I64d;
#define result(x,y)  printf("Case #%d: %I64d\n", x+1, (long long)y);
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif
#define sd(x)  scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sll(x) scanf("%I64d",&x)
#define sf(x) scanf("%Lf",&x)
#define ss(x) scanf("%s",x)
    typedef long double ld;
    typedef long long ll;
    typedef string str;

    int T;
    int main() {
	//ios::sync_with_stdio(false);//use with care
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out","w",stdout);
        getnum(T);
    // dprintf("%d %d\n",T,T);
        fora(t,T){
            char coder[20], jammer[20];
            char a[20], b[20];
            fora(i,20){
                coder[i]='0';
                jammer[i]='0';
            }
            int gmin=1e9;
            int cmin=1e9;
            int jmin=1e9;
            scanf("%s %s",a,b);
            int len = strlen(a);
            strcpy(coder+3-len,a);
            strcpy(jammer+3-len,b);
            fora(i,10){
                if(coder[0]!='?'&&coder[0]!=i+'0') continue;
                fora(j,10){
                    if(coder[1]!='?'&&coder[1]!=j+'0') continue;
                    fora(k,10){
                        if(coder[2]!='?'&&coder[2]!=k+'0') continue;
                        fora(ii,10){
                            if(jammer[0]!='?'&&jammer[0]!=ii+'0') continue;
                            fora(jj,10){
                                if(jammer[1]!='?'&&jammer[1]!=jj+'0') continue;
                                fora(kk,10){
                                    if(jammer[2]!='?'&&jammer[2]!=kk+'0') continue;
                                    if(abs(i*100+j*10+k-ii*100-jj*10-kk) < gmin){
                                        gmin=abs(i*100+j*10+k-ii*100-jj*10-kk);
                                        cmin=i*100+j*10+k;
                                        jmin=ii*100+jj*10+kk;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(len==1){
                printf("Case #%d: %01d %01d\n",t+1,cmin,jmin);
            }else if(len==2){
                printf("Case #%d: %02d %02d\n",t+1,cmin,jmin);
            }else{
                printf("Case #%d: %03d %03d\n",t+1,cmin,jmin);
            }
            
        }
        return 0;
    }