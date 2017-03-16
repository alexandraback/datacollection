#include <cstdio>
using namespace std;
int t,tt,i,j;
bool d,x,o,cx,co;
char s[5][5];
int main() {
  freopen("As.in","r",stdin);
  freopen("As.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    d=x=o=false;
    for (i=0; i<4; i++) {
	  scanf("%s",s[i]);
	  for (j=0; j<4; j++) if (s[i][j]=='.') d=true;
	}
	for (i=0; i<4; i++) {
	  cx=co=false;
	  for (j=0; j<4; j++) {
		if (s[i][j]=='.') break;
		if (s[i][j]=='X') cx=true;
		if (s[i][j]=='O') co=true;
	  }
	  if (j>=4 && !(cx && co)) { x|=cx; o|=co; }
	}
	for (j=0; j<4; j++) {
	  cx=co=false;
	  for (i=0; i<4; i++) {
		if (s[i][j]=='.') break;
		if (s[i][j]=='X') cx=true;
		if (s[i][j]=='O') co=true;
	  }
	  if (i>=4 && !(cx && co)) { x|=cx; o|=co; }
	}
	cx=co=false;
	for (i=0; i<4; i++) {
	  if (s[i][i]=='.') break;
	  if (s[i][i]=='X') cx=true;
	  if (s[i][i]=='O') co=true;
	}
	if (i>=4 && !(cx && co)) { x|=cx; o|=co; }
	cx=co=false;
	for (i=0; i<4; i++) {
	  if (s[i][3-i]=='.') break;
	  if (s[i][3-i]=='X') cx=true;
	  if (s[i][3-i]=='O') co=true;
	}
	if (i>=4 && !(cx && co)) { x|=cx; o|=co; }
    printf("Case #%d: ",t);
	if (x) puts("X won"); else
	  if (o) puts("O won"); else
	    puts(d?"Game has not completed":"Draw");
  }
  return 0;
}
