#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char toTranslate[105];
char output[105];

int main(){
  char* translation="yhesocvxduiglbkrztnwjpfmaq";
  char numCases[10];
  fgets(numCases, 10, stdin);
  int n = atoi(numCases);
  for(int i =1;i<=n;i++){
    fgets(toTranslate, 105, stdin);
    for(int k=0; k<strlen(toTranslate);k++){
      if(toTranslate[k]==' '){
        output[k]=' ';
      }
      else if(toTranslate[k]=='\n' || toTranslate[k]==EOF){
        output[k]=0;
      }
      else{
        output[k] = translation[(tolower(toTranslate[k]) - 97)];
      }
    }
    output[strlen(toTranslate)]=0;
    printf("Case #%d: %s\n", i, output);
  }
}
