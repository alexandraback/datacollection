#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
int main(){
   freopen("input228.txt","r",stdin);
   freopen("b9.txt","w",stdout);
int t,n,i,j,a,k,l,m,p,ans,x,y,x1,y1;
scanf("%d",&t);
for(i=1;i<=t;++i){
    scanf("%d%d",&x,&y);
    printf("Case #%d: ",i);
    if(x>0){
    for(j=1;j<=2*x;j++){
    if(j%2==0){
    printf("E");
    }
    else{
    printf("W");
    }
    }
    }
    if(x<0){
        x1=x*(-1);
    for(j=1;j<=2*x1;j++){
    if(j%2==0){
    printf("W");
    }
    else{
    printf("E");
    }
    }
    }
    if(y>0){
    for(j=1;j<=2*y;j++){
    if(j%2==0){
    printf("N");
    }
    else{
    printf("S");
    }
    }
    }
    if(y<0){
        y1=y*(-1);
    for(j=1;j<=2*y1;j++){
    if(j%2==0){
    printf("S");
    }
    else{
    printf("N");
    }
    }
    }
    printf("\n");

}
return 0;
}
