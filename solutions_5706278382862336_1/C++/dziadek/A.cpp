#include<iostream>
#include<sstream>
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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else
		return gcd(b,a%b);
}

bool check(ll a, ll b, int level){
	ll d = gcd(a,b);

	a /= d;
	b /= d;

	ll t = b;
	while(t%2 == 0) t /=2;

	if(t != 1) return false;
	if(b>(1LL<<level)) return false;

	return true;
}

void testcase(){
	string s;
	ll P,Q;

	cin >> s;
	stringstream w;
	w << s;

	char c;
	w >> P >> c >> Q;

	if(!check(P,Q,40)){
		cout << "Impossible";
		return;
	}

	ll p,q;
	p = P / gcd(P,Q);
	q = Q / gcd(P,Q);

	FOR(i,1,40){
		ll a = 2*p - q;
		if(a>=0){
			if(check(a,q,40-i)){
				cout << i;
				return;
			}
		}
		q /= 2;
	}
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

