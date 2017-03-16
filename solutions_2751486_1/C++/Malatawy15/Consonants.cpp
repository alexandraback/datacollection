#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n;
    char arr[1000011];
    scanf("%d",&t);
    for (int k=1;k<=t;k++){
        int sum = 0,is = 0,i,li = -1;
        scanf("%s %d",arr, &n);
        int size = strlen(arr);
        for (i =0;i<size;i++){
            if (arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
                is = 0;
            }
            else {
                is++;
                if (is==n){
                    if (li==-1){
                        sum+=((i-n+2)*(size-i));
                    }
                    else{
                        sum+=((i-n+1-li)*(size-i));
                    }
                    li = i-n+1;
                    is--;
                }
            }
        }
        printf("Case #%d: %d\n", k, sum);
    }
}
