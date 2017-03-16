#include <iostream>
#include <iomanip>

using namespace std;

long double p[100000], mean[100000];

long double min(long double a, long double b)
{
	if (a < b)
		return a;
	return b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	cout << setprecision(12);
	for (int o = 0; o < t; o++)
	{
		cout<<"Case #" << o + 1 <<": ";
		long double a,b;
		long double res;
		cin >> a >> b;
		p[0] = 1;
		for (int i = 1; i <= a; i++)
		{
			cin >> p[i];
			p[i] *= p[i-1]; 
		}
		//p[()a] = 0;
		res = b+2;
		long double keep_t =0.;
		for (int i = 0; i < a; i++)
			mean[i] = 0;
		long double prob = 1;
		for (int i =0; i < a; i++)
			prob *= p[i];
		prob = p[(int)a];
		res = min(res, prob*(b-a+1) + (1-prob)*(2*b - a +2));
		//prob = 1;
	//	cout << p[a-1]<< endl;
		for (int i = 1; i <= a; i++)
		{
			prob /= p[(int)a-i];
			res = min(res, p[(int)a-i]*(2*i+b-a+1) + (1-p[(int)a-i])*(2*i+2*b - a + 2));
			//cout << i <<"="<< p[i-1]*(2*i+b-a+1) + (1-p[i-1])*(2*i+2*b - a + 2) << endl;
		}
		cout << res << endl;
	}
	return 0;
}