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

string solve(double C, double F, double X)
{
	double ultraSpeed = F * X / C;
	double dFarmCount = floor((ultraSpeed - 2) / F);
	int farmCount = max(int(dFarmCount + 0.5), 0);

	double time = 0;
	for (int i = 0; i < farmCount; i++) {
		time += C / (2 + F * i);
	}
	time += X / (2 + F * farmCount);
	char answer[50];
	sprintf(answer, "%.7f", time);
	return answer;
}

void preprocess(){}

void readinput(double &C, double &F, double &X)
{
	cin>>C>>F>>X;
}

vs getoutput()
{
	double C, F, X;
	readinput(C, F, X);
	string answer = solve(C, F, X);
	return vs(1, answer);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	freopen("test\\B-small-attempt0.in", "r", stdin);freopen("test\\B-small-attempt0.out", "w", stdout);
//	freopen("test\\B-large.in", "r", stdin);freopen("test\\B-large.out", "w", stdout);
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