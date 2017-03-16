#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;




long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

//int  find (long long x, long long y, long long a = 0, long long b = 1, long long c = 1, long long d = 0, int depth = 0) 
//{
//	long long m = a*d+c*c,  n = c*d*2;
//
//
//	if(n > m)
//		return -1;
//
//	if (x == m && y == n)
//		return depth;
//	depth++;
//	if (x * n < y * m)
//		return 'L' + find (x, y, a, b, m, n, depth);
//	else
//		return 'R' + find (x, y, m, n, c, d, depth);
//}

int main()
{

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	long long mas[64];

	mas[0] = 1;
    for (int i = 1; i < 63; ++i)
    {
        mas[i] = mas[i - 1] * 2;
    }

	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{
       // cout << "Case #" << i + 1 << ": ";

       	string s;
		cin >> s;
		long long a = 0, b = 0;
		int i = 0;

		for(i=0;s[i] != 47; i++)
			a = a*10 + s[i] - '0';

		for(i++; i < s.length(); i++)
			b = b*10 + s[i] - '0';


        long long temp = gcd (a,b);
        a /= temp;
        b /= temp;

        bool ok = false;
        for (int j = 0; j < 63; ++j)
        {
            if (b == mas[j])
                ok = true;
        }
        if (!ok || (a == 0))
        {
			printf("Case #%d: %s\n", t, "impossible");
            continue;
        }

        for (int j = 0; j < 63; ++j)
        {
            if (static_cast <long double> (a) / b >= (long double)1.0 / mas[j])
            {
				printf("Case #%d: %d\n", t, j);
                break;
            }
        }

    }
	return 0;
}