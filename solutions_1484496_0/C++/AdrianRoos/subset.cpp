#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
int T,N,s[600], prefix[600];
map<pair<pair<int, int>, bool>, int> m;

vector<int> result1, result2;


void buildResult(int sum, int n, bool different) {
  if (n<0)
    return;
  pair<pair<int, int>, bool> p = make_pair(make_pair(sum,n),different);
  
  int res = m[p];
  
  if (res == 1)
    buildResult(sum, n - 1, different);
  else if (res == 2)
    buildResult(sum - s[n], n - 1, true);
  else if (res == 3)
    buildResult(sum + s[n], n - 1, true);
  else if (res == -1)
    ;
  else {
    printf("\nFAILED\n");
    exit(-1);
  }
  
  if (res == 2)
    result1.push_back(s[n]);
  if (res == 3)
    result2.push_back(s[n]);
  
}

int canBuild(int sum, int n, bool different) {
  if (n<0)
    return (sum == 0 && different) ? -1 : 0; 
  pair<pair<int, int>, bool> p = make_pair(make_pair(sum,n),different);
  if (m.find(p) != m.end())
    return m[p];
  
  if (n >= 1 && sum > prefix[n] + 1)
    return m[p] = 0; 
    
  if (canBuild(sum, n - 1, different)!=0)
    m[p] = 1;
  else if (canBuild(sum - s[n], n - 1, true)!=0)
    m[p] = 2;
  else if (canBuild(sum + s[n], n - 1, true)!=0)
    m[p] = 3;
  else
    m[p] = 0;
  
  return m[p];
}

int main() {
  scanf("%d", &T);
  for (int ttt=1; ttt<=T; ttt++) {
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
      scanf("%d", s+i);
    }
    sort(s, s+N);
    prefix[0] = s[0];
    for (int i=1; i<N; i++) {
      prefix[i] = prefix[i-1] + s[i];
    }
    
    m.clear();
    result1.clear();
    result2.clear();
    
    if (canBuild(0, N - 1, false) == 0)
      printf("Case #%d:\nImpossible\n", ttt);
    else {
      buildResult(0, N - 1, false);
      printf("Case #%d:\n", ttt);
      for (int i=0; i<result1.size(); i++)
	printf("%d%c", result1[i], (i == result1.size() - 1) ? '\n' : ' ');
      for (int i=0; i<result2.size(); i++)
	printf("%d%c", result2[i], (i == result2.size() - 1) ? '\n' : ' ');
    }
    
  }
}