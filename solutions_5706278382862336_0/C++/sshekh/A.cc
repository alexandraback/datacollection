// Round 1C 2014 problem A
// saurav shekhar
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define INF 2000000000
typedef unsigned int ui;
typedef long long unsigned int llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 100005; 


llu gcd(llu a, llu b)
{
	llu r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool inf_fraq(llu d)
{
	if(!(d & (d-1))) return false;
	else return true;

	while( d >0 && !(d & 1)) {
		d >>=1 ;
	}
	d++;
	while( d >0 && !(d & 1)) {
		d >>=1 ;
	}
	if(d == 1) return true;
	else return false;
}

int main()
{
  ui T,qq;
  unsigned long long P, Q;
  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
	scanf("%llu/%llu", &P, &Q);

	llu g = gcd(P,Q);
	P /= g;
	Q /= g;

	if(inf_fraq(Q)) {
		cout << "impossible\n";
	} else {
		llu x = 1;
		while(P < Q) {
			x++;
			P <<= 1;
		}
		cout << x-1 << "\n";
	}
  }
	
  return 0;
}
