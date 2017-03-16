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

int already[2000001];
int base10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    memset(already, -1, sizeof(already));
    string As, Bs;
    cin >> As >> Bs;
    int len = As.length();
    int A(atoi(As.c_str())), B(atoi(Bs.c_str()));
    int ans(0);
    for(int x = A; x < B; x++){
      FOR(i, 1, len){
	if(x / base10[i-1] % 10 == 0)continue;
	int toHead = x % base10[i];
	int tail = x / base10[i];
	int rot = toHead * base10[len - i] + tail;
	if(x < rot && rot <= B && already[rot] != x){
	  already[rot] = x;
	  ans++;
	}
      }
    }
    printf("Case #%d: %d\n", case_no+1, ans);
  }
  return 0;
}
