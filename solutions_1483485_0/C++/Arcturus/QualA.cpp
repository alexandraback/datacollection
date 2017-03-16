#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
  int jcase;
  char kal[101];
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  gets(kal);
  for(int icase=0; icase < jcase; icase++){
    gets(kal);
    printf("Case #%d: ", icase+1);
    for(int i=0; i<strlen(kal); i++){
      switch(kal[i]){
        case 'a' : printf("y"); break;
        case 'b' : printf("h"); break;
        case 'c' : printf("e"); break;
        case 'd' : printf("s"); break;
        case 'e' : printf("o"); break;
        case 'f' : printf("c"); break;
        case 'g' : printf("v"); break;
        case 'h' : printf("x"); break;
        case 'i' : printf("d"); break;
        case 'j' : printf("u"); break;
        case 'k' : printf("i"); break;
        case 'l' : printf("g"); break;
        case 'm' : printf("l"); break;
        case 'n' : printf("b"); break;
        case 'o' : printf("k"); break;
        case 'p' : printf("r"); break;
        case 'q' : printf("z"); break;
        case 'r' : printf("t"); break;
        case 's' : printf("n"); break;
        case 't' : printf("w"); break;
        case 'u' : printf("j"); break;
        case 'v' : printf("p"); break;
        case 'w' : printf("f"); break;
        case 'x' : printf("m"); break;
        case 'y' : printf("a"); break;
        case 'z' : printf("q"); break;
        case ' ' : printf(" "); break;
      }
    }
    printf("\n");
  } 
  return 0;
}
