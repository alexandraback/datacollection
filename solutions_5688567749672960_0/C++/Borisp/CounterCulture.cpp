#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;
long long countSameNumDigs(long long n)
{
	long long newN = n;
	vector<int> digs;
	while (n > 0)
	{
		digs.push_back(n % (long long)10);
		n /= (long long)10;
	}
	reverse(digs.begin(), digs.end());
	long long num1 = 0;
	for (int i = (int) digs.size() / 2 - 1; i >= 0; i--)
	{
		num1 = num1 * (long long) 10 + (long long)digs[i];
	}
	bool reversed = false;
	if (num1 > 1)
	{
		num1++;
		reversed = true;
	}
	else {
		num1 = 0;
		reversed = false;
	}
	long long num2 = 0;
	for (int i = (int) digs.size() / 2 ; i < digs.size(); i++)
	{
		num2 = num2 * (long long) 10 + (long long)digs[i];
	}
	if (num2 == 0 && reversed)
		return countSameNumDigs(newN - 1) + 1;
	if (reversed && num2 >= 1 && digs.size() > 1)
		num2--;
		
	return num1 + num2;
}

int fastest[1 << 20];
int reverseNumber(int n)
{
	vector<int> digs;
	while (n > 0)
	{
		digs.push_back(n % (long long)10);
		n /= (long long)10;
	}
	int res = 0;
	for (int i = 0; i < digs.size(); i++)
		res = res * 10 + digs[i];
	return res;
}

void dp()
{
	memset(fastest, -1, sizeof(fastest));
	queue<int> toProcess;
	toProcess.push(1);
	fastest[1] = 1;
	int cur = 0;
	int rev;
	while(!toProcess.empty())
	{
		cur = toProcess.front();
		toProcess.pop();
		if (fastest[cur + 1] == -1)
		{
			if (cur + 1 <= 1000000)
			{
				fastest[cur + 1] = fastest[cur] + 1;
				toProcess.push(cur + 1 );
			}
		}
		rev = reverseNumber(cur);
		if (fastest[rev] == -1)
		{
			if (rev <= 1000000)
			{
				fastest[rev] = fastest[cur] + 1;
				toProcess.push(rev);
			}

		}
	}

}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	//dp();
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		long long n;
		cin >> n;
		long long tmp = 9;
		long long res = 0;
		while (tmp < n)
		{
			res += countSameNumDigs(tmp);
			res++;
			tmp = (tmp * (long long)10 + (long long) 9);
		}
		res += countSameNumDigs(n);
		/*if (res != fastest[n])
		{
			cerr << n << " " << res << " " << fastest[n] << endl;
		}*/
		cout << res << endl;

	}
	return 0;
}
