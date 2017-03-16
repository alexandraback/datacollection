#include <stdio.h>
#include <string>

using namespace std;

char b[4][4];
int calc(int caseid) {
  for (int i=0;i<4;i++) {
    int no=0,nt=0,nx=0;
    for (int j=0;j<4;j++) {
      if (b[i][j]=='O') no++;
      if (b[i][j]=='X') nx++;
      if (b[i][j]=='T') nt++;
    }
    if (no+nt==4) {
      printf("Case #%d: O won\n",caseid);
      return 0;
    }
    if (nx+nt==4) {
      printf("Case #%d: X won\n",caseid);
      return 0;
    }
  }
  bool end=true;
  for (int i=0;i<4;i++) {
    int no=0,nt=0,nx=0;
    for (int j=0;j<4;j++) {
      if (b[i][j]=='.') end=false;
      if (b[j][i]=='O') no++;
      if (b[j][i]=='X') nx++;
      if (b[j][i]=='T') nt++;
    }
    if (no+nt==4) {
      printf("Case #%d: O won\n",caseid);
      return 0;
    }
    if (nx+nt==4) {
      printf("Case #%d: X won\n",caseid);
      return 0;
    }
  }
  {
    int no=0,nt=0,nx=0;
    for (int j=0;j<4;j++) {
      if (b[j][3-j]=='O') no++;
      if (b[j][3-j]=='X') nx++;
      if (b[j][3-j]=='T') nt++;
    }
    if (no+nt==4) {
      printf("Case #%d: O won\n",caseid);
      return 0;
    }
    if (nx+nt==4) {
      printf("Case #%d: X won\n",caseid);
      return 0;
    }
  }
  {
    int no=0,nt=0,nx=0;
    for (int j=0;j<4;j++) {
      if (b[j][j]=='O') no++;
      if (b[j][j]=='X') nx++;
      if (b[j][j]=='T') nt++;
    }
    if (no+nt==4) {
      printf("Case #%d: O won\n",caseid);
      return 0;
    }
    if (nx+nt==4) {
      printf("Case #%d: X won\n",caseid);
      return 0;
    }
  }

  if (end) 
    printf("Case #%d: Draw\n",caseid);
  else
    printf("Case #%d: Game has not completed\n",caseid);
  return 0;
}

int main()
{
  FILE *fp = fopen("in","r");
  char line[1024];
  fgets(line, 1024, fp);
  int n=atoi(line);
  for (int i=0;i<n;i++) {
    for (int j=0;j<4;j++) {
      fgets(b[j], 10, fp);
    }
    calc(i+1);
    fgets(line, 10, fp);
  }
}

