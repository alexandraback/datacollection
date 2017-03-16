#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){

int t;
int n = 0;
int v = 0;
int ty=0;
int tx=0;
int a;
int b;

scanf("%d\n",&t);
for (int i=0; i<t; i++){
    scanf("%d %d",&a,&b);
    printf("Case #%d: ", i+1);

if(a>0){
        for(int j=0; j<a; j++)
           printf("WE");
}
if(a<0){
        for(int j=0; j>a; j--)
           printf("EW");
}
if(b>0){
        for(int j=0; j<b; j++)
           printf("SN");
}
if(b<0){
        for(int j=0; j>b; j--)
           printf("NS");
}
                
printf("\n");

}
  
//system("pause");
return 0;                  
}
