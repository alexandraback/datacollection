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

typedef unsigned long long ull;
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

string solve(const ull r, const ull t)
{
	ull low = 1, high = 1000000000ull;
	while (high - low > 1) {
		ull mid = low + (high - low) / 2;
		ull f1 = 2*r + 2*mid - 1;
		ull f2 = mid;
		ull f = f1 * f2;
		if (f <= t && f / f1 == f2) {
			low = mid;
		} else {
			high = mid;
		}
	}
	char answer[21];
	sprintf(answer, "%llu", low);
	return answer;
}

void preprocess(){}

void readinput(ull &r, ull &t)
{
	cin>>r>>t;
}

vs getoutput()
{
	ull r, t;
	readinput(r, t);
	string answer = solve(r, t);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	freopen("test\\A-small-attempt0.in", "r", stdin);freopen("test\\A-small-attempt0.out", "w", stdout);
//	freopen("test\\A-large.in", "r", stdin);freopen("test\\A-large.out", "w", stdout);
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