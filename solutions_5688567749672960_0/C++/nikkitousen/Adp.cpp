#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

int N;
int mem[1000100];

int flip(int n) {
	int res = 0;
	while(n > 0) {
		res = res*10 + (n%10);
		n /= 10;
	}
	return res;
}

int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
   	cin >> N;
   	
    mem[1] = 1;
    FOR(n, 2, N+1) {
      mem[n] = mem[n-1];
      if(flip(n) < n && flip(flip(n)) == n) mem[n] = min(mem[n], mem[flip(n)]);
      mem[n]++;
    }
    
    cout << mem[N] << endl;
   	
  }
}
