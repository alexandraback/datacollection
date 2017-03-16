#include <stdio.h>

int main(void){
  int i, t, c;
  scanf("%d\n", &t);
  for(i = 0; i < t; ++i){
    printf("Case #%d: ", i + 1);
    while((c = getchar()) != '\n'){
      switch (c){
      case 'a': putchar('y');
        break;
      case 'b': putchar('h');
        break;
      case 'c': putchar('e');
        break;
      case 'd': putchar('s');
        break;
      case 'e': putchar('o');
        break;
      case 'f': putchar('c');
        break;
      case 'g': putchar('v');
        break;
      case 'h': putchar('x');
        break;
      case 'i': putchar('d');
        break;
      case 'j': putchar('u');
        break;
      case 'k': putchar('i');
        break;
      case 'l': putchar('g');
        break;
      case 'm': putchar('l');
        break;
      case 'n': putchar('b');
        break;
      case 'o': putchar('k');
        break;
      case 'p': putchar('r');
        break;
      case 'q': putchar('z');
        break;
      case 'r': putchar('t');
        break;
      case 's': putchar('n');
        break;
      case 't': putchar('w');
        break;
      case 'u': putchar('j');
        break;
      case 'v': putchar('p');
        break;
      case 'w': putchar('f');
        break;
      case 'x': putchar('m');
        break;
      case 'y': putchar('a');
        break;
      case 'z': putchar('q');
        break;
      default: putchar(c);
      }
    }
    putchar(c);
  }
  return 0;
}
