#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n;
struct node{
    int x,i;
}a[1000];
int cmp(node a,node b){
    if (a.x==b.x) return a.i<b.i;
    return a.x>b.x;
}
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        printf("Case #%d: ",cas);
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].i=i;
        }
        sort(a+1,a+1+n,cmp);
        while(a[1].x>a[2].x) {
            printf("%c ",'A'-1+a[1].i);
            a[1].x--;
        }
        for (int i=3;i<=n;i++){
            while(a[i].x){
               printf("%c ",'A'-1+a[i].i);
                a[i].x--;
            }
        }
        while(a[1].x>1){
            printf("%c%c ",'A'-1+a[1].i,'A'-1+a[2].i);
            a[1].x--;a[2].x--;
        }
        printf("%c%c\n",'A'-1+a[1].i,'A'-1+a[2].i);
    }
    return 0;
}
