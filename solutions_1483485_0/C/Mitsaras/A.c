#include <stdio.h>
#include <stdlib.h>

char map(char a){

  switch (a){
  case 'a':return 'y';
  case 'b':return 'h';
  case 'c':return 'e';
  case 'd':return 's';
  case 'e':return 'o';
  case 'f':return 'c';
  case 'g':return 'v';
  case 'h':return 'x';
  case 'i':return 'd';
  case 'j':return 'u';
  case 'k':return 'i';
  case 'l':return 'g';
  case 'm':return 'l';
  case 'n':return 'b';
  case 'o':return 'k';
  case 'p':return 'r';
  case 'q':return 'z';
  case 'r':return 't';
  case 's':return 'n';
  case 't':return 'w';
  case 'u':return 'j';
  case 'v':return 'p';
  case 'w':return 'f';
  case 'x':return 'm';
  case 'y':return 'a';
  case 'z':return 'q';
  case ' ':return ' ';
  }
  
}

main(){
  int t,T;
  char c;
  FILE * f;
  FILE * g;

  f=fopen("A.in","r");
  g=fopen("A.txt","w");

  fscanf(f,"%d\n",&T);
  for (t=1;t<=T;t++){
    fprintf(g,"Case #%d: ",t);
    while ((c=getc(f))!='\n') fprintf(g,"%c",map(c));
    putc('\n',g);
  }


}
