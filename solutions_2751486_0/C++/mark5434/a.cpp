#include <stdio.h>
#include <string>

using namespace std;

char str[10000000];
int n;
int gst[1000000];
int gn[1000000];
int numg;
FILE *out;

int calc(int caseid) {
  numg=0;
  int lastnum=0;
  long res=0;
  for (int i=0;i<strlen(str);i++) {
    if (str[i]=='a' || str[i]=='e' || str[i]=='o' || str[i]=='i' || str[i]=='u') {
      lastnum=0;
    }
    else {
      lastnum++;
      if (lastnum==n) {
        gst[numg]=i-n+1;
        gn[numg]=n;
        numg++;
      }
      if (lastnum>n) {
        gn[numg-1]++;
      }
    }
    if (numg>0) {
      int ii=gst[numg-1] + gn[numg-1] -n;
      res+=ii+1;
    }
    //fprintf(out,"Case #%d: %d\n",caseid,gn[0]);
  }
 
  fprintf(out,"Case #%d: %ld\n",caseid,res);
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
    fscanf(fp,"%s %d",str,&n);
    //fprintf(out,"%s xxx %d",str,n);
    calc(i+1);
  }
}

