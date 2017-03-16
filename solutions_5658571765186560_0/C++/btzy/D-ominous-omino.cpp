#include<cstdio>
#include<algorithm>
using namespace std;
int tc,x,r,c;
int main(){
    scanf("%d\n",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d%d%d",&x,&r,&c);
        if(r*c%x!=0||x>=7||x>max(r,c)||(x+1)/2>min(r,c)||(x==4&&min(r,c)==2)||(x==6&&min(r,c)==3))printf("Case #%d: RICHARD\n",ct);
        else printf("Case #%d: GABRIEL\n",ct);
    }
}
