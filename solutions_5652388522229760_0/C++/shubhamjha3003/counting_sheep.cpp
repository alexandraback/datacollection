#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1000100
int bound[1000100];
void calc_max_bound(){
    int j,num,bit,max_val=0;
    for(int i=1;i<MAXN;i++){
        j=1;
        bit=0;
        while(bit!=1023){
            num=j*i;
            bound[i]=num;
            while(num){
                bit=bit|(1<<(num%10));
                num/=10;
            }
            max_val=max(max_val,j);
            j++;
        }
    }
}
int main(){
    int t,n,i;
    calc_max_bound();
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        if(n==0)
            printf("Case #%d: INSOMNIA\n",i);
        else
            printf("Case #%d: %d\n",i,bound[n]);
    }
    return 0;
}
