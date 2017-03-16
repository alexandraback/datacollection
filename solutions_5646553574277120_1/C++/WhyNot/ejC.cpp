

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long top,C,D,V,d,count;
    int T;
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%ld %ld %ld",&C,&D,&V);
        count=0;
        top=1;
        for(int i=0;i<D;i++){
            scanf("%ld",&d);
            while(d>top){
                count++;
                top+=C*top;
            }
            top+=C*d;
        }
        while(V>=top){
            count++;
            top+=C*top;
        }

        printf("Case #%d: %ld\n",c+1,count);
    }
    return 0;
}
