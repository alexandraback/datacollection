#include <iostream>
#include <algorithm>

using namespace std;

int s[200];
int ss[200];
double t[101];

void process()
{
	int n;
	cin >> n;
	double sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		sum += s[i];
		ss[i] = s[i];
	}
	double k = sum*2;
	int ex = 0;
	sort(ss, ss+n, greater<int>());
	for(int i = 0; i < n; i++)
	{
		double p = k / (n-ex);
		if( ss[i] >= p )
		{
			t[ss[i]] = 0;
			ex++;
			k -= ss[i];
		}
		else
			t[ss[i]] = (p - ss[i]) / sum * 100;
	}
	for(int i = 0; i < n; i++)
		printf("%.6lf ", t[s[i]]);
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i+1);
		process();
	}
}
