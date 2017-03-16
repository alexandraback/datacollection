#include<cstdio>
#include<cmath>
#include<cstring>
#include<time.h>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

struct Node{
    int a, b, num;
}p[1000];
inline bool cmp( Node s, Node t ){
    return s.b<t.b || ( s.b==t.b && s.a>t.a );
}

int main(){
    int T, n;
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&p[i].a,&p[i].b);
            p[i].num = 2;
        }
        sort( p, p+n, cmp );
        int star = 0, time = 0;
        for(int i=0,j; i<n; i++){
            if( p[i].b<=star ){
                star += p[i].num;
                time++;
            }else{
                for(j=n-1; j>=i; j--){
                    if( p[j].num==2 && p[j].a<=star ){
                        p[j].num = 1;
                        star += 1;
                        time++;
                        break;
                    }
                }
                if( j==i-1 ){ time = -1; break; }
                i--;
            }
        }
        printf("Case #%d: ",cs);
        if( time==-1 ) printf("Too Bad\n");
        else printf("%d\n",time);
    }
    return 0;
}

/*int main(){
    int T, A, B; double p[100000];
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++){
        scanf("%d%d",&A,&B);
        for(int i=0; i<A; i++) scanf("%lf",&p[i]);
        double exp = B+2, pp = 1;
        for(int i=0; i<A; i++){
            double s = (A-i+B-i+1)*pp+(A-i+B-i+1+B+1)*(1-pp);
            //printf("%.6f\n",s);
            exp = min( exp, s );
            pp *= p[i];
        }
        //printf("%.6f\n",(B-A+1)*pp+(B-A+1+B+1)*(1-pp));
        exp = min( exp, (B-A+1)*pp+(B-A+1+B+1)*(1-pp) );
        printf("Case #%d: %.6f\n",cs,exp);
    }
    return 0;
}*/
