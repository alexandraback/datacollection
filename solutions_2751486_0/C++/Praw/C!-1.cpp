#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){

int t;
int ans = 0;
char c[1000];
int n = 0;
int v = 0;

scanf("%d\n",&t);
for (int i=0; i<t; i++){
    scanf("%s %d",&c,&n);
             
ans = 0;
v = 0;

for(int j=0; j<strlen(c); j++){
        for(int k=j; k<strlen(c); k++){
                v = 0;
                for(int p=j; p<=k; p++){
                if(c[p]!='a' &&
                   c[p]!='e' &&
                   c[p]!='i' &&
                   c[p]!='o' &&
                   c[p]!='u')
                {  
                   v++;
                   if(v==n){ ans++;break;}
                }
                else v = 0;    
                }
        }
}
                
printf("Case #%d: %d\n", i+1, ans);


}
  
//system("pause");
return 0;                  
}
