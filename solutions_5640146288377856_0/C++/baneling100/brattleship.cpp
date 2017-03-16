#include <stdio.h>

int T, R, C, W;

int main(void) {

    int i;

    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&T);
    for(i=1 ; i<=T ; i++) {
        scanf("%d %d %d",&R,&C,&W);
        if(C%W) printf("Case #%d: %d\n",i,(C/W)*R+W);
        else printf("Case #%d: %d\n",i,(C/W)*R+W-1);
    }
    return 0;
}
