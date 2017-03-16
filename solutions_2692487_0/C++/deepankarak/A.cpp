#include <algorithm>
#include <iostream>

using namespace std;
 
 
int main(){
int a,t,i,j,n,op,m,arr[101];
freopen("asmall.in","r",stdin);
freopen("asmallo.txt","w",stdout);
scanf("%d",&t);
for(i=0;i<t;++i){
scanf("%d %d",&a,&n);
op=0;
for(j=0;j<n;++j){
    scanf("%d",&arr[j]);
}
if(a==1){
    printf("Case #%d: %d\n",i+1,n);
continue;
}
sort(arr,arr+n);
m=n;
for(j=0;j<n;++j){
    if(arr[j]<a){
        a+=arr[j];
    }
    else{
            while(arr[j]>=a){
                op++;
                a=2*a-1;
            }
        a+=arr[j];
    }
    if(m>(op+n-j-1))
        m=op+n-j-1;
 
}
printf("Case #%d: %d\n",i+1,m);
}
return 0;
}
