#include<cstdio>

int main(){
    int testcase;
    unsigned long long paintAvail;
    unsigned long long radius;
    unsigned long long i;
    int a;

    unsigned long long curArea;

    scanf("%d",&testcase);
    for(a=1;a<=testcase;a++){
            scanf("%llu %llu",&radius,&paintAvail);
            curArea = 0;
            for(i=0;curArea <= paintAvail;i++){
                curArea += (radius+i*2+1)*(radius+i*2+1) - (radius+i*2)*(radius+i*2);
            }
            printf("Case #%d: %llu\n",a,i-1);
    }

    return 0;
}
