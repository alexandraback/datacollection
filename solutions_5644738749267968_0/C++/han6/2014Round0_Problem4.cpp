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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define loop(i,n) for(int i=0; i<(n); i++)
#define tr(it,c) for(it=(c).begin(); it!=(c).end(); it++)
#define tr2(it1,c,it2,d) for(it1=(c).begin(),it2=(d).begin(); it1!=(c).end(); it1++,it2++)

int getMaxWin(int N, const vd &a, const vd &b)
{
	int j = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] > b[j]) {
			j ++;
			count ++;
		} else {
			continue;
		}
	}
	return count;
}

string solve(int N, vd &a, vd &b)
{
	sort(all(a));
	sort(all(b));
	int aMaxWin = getMaxWin(N, a, b);
	int aMinWin = N - getMaxWin(N, b, a);
	char answer[50];
	sprintf(answer, "%d %d", aMaxWin, aMinWin);
	return answer;
}

void preprocess(){}

void readinput(int &N, vd &a, vd &b)
{
	cin>>N;
	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < N; i++) {
		cin>>b[i];
	}
}

vs getoutput()
{
	int N;
	vd a, b;
	readinput(N, a, b);
	string answer = solve(N, a, b);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	freopen("test\\D-small-attempt0.in", "r", stdin);freopen("test\\D-small-attempt0.out", "w", stdout);
//	freopen("test\\D-large.in", "r", stdin);freopen("test\\D-large.out", "w", stdout);
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