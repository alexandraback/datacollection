#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<map>
#include<set>

using namespace std;


long long  reverse(long long n)
{
	long long res =  0;

	//if(n % 10 == 0)
		//return n + 1;

	while(n > 0)
	{
		res *= 10;
		res += n%10;
		n/= 10;

	}
	return res;
}



const int nsize = 1000003;


int din[nsize];


void init()
{

	for(int i = 1; i < nsize; i++)
	{
		din[i]  = 10000000;
	}
	din[1] = 1;
	for(int i = 1; i < nsize; i++)
	{
		long long r = reverse(i);
		if(r > nsize)
			continue;
		if(r > i)
		{
			din[r] = min(din[i] + 1, din[r]);
		}
		else
		{
			if(din[i] + 1 < din[r])
			{
				throw;
			}
		}
		din[i + 1] = min(din[i + 1], din[i] + 1);
	}
}


int main()
{
	init();

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{



		long long  n;
		cin >> n;

		int res =  din[n];

		//while(n != 1)
		//{
		//	long long r = reverse(n);
		//	if(r < n)
		//	{
		//		n = r;
		//	}
		//	else
		//	{
		//		n--;
		//	}
		//	res++;

		//}

		//cout << reverse(n);

		printf("Case #%d: %d\n", tt+1, res);
	}


	return 0;

}