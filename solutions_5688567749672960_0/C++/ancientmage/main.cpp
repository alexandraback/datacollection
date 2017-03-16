#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory.h>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
#define PI 3.1415926535
#define EPS 0.00000001
#define pii pair<int, int>
#define INF 2000000000

//#define DEBUG 41

#ifndef DEBUG

ifstream in("in.txt");
ofstream out("out.txt");

#define cin in
#define cout out

#endif
template<typename T>
void print(int i, T a)
{
	cout << "Case #" << i << ": " << a << "\n";
}


ll a[1234567];

int rev(int a)
{
	stringstream s;
	s << a;
	string t = s.str();
	reverse(t.begin(), t.end());
	return stoi(t);
}

int main()
{
	int n;
	cin >> n;
	a[1] = 1;
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		int tp = q.front();
		q.pop();
		if(a[tp+1] == 0 && tp + 1 <= 1000000)
		{
			a[tp+1] = a[tp]+1;
			q.push(tp+1);
		}
		int rv = rev(tp);
		if(a[rv] == 0 && rv <= 1000000)
		{
			a[rv] = a[tp]+1;
			q.push(rv);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		int t;
		cin >> t;
		print(i, a[t]);

	}
	

}