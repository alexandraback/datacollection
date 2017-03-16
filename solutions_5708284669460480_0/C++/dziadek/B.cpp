#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include <iomanip>
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

int sum,counter,maxi;
int k,l,s;
string K,L;
char word[10];

void go(int n){
	if(n == s){
		++counter;
		int tmp = 0;
		FOR(i,0,s-L.length()){
			bool ok = true;
			REP(j,L.length())
				if(word[i+j] != L[j]) ok = false;
			if(ok) ++tmp;;
		}
		maxi = max(maxi,tmp);
		sum += tmp;
		return;
	}

	REP(i,K.length()){
		word[n] = K[i];
		go(n+1);
	}
}

void testcase(){
	cin >> k >> l >> s;
	cin >> K >> L;
	counter = 0;
	sum = 0;
	maxi = 0;
	go(0);
	cout << setprecision(9) << (double)maxi - (double)sum / counter;
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
