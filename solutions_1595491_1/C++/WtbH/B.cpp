#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>
#include<iomanip>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int N, S, p;
    cin >> N >> S >> p;
    vector<int> scores;
    REP(i, N){
      int tmp;
      cin >> tmp;
      if(tmp > 0) scores.push_back(tmp);
    }
    sort(ALL(scores));
    printf("Case #%d: ", case_no+1);
    if(p == 0){
      printf("%d\n", N);
    }else if (p == 1){
      printf("%d\n", (int)scores.size());
    }else{
      int ans(0);
      int atleast = p * 3 - 4;
      FOR_EACH(s, scores){
	if(*s < atleast) continue;
	if(*s > (p-1)*3) {
	  ans++;
	  continue;
	}
	if(S > 0){
	  S--;
	  ans += 1;
	}
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
