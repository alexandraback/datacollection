#include<stdio.h>

getSoln(int r, int c, int w) {
    if(w==1){
        return r*c;
    }
    if(w==c){
        return c + (r-1);
    }
    else{
        return ((c/w) * (r-1)) + w + (c/w) - (c%w==0);
    }
}

main()
{
    int r,c,t,w,soln,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d",&r,&c,&w);
        soln = getSoln(r,c,w);
        printf("Case #%d: %d\n",i+1, soln);
    }
    return 0;
}