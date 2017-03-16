#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int tt;
int l, x;
char str[10010];

char chart[4][4] = {{'1', 'i', 'j', 'k'},
                    {'i', '1', 'k', 'j'},
                    {'j', 'k', '1', 'i'},
                    {'k', 'j', 'i', '1'}};
int sign[4][4] = {{1, 1, 1, 1},
                  {1, -1, 1, -1},
                  {1, -1, -1, 1},
                  {1, 1, -1, -1}};

int trans(char a){
  switch(a){
  case '1':
    return 0;
  case 'i':
    return 1;
  case 'j':
    return 2;
  case 'k':
    return 3;
  }
}
char mul(int &curSign, char a, char b){
  int ai, bi;
  ai = trans(a);
  bi = trans(b);
  curSign *= sign[ai][bi];
  return chart[ai][bi];
}

int main(void){
  int i, j;
  int len;
  int curSign;
  char curChar;
  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%d%d", &l, &x);
    scanf("%s", str);
    for(i=0; i<l; ++i){
      for(j=1; j<x; ++j){
        str[i+l*j] = str[i];
      }
    }

    len = l*x;
    curSign = 1;
    curChar = '1';
    for(i=0; i<len; ++i){
      if(curSign==1 && curChar=='i'){
        break;
      }
      curChar = mul(curSign, curChar, str[i]);
    }
    if(i >= len){
      printf("Case #%d: NO\n", tc);
      continue;
    }

    curSign = 1;
    curChar = '1';
    for(; i<len; ++i){
      if(curSign==1 && curChar=='j'){
        break;
      }
      curChar = mul(curSign, curChar, str[i]);
    }
    if(i >= len){
      printf("Case #%d: NO\n", tc);
      continue;
    }

    curSign = 1;
    curChar = '1';
    for(; i<len; ++i){
      curChar = mul(curSign, curChar, str[i]);
    }
    if(curSign != 1 || curChar != 'k'){
      printf("Case #%d: NO\n", tc);
    }else{
      printf("Case #%d: YES\n", tc);
    }
  }
  return 0;
}
