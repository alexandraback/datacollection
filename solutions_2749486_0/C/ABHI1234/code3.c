#include<stdio.h>

int main()
{
int T,i,j,k,l,x,y;
char a[1000];
scanf("%d",&T);
for(i=1;i<=T;i++){
l=0;
scanf("%d %d",&x,&y);
if(x<0){
for(j=0;j<-2*x;j++){
if(j%2)
a[j]='W';
else
a[j]='E';
}
}
else {

for(j=0;j<2*x;j++){
if(j%2)
a[j]='E';
else
a[j]='W';
}
}
l=j;
if(y>0){
for(j=0;j<2*y;j++){
if(j%2)
a[l+j]='N';
else
a[l+j]='S';
}
}
else {

for(j=0;j<-2*y;j++){
if(j%2)
a[l+j]='S';
else
a[l+j]='N';
}
}
l=l+j;
a[l]='\0';
printf("Case #%d: %s\n",i,a);
}

return 0;

}
