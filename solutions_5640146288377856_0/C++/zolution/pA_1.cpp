#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A_o2.txt","w",stdout);
    int T = 0;

    scanf("%d",&T);
    for(int g=1;g<=T;g++){
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        int ans = 0;
        ans+= (c/w)*r;
        ans+=w;
        if(c%w==0) ans--;
        printf("Case #%d: %d\n",g,ans);
    }
    return 0;
}
