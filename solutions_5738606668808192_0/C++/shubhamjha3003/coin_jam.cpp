#include<cstdio>
long long get_num_in_base(int arr[16],int b){
    long long num=0;
    for(int i=0;i<16;i++){
        num=b*num+arr[i];
    }
    return num;
}
long long get_factor(long long num){
    for(long long fact=3;fact*fact<=num;fact+=2){
        if(num%fact==0)
            return fact;
    }
    return -1;
}
void compute_output(int n=16,int j=50){
    int i,k,num,arr[16];
    arr[0]=arr[15]=1;
    int counter=0;
    long long iter,fact[11];
    for(i=0;i<1<<14&&counter<j;i++){
        k=1;
        num=i;
        while(k<=14){
            arr[k]=num%2;
            num/=2;
            k++;
        }
        for(k=2;k<=10;k++){
            iter=get_num_in_base(arr,k);
            fact[k]=get_factor(iter);
            if(fact[k]==-1)
                break;
        }
        if(k==11){
            for(k=0;k<16;k++){
                printf("%d",arr[k]);
            }
            printf(" ");
            for(k=2;k<=10;k++){
                printf("%lld ",fact[k]);
            }
            printf("\n");
            counter++;
        }
    }
}
int main()
{
    int i,t,n,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&j);
        printf("Case #%d:\n",i);
        compute_output(n,j);
    }
    return 0;
}
