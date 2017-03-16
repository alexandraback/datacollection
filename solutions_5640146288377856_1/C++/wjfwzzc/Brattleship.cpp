#include<cstdio>
using namespace std;
int main() {
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t,r,c,w;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",cas,(c/w+w-(c%w==0))*r);
    }
}
