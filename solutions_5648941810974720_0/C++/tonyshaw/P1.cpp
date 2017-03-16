#include<cstdio>
#include<cstring>

#define MaxN 2016
#define MaxM 26

char str[MaxN];
int map[MaxM];
int ret[10];
char* dict[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void build(int i, char ch) {
  ret[i]=map[ch-'A'];
  for (int j=0; j!=strlen(dict[i]); j++)
    map[dict[i][j]-'A']-=ret[i];
}

int main() {
  int t;

  scanf("%d\n", &t);
  for (int i=0; i!=t; i++) {
    scanf("%s\n",str);
    memset(map,0,sizeof(map));
    memset(ret,0,sizeof(ret));
    for (int j=0; j!=strlen(str); j++)
      map[str[j]-'A']++;
    build(8,'G');
    build(6,'X');
    build(7,'S');
    build(5,'V');
    build(4,'U');
    build(3,'H');
    build(2,'W');
    build(0,'Z');
    build(1,'O');
    build(9,'I');
    printf("Case #%d: ",i+1);
    for (int j=0; j!=10; j++) {
      for (int k=0; k!=ret[j]; k++) {
	printf("%d",j);
      }
    }
    printf("\n");
  }
}
      
    
