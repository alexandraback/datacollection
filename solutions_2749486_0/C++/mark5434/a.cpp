#include <stdio.h>
#include <string>

using namespace std;

int x,y;
FILE *out;

int calc(int caseid) {
  fprintf(out,"Case #%d: ",caseid);
  if (x<0) {
    for (int i=0;i<-x;i++) {
      fprintf(out,"EW");
    }
  }
  else {
    for (int i=0;i<x;i++) {
      fprintf(out,"WE");
    }
  }
  if (y<0) {
    for (int i=0;i<-y;i++) {
      fprintf(out,"NS");
    }
  }
  else {
    for (int i=0;i<y;i++) {
      fprintf(out,"SN");
    }
  }
  fprintf(out,"\n");
  return 0;
}

int main()
{
  FILE *fp = fopen("../in","r");
  out = fopen("../out","w");
 
  char line[1024];
  fgets(line, 1024, fp);
  int ln=atoi(line);
  for (int i=0;i<ln;i++) {
    fscanf(fp,"%d %d",&x,&y);
    //fprintf(out,"%s xxx %d",str,n);
    calc(i+1);
  }
}

