#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int T,C=1;
int n,sum;
int v[32];
bool first;
set<int> s;
map<int,int> m;

int main(){

  scanf("%d",&T);
  while(T--){
    printf("Case #%d:\n",C++);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",v+i);

    s.clear(); m.clear();
    for(int i=0;i<(1<<n);i++){
      sum=0;
      for(int j=0;j<n;j++) if(i&(1<<j))
        sum+=v[j];

      if(s.find(sum)!=s.end()){
        first=true;
        for(int j=0;j<n;j++) if(i&(1<<j)){
          if(!first) printf(" "); first=false;
          printf("%d",v[j]);
        }
        printf("\n");
        first=true;
        for(int j=0;j<n;j++) if(m[sum]&(1<<j)){
          if(!first) printf(" "); first=false;
          printf("%d",v[j]);
        }
        printf("\n");
        goto end;
      }
      m[sum]=i;
      s.insert(sum);
    }

    printf("Impossible\n");
    end:;
  }

  return 0;
}
