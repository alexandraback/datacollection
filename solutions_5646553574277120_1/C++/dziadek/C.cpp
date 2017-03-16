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
	int c,d,v;
	cin >> c >> d >> v;

	VI V;
	REP(i,d){
		int a;
		cin >> a;
		V.PB(a);
	}

	sort(ALL(V));

	int res = 0;
	long long sum = 0;

	REP(i,V.size()){
		while(V[i] > sum + 1){
			sum += (long long)c*(sum + 1);
			++res;
		}
		sum += (long long)c*V[i];
	}

	while(sum < v){
		++res;
		sum += (long long)c*(sum + 1);
	}

	cout << res;
}

int main(){
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}
