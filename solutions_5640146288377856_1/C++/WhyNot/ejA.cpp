

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int T;

int main()
{
    int R,C,W;

    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d %d %d",&R,&C,&W);
        printf("Case #%d: %d\n",c+1,(C/W)*R+W-1+(C%W?1:0));
    }
    return 0;
}
