#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

void testcase(){
	int A,B,K;
	int tab[1001];

	cin >> A >> B >> K;

	REP(i,1000) tab[i] = 0;

	REP(a,A) REP(b,B){
		tab[a&b]++;
	}

	int res = 0;
	REP(i,K) res += tab[i];
	cout << res;
}

int main(){
	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}
