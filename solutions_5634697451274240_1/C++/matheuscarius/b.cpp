#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

char inv(char c) {
  return c=='+' ? '-':'+';
}

void troca(int pos, char s[]) {
  char aux[110];
  for(int i = 0; i < pos; i++)
    aux[i]=inv(s[i]);
  reverse(aux,aux+pos);
  for(int i = 0; i < pos; i++)
    s[i]=aux[i];
}

int main () {
  int t;
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++) {
    char s[110];
    scanf(" %s", s);
    int len = strlen(s);
    int cont = 0;
    while(1) {
      int flip;
      for(flip = 0; flip < len; flip++) {
        if(s[flip]!=s[0]) break;
      }
      //printf("%d %d\n", found,flip);
      if(flip == len && s[0] == '+') break;
      troca(flip,s);
      cont++;
    }
    printf("Case #%d: %d\n", caso, cont);
  }
  return 0;    
}
