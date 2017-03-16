#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef long long LL;

int tt;
LL l, x;
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
  LL i, j;
  LL len;
  int curSign;
  char curChar;
  LL posiI, posiK;

  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%lld%lld", &l, &x);
    scanf("%s", str);

    len = l*x;
    curSign = 1;
    curChar = '1';
    for(i=0; i<4*l && i<len; ++i){
      curChar = mul(curSign, curChar, str[i%l]);
      if(curSign==1 && curChar=='i'){
        break;
      }
    }
    if(curSign!=1 || curChar!='i'){
      printf("Case #%d: NO\n", tc);
      continue;
    }
    posiI = i;

    curSign = 1;
    curChar = '1';
    for(i=len-1; i>posiI && i>=len-4*l; --i){
      curChar = mul(curSign, str[i%l], curChar);
      if(curSign==1 && curChar=='k'){
        break;
      }
    }
    if(curSign!=1 || curChar!='k'){
      printf("Case #%d: NO\n", tc);
      continue;
    }
    posiK = i;

    curSign = 1;
    curChar = '1';
    i = (posiI+1) + (((posiK-posiI-1) / (4*l)) * (4*l));
    for(; i<posiK; ++i){
      curChar = mul(curSign, curChar, str[i%l]);
    }
    if(curSign != 1 || curChar != 'j'){
      printf("Case #%d: NO\n", tc);
    }else{
      printf("Case #%d: YES\n", tc);
    }
  }
  return 0;
}
