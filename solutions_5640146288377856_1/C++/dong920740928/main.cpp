#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T;
    int R,C,W;
    scanf("%d",&T);getchar();
    for(int k=1;k<=T;++k)
    {
        scanf("%d %d %d",&R,&C,&W);getchar();
        if(C%W==0)
            printf("Case #%d: %d\n",k,R*(C/W)+W-1);
        else
            printf("Case #%d: %d\n",k,R*(C/W)+W);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
