#include <stdio.h>
#include <string>

using namespace std;

int row,col;
int b[100][100];
int res[100][100];
int calc(int caseid) {
  int x[100],y[100];

  for (int r=0;r<row;r++) {
    x[r]=0;
    for (int c=0;c<col;c++) {
      if (b[r][c]>x[r]) x[r]=b[r][c];
    }
  }
  for (int c=0;c<col;c++) { 
    y[c]=0;
    for (int r=0;r<row;r++) {
      if (b[r][c]>y[c]) y[c]=b[r][c];
    }
  }
  for (int r=0;r<row;r++) { 
    for (int c=0;c<col;c++) {
      res[r][c]=100;
    }
  }
  bool same=true;
  for (int r=0;r<row;r++) {
    for (int c=0;c<col;c++) {
      res[r][c]=x[r]<y[c]?x[r]:y[c];
      if (res[r][c]!=b[r][c]) {
        same=false;
        break;
      }
    }
  }

  if (same)
    printf("Case #%d: %s\n",caseid,"YES");
  else
    printf("Case #%d: %s\n",caseid,"NO");
  return 0;
}

int main()
{
  FILE *fp = fopen("in","r");
  char line[1024];
  fgets(line, 1024, fp);
  int n=atoi(line);
  for (int i=0;i<n;i++) {
    fscanf(fp,"%d %d",&row,&col);
    for (int r=0;r<row;r++) {
      for (int c=0;c<col;c++) {
        fscanf(fp,"%d",&b[r][c]);
      }
    }
calc(i+1);
  }
}

