#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int tc;
#define printg tc++, printf("Case #%d: ",tc), printf
#define gout tc++, printf("Case #%d: ",tc), cout
#define INF (1<<29)
	
string s;
string t;
int K, L, S;

int repeat = 0;

float probs[30];

float f(int piv, int N) {
	if (N == 0)
		return 1;
	
	if (piv + N < L)
		return 0;
		
	float ret = 0;
	
	// last char
	if (piv == L-1) {
		ret =	probs[t[piv] - 'A'] * (1 + (N>1?f(repeat, N - 1):0)) + 
				(1 - probs[t[piv] - 'A']) * (N>1?f(repeat, N - 1):0);
	}
	else
		ret = probs[t[piv] - 'A'] * f(piv+1, N - 1) + 
			  (1 - probs[t[piv] - 'A']) * f(0, N - 1);
			
	cout << N << " " << ret << endl;
	return ret;
}

void solve() {
	float ret;
	
	scanf("%d %d %d", &K, &L, &S);
	cin >> s;
	cin >> t;
	
	REP(i, 30)	probs[i] = 0;
	REP(i, K)	probs[s[i] - 'A']++;
	REP(i, 30)	probs[i] /= K;
	
	int i = L-1;
	bool found = false;
	for (; i > 0; --i) {
		found = true;
		for (int j = 0; j < i; ++j) {
			if (s[j] != s[L - i + j]){
				found = false;
				break;
			}
		}
		
		if (found) {
			repeat = i;
			break;
		}
	}
	gout << f(0, S) << endl;
}
	
int main(void){
	int T;
	
	scanf("%d", &T);
	
	REP(i, T)
		solve();
	return 0;
}