#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;

typedef vector<size_t> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<double> vd;
typedef vector<string> vs;

void extractTwo(ll X, ll &X1, ll &X2)
{
	X2 = 1;
	while(X % 2 == 0) {
		X /= 2;
		X2 *= 2;
	}
	X1 = X;
}

string solve(ll P, ll Q)
{
	ll P1, P2, Q1, Q2;
	extractTwo(P, P1, P2);
	extractTwo(Q, Q1, Q2);
	char answer[50];

	if (P1 % Q1 || Q2 % P2) {
		strcpy(answer, "impossible");
	} else {
		P1 /= Q1;
		Q1 = 1;
		Q2 /= P2;
		P2 = 1;
		size_t result = 0;
		while (P1 < Q2) {
			result ++;
			P1 *= 2;
		}
		sprintf(answer, "%u", result);
	}
	return answer;
}

void preprocess(){}

void readinput(ll &P, ll &Q)
{
	scanf("%lld/%lld", &P, &Q);
}

vs getoutput()
{
	ll P, Q;
	readinput(P, Q);
	string answer = solve(P, Q);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
//	freopen("test\\A-small-attempt0.in", "r", stdin);freopen("test\\A-small-attempt0.out", "w", stdout);
	freopen("test\\A-large.in", "r", stdin);freopen("test\\A-large.out", "w", stdout);
	size_t testcase;
	cin>>testcase;
	preprocess();
	for(size_t i = 1; i <= testcase; i ++)
	{
		cout<<"Case #"<<i<<": ";
		vs answer = getoutput();
		for(size_t j = 0; j < answer.size(); j ++)
			cout<<answer[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}