#include <stdio.h>
#include <stdlib.h>

struct mapping {
  char english;
  char googlerese;
} mapping_array[] = {
  'a', 'y',
  'b', 'n',
  'c', 'f',
  'd', 'i',
  'e', 'c',
  'f', 'w',
  'g', 'l',
  'h', 'b',
  'i', 'k',
  'j', 'u',
  'k', 'o',
  'l', 'm',
  'm', 'x',
  'n', 's',
  'o', 'e',
  'p', 'v',
  'q', 'z',
  'r', 'p',
  's', 'd',
  't', 'r',
  'u', 'j',
  'v', 'g',
  'w', 't',
  'x', 'h',
  'y', 'a',
  'z', 'q'
};

void read_input_string(FILE *fp, char *input_string) {
  char c;
  int sp = 0;
  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      break;
    }
    input_string[sp++] = c;
  }
  input_string[sp] = 0;
}

char translate_char(char c) {
  int i;
  if (c == ' ') {
    return c;
  }
  for (i = 0; i < 26; i++) {
    if (c == mapping_array[i].googlerese) {
      return mapping_array[i].english;
    }
  }
  return '?';
}

void translate_string(char *input_string, char *output_string) {
  int sp = 0;
  while (input_string[sp]) {
    output_string[sp] = translate_char(input_string[sp]);
    sp++;
  }
  output_string[sp] = 0;
}

int main(void) {
  int T, i;
  char input_string[101];
  char output_string[101];
  FILE *ifp = fopen("input", "r");
  FILE *ofp = fopen("output", "w");
  if (!ifp) {
    return 1;
  }
  if (!ofp) {
    return 2;
  }
  fscanf(ifp, "%d\n", &T);
  printf("%d test cases\n", T);
  for (i = 1; i <= T; i++) {
    read_input_string(ifp, input_string);  
    translate_string(input_string, output_string);
    printf("Case #%d: %s\n", i, input_string);
    printf("Case #%d: %s\n", i, output_string);
    fprintf(ofp, "Case #%d: %s\n", i, output_string);
  }
  fclose(ifp);
  fclose(ofp);
  return 0;
}
