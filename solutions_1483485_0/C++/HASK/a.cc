
#include <cstdio>
#include <cstring>

int set_mapping(char* mapping, char* in, char* out) {

  int n = strlen(in);
  for (int i = 0; i < n; i++) {
    if (in[i] < 'a' || in[i] > 'z') continue;

    mapping[in[i]-'a'] = out[i];
  }

  return 0;
}

int init_mapping(char* mapping) {

  char* tmp_i = (char*)"y qee";
  char* tmp_o = (char*)"a zoo";
  set_mapping(mapping, tmp_i, tmp_o);

  tmp_i = (char*)"ejp mysljylc kd kxveddknmc re jsicpdrysi";
  tmp_o = (char*)"our language is impossible to understand";
  set_mapping(mapping, tmp_i, tmp_o);

  tmp_i = (char*)"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  tmp_o = (char*)"there are twenty six factorial possibilities";
  set_mapping(mapping, tmp_i, tmp_o);

  tmp_i = (char*)"de kr kd eoya kw aej tysr re ujdr lkgc jv";
  tmp_o = (char*)"so it is okay if you want to just give up";
  set_mapping(mapping, tmp_i, tmp_o);

  return 0;
}


int main(int argc, char** argv) {

  char mapping[27]; 
  mapping[26] = '\0';
  mapping[25] = 'q';
  init_mapping(mapping);

  int T;
  scanf("%d",&T); getchar();

  for (int t = 1; t<=T; t++) {
    printf("Case #%d: ", t);

    char in[101];
    gets(in); // getchar();

    int n = strlen(in);
    for (int i = 0; i < n; i++) {
      if (in[i] < 'a' || in[i] > 'z') putchar(in[i]);
      else putchar(mapping[in[i]-'a']);
    }
    putchar('\n');
  }

  return 0;
}
