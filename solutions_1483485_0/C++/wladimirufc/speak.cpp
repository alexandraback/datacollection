#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


char s1[30] = "abcdefghijklmnopqrstuvwxyz";
char s2[30] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
       FILE *fp=fopen("A-small-attempt5.in", "r");
			 FILE *ofp=fopen("respostas4.out", "w");
       
			 //FILE *fp=fopen("A-large-practice.in", "r"),
       //*ofp=fopen("respuestaL.out", "w");

       int T;
       char linha[1024];
       
       fgets (linha , 1024 , fp);
       sscanf(linha, "%d", &T);
       
      
			 
       for(int tc=1;tc<=T;tc++)
       {
               
               fgets (linha , 1024 , fp);
               printf("%s\n",linha);

						   for(int i=0;linha[i]!='\0';i++){
      					if(linha[i]>='a' && linha[i]<='z') linha[i]=s2[linha[i]-'a'];
      	
    					 }


               // print cases
               fprintf(ofp, "Case #%d: %s", tc,linha);
               
       }
       
       system("PAUSE");
       
       fclose(fp);
       fclose(ofp);
       return 0;
}
