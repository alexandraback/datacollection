#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define EPS (1e-10)

int judge[250];
int main(){
    int ntest,jud,tot;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        scanf("%d",&jud);
        tot=0;
        for (int i=0;i<jud;++i){
            scanf("%d",&judge[i]);
            tot+=judge[i];
        }
        double left=0.0, right=(double)tot,mid,cnt,temp;
        for (int acc=0;acc<100;++acc){
            mid=(left+right)/2.0;
            cnt=0.0;
            for (int i=0;i<jud;++i){
                temp=(mid-(double)judge[i])/(double)tot;
                if (temp+EPS>1e-9)
                cnt+=temp;
            }
            if (cnt<1.0+EPS){
               left=mid;
            }
            else{
                 right=mid;
            }
        }
        printf("Case #%d:",test);
        for (int i=0;i<jud;++i){
            temp=(EPS+mid-(double)judge[i])/(double)tot;
            printf(" %lf",temp+EPS>0.0?100*(temp+EPS):0.0);
        }
        printf("\n");
    }
    return 0;
}
