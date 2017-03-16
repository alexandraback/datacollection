#include "stdio.h"
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
char s[1000002];
vector<pair<int, int> > pairs;
bool isCons(char c) {
  if (c != 'a' && c != 'e' && c != 'i' && c != 'o'
    && c != 'u') {
    return true;
  }
  return false;
}
long long getAns(vector<pair<int, int> > pairs, int n) {
  long long ans = 0;
  int start = 0;
  for (int k=0; k<pairs.size(); k++) {
    int currentst = pairs[k].first;
    int currentend = pairs[k].second;
    printf("currentst : %d , currentend : %d, stchoice : %d endchoice %d\n", currentst, currentend, 
	   currentst==0 ? 1 : (currentst - start), (n - currentend));
    ans += (currentst==0 ? 1 : (currentst - start)) * (n - currentend);
    start = currentst;
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  for(int x=1; x<=t; x++) {
    int n;
    pairs.clear();
    scanf("%s %d", s, &n);
    int len = strlen(s);
    int counter = 0;
    long long ans = 0;
    int start = -1;
    for(int j = 0; j<len; j++) {
      if (isCons(s[j])) {
	counter++;
	if (counter == n)  {
	  int currentst = j-n+1;
	  int currentend = j;
	  ans +=  (currentst - start) * (len - currentend);
	  start = currentst;
	  //printf("j is %d\n", j);
	  //pairs.push_back(make_pair(j-n+1, j));
	  counter --;
	}
      } else {
	counter = 0;
      }
    }
    printf("Case #%d: %lld\n", x, ans);
  }
}