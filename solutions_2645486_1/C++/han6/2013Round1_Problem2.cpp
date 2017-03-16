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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define loop(i,n) for(int i=0; i<(n); i++)
#define tr(it,c) for(it=(c).begin(); it!=(c).end(); it++)
#define tr2(it1,c,it2,d) for(it1=(c).begin(),it2=(d).begin(); it1!=(c).end(); it1++,it2++)

ll solvehelper(ll E, ll R, ll N, ll start, ll end, const vi& v, ll starte, ll ende)
{
	if (start == end)
		return 0;
	int maxindex = -1;
	int maxvalue = -1;
	for (int i = (int)start; i < (int)end; i++) {
		if (v[i] > maxvalue) {
			maxindex = i;
			maxvalue = v[i];
		}
	}

	ll gain1;
	ll maxStateE = min((maxindex - start) * R + starte, E);
	if (maxStateE >= E) {
		gain1 = solvehelper(E, R, N, start, maxindex, v, starte, E - R);
	} else {
		gain1 = 0;
	}
	ll maxuse = min((end - maxindex - 1) * R + maxStateE - ende, maxStateE);
	ll gain2 = maxuse * maxvalue;
	ll gain3 = solvehelper(E, R, N, maxindex+1, end, v, maxStateE - maxuse + R, ende);
	return gain1 + gain2 + gain3;
}

string solve(int E, int R, int N, const vi& v)
{
	if (R > E) R = E;
	ll result = solvehelper(E, R, N, 0, N, v, E, 0);
	char answer[21];
	sprintf(answer, "%lld", result);
	return answer;
}

void preprocess(){}

void readinput(int &E, int &R, int &N, vi &v)
{
	cin>>E>>R>>N;
	v.resize(N);
	loop(i, N)
		cin>>v[i];
}

vs getoutput()
{
	int E, R, N;
	vi v;
	readinput(E, R, N, v);
	string answer = solve(E, R, N, v);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
//	freopen("test\\B-small-attempt2.in", "r", stdin);freopen("test\\B-small-attempt2.out", "w", stdout);
	freopen("test\\B-large.in", "r", stdin);freopen("test\\B-large.out", "w", stdout);
	int testcase;
	cin>>testcase;
	preprocess();
	for(int i=1; i<=testcase; i++)
	{
		cout<<"Case #"<<i<<": ";
		vs answer = getoutput();
		loop(j, sz(answer))
			cout<<answer[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}