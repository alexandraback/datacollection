#include <stdio.h>
#include <string>
#include <map>

using namespace std;

FILE *out;
long long st,ed;

int det(long long num) {
  long long tot=2*num*(num-1)+(2*st+1)*num;
  if (tot==ed) {return 0;}
  if (tot>ed) {return -1;}
  if (tot<ed) {return 1;}
  return 0;
}

int calc(int caseid) {
  //fprintf(out,"%lldaaaa%lld\n",st,ed);
  long long left=ed;
  long long r=st;
  long long numl=1,numb=-1;
  if (ed<2*st+1) {
    fprintf(out,"Case #%d: %lld\n", caseid, 0);
    return 0;
  }
  numb=1;
  while (true) {
    if (det(numb)>=1) {
      numb*=2;
    }
    else {break;}
  }
  if (numb==1) {
    fprintf(out,"Case #%d: %lld\n", caseid, 1);
    return 0;
  }
  numl=numb/2;
  long long step=numl;
  while (true) {
    if (step==0) {break;}
    if (det(numl+step)>=0) {
      numl+=step;
    }
    step/=2;
  }
  fprintf(out,"Case #%d: %lld\n", caseid, numl);
  return 0;
}

int main()
{
  FILE *fp = fopen("in","r");
  out = fopen("out","w");
 
  char line[1024];
  fgets(line, 1024, fp);
  int n=atoi(line);
  for (int i=0;i<n;i++) {
    fscanf(fp,"%lld%lld",&st,&ed);
    calc(i+1);
  }
}

