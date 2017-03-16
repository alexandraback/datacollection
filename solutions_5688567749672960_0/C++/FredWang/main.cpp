#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int q[10000010], g[10000010], qh, qt, f[10000010];
long long rev(long long n)
{
	vector<int> digi;
	while (1)
	{
		digi.push_back(n % 10);
		n = (n - n % 10) / 10;
		if (n == 0)break;
	}
	long long ans = 0;
	for (int i = 0; i <digi.size(); ++i)
	{
		ans = ans * 10 + digi[i];
	}
	return ans;
}
long long process_bian(long long n)
{
	vector<int> digi;
	while (1)
	{
		digi.push_back(n % 10);
		n = (n - n % 10) / 10;
		if (n == 0)break;
	}
	long long p = 0;
	for (int i = digi.size()-1; i>=0; --i)
	{
		if (i == 0)digi[0] = 1;
		else if (i < digi.size() / 2)digi[i] = 0;
		else continue;
	}
	for (int i =  digi.size() - 1; i >= 0; --i)
	{
		p = p * 10 + digi[i];
	}
	return p;
}
int main()
{
	memset(f, 10, sizeof(f));
	f[1] = 1;
	g[1] = 0;
	q[++qt] = 1;
	while (qh<qt){
		int x = q[++qh];
		if (x + 1<10000000 && f[x] + 1<f[x + 1]){
			f[x + 1] = f[x] + 1;
			g[x + 1] = x;
			q[++qt] = x + 1;
		}
		if (f[x] + 1<f[rev(x)]){
			f[rev(x)] = f[x] + 1;
			g[rev(x)] = x;
			q[++qt] = rev(x);
		}
	}
	ifstream fin;
	fin.open("C:\\Users\\ty\\Desktop\\codejam2015\\A.in");
	ofstream fout;
	fout.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");

	int T;
	fin >> T;
	for (int i = 0; i < T; ++i)
	{
		int x;
		fin >> x;
		fout << "Case #" << i + 1 << ": " << f[x]<< endl;
	}
	fout.close();
	return 0;
}
