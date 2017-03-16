#include <iostream>
#include <vector>
#include <string>

#define for0(i , N) for(int i = 0; i < (N); i++)
#define pb push_back

using namespace std;

int main()
{
	int kases;
	cin >> kases;
	cout.precision(6);
	cout << fixed;
	for0(kase, kases)
	{
		int A, B;
		cin >> A >> B;
		double p[A];
		for0(a, A)
		{
			cin >> p[a];
			if (a > 0)
				p[a] = p[a] * p[a-1];
			//cout << p[a] << endl;
		}
		double Ex[2 + A];
		int tg = B-A;
		Ex[2 + A - 1] = (tg + 1) * p[A-1] + ( tg + 1 + B+1) * (1 - p[A-1]); //keep typing
		Ex[2 + A - 2] = 2 + B;
		for ( int i = 1; i < A; i++)
		{
			Ex[i-1] = p[A-i-1] * (2 * i + tg + 1) + (1 - p[A - i-1]) * (2 * i + tg + 1 + B  +1);
		}
		Ex[A-1] = A + B + 1;
		double big = Ex[0];
		for0(i, 2+A)
		{
			big = big < Ex[i] ? big : Ex[i];
			//cout << Ex[i] << endl;
		}
		
		cout << "Case #" << kase + 1 << ": " << big << endl;
	}
}
