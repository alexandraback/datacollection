#include<iostream>

using namespace std;

int sti(string s)
{
	int x = 0;
	for (int i = 0; i < s.size(); i++)
	{
		x *= 10;
		x += s[i] - '0';
	}
	return x;
}

int pow[8];

int main()
{
	ios_base::sync_with_stdio(0);
	pow[0] = 1;
	for (int i = 1; i < 8; i++) pow[i] = 10 * pow[i - 1];
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		string A, B;
		cin >> A >> B;
		int diff = 1000000;
		int mina = 1000000;
		int minb = 1000000;
		string A2, B2;
		int q = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '?') q++;
			if (B[i] == '?') q++;
		}
		
		for (int i = 0; i < pow[q]; i++)
		{
			string A1 = A, B1 = B;
			int l = 0;
			for (int j = 0; j < A.size(); j++)
			{
				if (A1[j] == '?')
				{
					int c = (i % pow[l + 1]) / pow[l];
					l++;
					A1[j] = c + '0';
				}
				
				if (B1[j] == '?')
				{
					int c = (i % pow[l + 1]) / pow[l];
					l++;
					B1[j] = c + '0';
				}
			}
			int a = sti(A1);
			int b = sti(B1);
			int d = a - b >= 0 ? a - b : b - a;
			//cout << a << " " << b << " " << d << "\n";
			if (d > diff) continue;
			else if (d < diff)
			{
				diff = d;
				mina = a;
				minb = b;
				A2 = A1;
				B2 = B1;
			}
			else if (a > mina) continue;
			else if (a < mina)
			{
				diff = d;
				mina = a;
				minb = b;
				A2 = A1;
				B2 = B1;
			}
			else if (b > minb) continue;
			else
			{
				diff = d;
				mina = a;
				minb = b;
				A2 = A1;
				B2 = B1;
			}
		}
		cout << "Case #" << t << ": " << A2 << " " << B2 << "\n";
	}
	
	
	
	return 0;
}
