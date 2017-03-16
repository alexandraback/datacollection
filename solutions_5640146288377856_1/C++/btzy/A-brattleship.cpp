#include<cstdio>
using namespace std;
int tc,r,c,w;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",ct,r*(c/w)+w+((c%w==0)?-1:0));
    }
}
