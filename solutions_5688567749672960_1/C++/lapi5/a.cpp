#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>

using namespace std;

long long only9[20];

int length(long long n)
{
	int ret = 0;
	while(n != 0)
	{
		++ret;
		n /= 10;
	}
	return ret;
}

long long reverse(long long n)
{
	long long ret = 0;
	while(1)
	{
		if(n % 10 == 0)
			n /= 10;
		else break;
	}

	while(n != 0)
	{
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

long long solve(long long n)
{
	long long cnt = 0;
	if(length(n) == 1) return n;

	int len = length(n);
	int l = len / 2;
	int r = (len + 1) / 2;

	long long tmp = 1;
	for(int i = 0; i < r; ++i) tmp *= 10;
	long long right = n % tmp;
	cnt += right - 1;

	long long revn = reverse(n);
	tmp = 1;
	for(int i = 0; i < l; ++i) tmp *= 10;
	long long left = revn % tmp;
	cnt += left - 1;
	if(left != 1) ++cnt;

	cnt += 2;
	cnt += only9[len - 1];

	return cnt;



}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int T;
	in >> T;
	only9[1] = 9;
	for(int i = 2; i < 20; ++i)
	{
		only9[i] = 0;
		int l = i / 2;
		int r = (i + 1) / 2;

		long long tmp = 1;
		for(int j = 0; j < l; ++j) tmp *= 10;
		only9[i] += (tmp - 2);
		tmp = 1;
		++only9[i];
		for(int j = 0; j < r; ++j) tmp *= 10;
		only9[i] += (tmp - 2);
		only9[i] += 2;
		only9[i] += only9[i - 1];
	}

	for(int kase = 1; kase <= T; ++kase)
	{
		long long N;
		in >> N;
		
		int ans;
		if(N % 10 == 0) ans = solve(N-1) + 1;
		else ans = solve(N);	
		
		out << "Case #" << kase << ": " << ans << endl;

	}

	in.close();
	out.close();
	return 0;
}
