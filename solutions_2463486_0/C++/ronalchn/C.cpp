#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>

using namespace std;

#define NUM 10000001

int ans[NUM]={};

char line[100];
long long sqrta(long long v) {
  long long ans=(long long)ceil(sqrt(double(v)));
  while (ans*ans<v) ans++;
  return ans;
}
long long sqrtb(long long v) {
  long long ans=(long long)floor(sqrt(double(v)));
  while (ans*ans>v) ans--;
  return ans;
}

int main() {
  ans[0]=1;
  int p10[10]={1};
  for (int i=1;i<10;i++) p10[i]=p10[i-1]*10;
  for (int j=1;j<=7;j++) {
    int l=(j+1)/2;
    for (int i=p10[l-1];i<p10[l];i++) {
      int val=0;
      for (int k=j-j/2-j/2;k<(j+1)/2;k++) {
	val*=10;
	val+=i/p10[k]%10;
      }
      val+=i*p10[j/2];
      //clog << val << endl;
      long long v2 = val;
      v2*=v2;
      sprintf(line,"%lld",v2);
      int sz=strlen(line);
      bool good=true;
      for (int i=0;i<sz/2;i++) if (line[i]!=line[sz-1-i]) {good=false;break;}
      if (good) {
	ans[val]=1;
	//clog << val << "=" << v2 << endl;
      }
    }
  }
  for (int i=1;i<NUM;i++) {
    ans[i]+=ans[i-1];
  }
  int N;
  cin >> N;
  for (int n=1;n<=N;n++) {
    long long A, B;
    cin >> A >> B;
    printf("Case #%d: %d\n", n, ans[sqrtb(B)]-ans[sqrta(A)-1]);
  }
  return 0;
}


