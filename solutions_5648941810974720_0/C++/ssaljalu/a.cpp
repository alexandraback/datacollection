#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T,TT;
char s[2001];
int cnt[256];
int d[10];
char str[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void sub(int x, int y){
  int i;
  d[x]+=y;
  for(i=0;str[x][i];i++)
    cnt[str[x][i]]-=y;
}

int main() {
  int i;
  scanf("%d",&TT);
  for(T=1;T<=TT;T++){
    scanf("%s",s);
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    for(i=0;s[i];i++)
      cnt[s[i]]++;
    sub(0,cnt['Z']);
    sub(2,cnt['W']);
    sub(4,cnt['U']);
    sub(6,cnt['X']);
    sub(8,cnt['G']);
    sub(1,cnt['O']);
    sub(3,cnt['T']);
    sub(5,cnt['F']);
    sub(7,cnt['S']);
    sub(9,cnt['I']);
    printf("Case #%d: ",T);
    for(i=0;i<10;i++)while(d[i]--)printf("%d",i);
    printf("\n");
  }
  return 0;
}
