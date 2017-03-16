#include <stdio.h>

int cnt=0;
int check[10];
int a[100];

void digitCheck(int x)
{
    while(x>0){
        if(check[x%10]==0){
            check[x%10]=1;
            cnt++;
        }
        x/=10;
    }
    return;
}

int lastNum(int x)
{
    int i=0;
    if(x==0) return -1;
    while(1){
        if(cnt==10) break;

        i++;
        digitCheck(x*i);
    }
    return x*i;
}

int main()
{
    int n,t,tmp;
    int i,j;


    FILE  *in, *out;

    in=fopen("A-small-attempt0.in","r");
    out=fopen("output.txt","w");


    fscanf(in,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(in,"%d",&a[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<10;j++) check[j]=0;
        cnt=0;

        tmp=lastNum(a[i]);
        if(tmp==-1) fprintf(out,"Case #%d: INSOMNIA\n",i+1);
        else fprintf(out,"Case #%d: %d\n",i+1,tmp);
    }
    return 0;
}
