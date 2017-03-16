#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

char buf[10000];

map<char,char> all;

char const* train[3][2]={
  {"ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand"},
  {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities"},
  {"de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up"}};

int main(){
  all['a']='y', all['o']='e', all['z']='q';
  set<char> allow, unused;
  for (int i=3; i--;) for (int j=0; train[i][0][j]; j++) all[train[i][0][j]]=train[i][1][j];
  for (char i='z'+1; i-->'a';) allow.insert(i), unused.insert(i);
  for (auto it: all) allow.erase(it.first), unused.erase(it.second);
  all[*allow.begin()]=*unused.begin();

  int tests; scanf("%d\n",&tests); for (int test=1; test<=tests; test++){
    fgets(buf,sizeof buf,stdin);
    for (int i=0; buf[i]!='\n'; i++) if (buf[i]>='a' and buf[i]<='z') buf[i]=all[buf[i]]; else if (buf[i]=='\r') buf[i]='\n', buf[i+1]=0;
    printf("Case #%d: %s",test,buf);
  }
}
