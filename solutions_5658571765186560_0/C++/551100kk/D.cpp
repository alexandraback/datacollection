#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
    freopen("D-small-attempt3.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,i,j,x,y,C=0;
    scanf("%d",&t);
    while(t--){
        int flag=1;
        scanf("%d%d%d",&n,&x,&y);
        if(x>y) swap(x,y);
        if(x*y%n || x<(n+1)/2){
            printf("Case #%d: RICHARD\n",++C);
            continue;
        }
        if(n==1) {
            printf("Case #%d: GABRIEL\n",++C);
            continue;
        }
        if(n==2) {
            printf("Case #%d: GABRIEL\n",++C);
            continue;
        }
        if(n==3) {
            printf("Case #%d: GABRIEL\n",++C);
            continue;
        }
        if(x<=2 || y<=3){
            printf("Case #%d: RICHARD\n",++C);
            continue;
        }
        if(n==4){
            printf("Case #%d: GABRIEL\n",++C);
            continue;
        }
        if(n>=7) {
            printf("Case #%d: RICHARD\n",++C);
            continue;
        }
    }
}
