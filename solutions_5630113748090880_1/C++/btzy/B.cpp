#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,k;
bool arr[2501];
int main(){
    scanf("%d",&t);
    for(int c=1;c<=t;++c){
        fill(arr,arr+2501,false);
        scanf("%d",&n);
        for(int i=0;i<2*n-1;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&k);
                arr[k]=!arr[k];
            }
        }
        printf("Case #%d:",c);
        for(int i=0;i<=2500;++i){
            if(arr[i])printf(" %d",i);
        }
        printf("\n");
    }
}
