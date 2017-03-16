#include <stdio.h>
#include <string>

using namespace std;

long long int listnum[1000];
int num;
void load() {
  FILE *fp = fopen("cheat","r");
  int p=0;
  while (!feof(fp)){
    fscanf(fp,"%ld",&listnum[p++]);
  }
  num=p;
}

long long int st,ed;
int calc(int caseid) {
  int i=0;
  for (;i<num;i++) {
    if (st<=listnum[i]) break;
  }
  int stid=i;
  for (;i<num;i++) {
    if (ed<=listnum[i]) break;
  }
  int edc=0;
  if (ed==listnum[i]) {edc=1;}
  int r=i-stid+edc;
  printf("Case #%d: %d\n",caseid,r);
  return 0;
}

int main()
{
  FILE *fp = fopen("in","r");
  char line[1024];
  fgets(line, 1024, fp);
  load();
  int n=atoi(line);
  long long int listnum[1000];
  for (int i=0;i<n;i++) {
    fscanf(fp,"%ld %ld",&st,&ed);
    calc(i+1);
  }
}

