#include <stdio.h>
#include <assert.h>

int find_translation(int argc, char *argv[]) {
  char *googlerese = argv[1];
  char *english = argv[2];
  FILE *goog;
  FILE *eng;
  char c, i;

  printf("googlerese: %s -> english: %s\n", googlerese, english);
  
  goog = fopen(googlerese,"r");
  eng = fopen(english,"r");

  while((c=fgetc(goog)) != EOF) {
    i=fgetc(eng);
    putchar(c);
    printf(" -> ");
    putchar(i);
    putchar('\n');
  }
  
  return 0;
}

void translate_line(FILE *f) {
  char c;
  while (((c=fgetc(f)) != '\n') && (c != EOF)) {
    switch(c) {
    case 'a':
      putchar('y');
      break;
    case 'b':
      putchar('h');
      break;
    case 'c':
      putchar('e');
      break;
    case 'd':
      putchar('s');
      break;
    case 'e':
      putchar('o');
      break;
    case 'f':
      putchar('c');
      break;
    case 'g':
      putchar('v');
      break;
    case 'h':
      putchar('x');
      break;
    case 'i':
      putchar('d');
      break;
    case 'j':
      putchar('u');
      break;
    case 'k':
      putchar('i');
      break;
    case 'l':
      putchar('g');
      break;
    case 'm':
      putchar('l');
      break;
    case 'n':
      putchar('b');
      break;
    case 'o':
      putchar('k');
      break;
    case 'p':
      putchar('r');
      break;
    case 'q':
      putchar('z');
      break;
    case 'r':
      putchar('t');
      break;
    case 's':
      putchar('n');
      break;
    case 't':
      putchar('w');
      break;
    case 'u':
      putchar('j');
      break;
    case 'v':
      putchar('p');
      break;
    case 'w':
      putchar('f');
      break;
    case 'x':
      putchar('m');
      break;
    case 'y':
      putchar('a');
      break;
    case 'z':
      putchar('q');
      break;
    case ' ':
      putchar(' ');
      break;
    default:
      assert(0);
    }
  }
}

int translate_goog_to_eng(int argc, char *argv[]) {
  int i, n;
  FILE *google;
  google = fopen(argv[1], "r");
  fscanf(google, "%d", &n);
  fgetc(google); /* newline */
  for (i=0; i < n; i++) {
    printf("Case #%d: ", i+1);
    translate_line(google);
    putchar('\n'); 
  }
  return 0;
}

/*  return find_translation(argc, argv); */

int main(int argc, char *argv[]) {
  return translate_goog_to_eng(argc, argv);
  
}

