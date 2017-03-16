#include<stdio.h>
#include<string.h>

char temp[1009],A[30];
int cas,cas1,l,i;

int main()
{

strcpy(A,"yhesocvxduiglbkrztnwjpfmaq");

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-output.out","w",stdout);


gets(temp);
sscanf(temp,"%d",&cas);

for(cas1=1;cas1<=cas;cas1++)
{
   gets(temp);
   l = strlen(temp);
   
   printf("Case #%d: ",cas1);
   
   for(i=0;i<l;i++)
   {
   if(temp[i]>='a'&&temp[i]<='z')
   printf("%c",A[temp[i]-'a']);
   else
   printf("%c",temp[i]);
   }
                     
   printf("\n");       
}    

return 0;    
}
