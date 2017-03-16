#include <iostream>
#include <math.h>

using namespace std;

int t;
int n, j;
bool a[35];
//bool b[20];
//bool res[20];

long long sqrtbase[11] = {
	0,0,65536,43046721,4294967296,152587890625,2821109907456,33232930569601,281474976710656,1853020188851841,10000000000000000
};

struct mybignum
{
	unsigned long long a[8];
	mybignum () {
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		a[4] = 0;
		a[5] = 0;
		a[6] = 0;
		a[7] = 0;
	}
};

void output(mybignum n) {
	int i = 4;
	while(i >= 0 && n.a[i] == 0) i--;
	cout << n.a[i];
	i--;
	for (; i >= 0; --i)
	{
		cout.width(10);
		cout.fill('0');
		cout << n.a[i];
	}
}

mybignum myadd(mybignum x, mybignum y) 
{
	mybignum ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.a[i] += (x.a[i] + y.a[i]) % 10000000000;
		ans.a[i + 1] += (x.a[i] + y.a[i]) / 10000000000;
	}
	return ans;
}

mybignum mymulti(mybignum x, long long y)
{
	mybignum ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.a[i] = x.a[i] * y;
	}
	for (int i = 0; i < 4; ++i)
	{
		ans.a[i+1] += ans.a[i] / 10000000000;
		ans.a[i] = ans.a[i] % 10000000000;
	}
	return ans;
}

long long mymod(mybignum x, long long y)
{
	long long ans = 0;
	for (int i = 4; i >= 0; --i)
	{
		ans = ans * (10000000000 % y);
		ans %= y;
		ans += (x.a[i] % y);
		ans %= y;
	}
	return ans;
}

mybignum myp(long long a, long long n)
{
	mybignum ans;
	ans.a[0] = 1;
	for (long long i = 0; i < n; ++i)
		ans = mymulti(ans, a);
	return ans;
}

mybignum base(int b) {
	mybignum ans;
	//cout << "function base starts" << endl;
	for (int i = 0; i < n; ++i)
	{
		ans = myadd(ans, mymulti(myp(b, i), a[i]));
	}
	//cout << "function base ends" << endl;
	return ans;
}

void generate() {
	int tmp = 1;
	while(tmp < n - 1 && a[tmp] == 1) {
		a[tmp] = 0;
		tmp ++;
	}
	a[tmp] = 1;
}

int main(int argc, char const *argv[])
{
	cin >> t;
	cin >> n >> j;

	cout << "Case #" << 1 << ": " << endl;
	a[0] = 1;
	a[n-1] = 1;

	bool jcb, flag;
	mybignum tmp;
	long long divs[11];
	while (j>0)
	{
		jcb = 1;
		//cout << "Debug 1" << endl;
		for (int i = 2; i < 11; ++i)
		{
			//cout << "Debug 2" << endl;
			tmp = base(i);
			flag = 0;
			for (long long k = 2; k < sqrtbase[2]; ++k)
			{
				//cout << "Debug 3: " << k << endl;
				if (mymod(tmp, k) == 0)
				{
					flag = 1;
					divs[i] = k;
					break;
				}
			}
			if (flag == 0)
			{
				jcb = 0;
				break;
			}
		}
		if (jcb == 1)
		{
			for (int i = n - 1; i >= 0; --i)
			{
				cout<<a[i];
			}
			for (int i = 2; i < 11; ++i)
			{
				cout<<' ' <<divs[i];
			}
			cout<<endl;
			j --;
		}
		generate();
	}

	return 0;
}
