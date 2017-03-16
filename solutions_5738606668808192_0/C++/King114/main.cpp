#include <stdio.h>

int base10to2(int x)
{
    int dap=0,temp,sum;
    int i;
    for(i=1;x>0;i*=10){
        temp=x%2;
        sum=temp*i;
        dap+=sum;
        x/=2;
    }
    return dap;
}

int seung(int x,int k)
{
    int result=1;
    while(k>0){
        result*=x;
        k--;
    }
    return result;
}

int main()
{
    int t,n,j;
    int i,i_2,k;

    FILE  *in, *out;

    in=fopen("C-small-attempt0.in","r");
    out=fopen("output.txt","w");


    fscanf(in,"%d",&t);
    fscanf(in,"%d %d",&n,&j);

    fprintf(out,"Case #1:\n");
    for(i=1;i<=j;i++){
        i_2=base10to2(i);
        fprintf(out,"1%06d11%06d1 ",i_2,i_2);
        for(k=2;k<=10;k++) fprintf(out,"%d ",seung(k,n/2)+1);
        fprintf(out,"\n");
    }



    return 0;

}
