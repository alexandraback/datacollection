#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

vector<int> pr;
void primeNum()
{
	pr.push_back(2);
	for (int i = 3; i < 32000; i+= 2)
	{
		int sq = sqrt(i);
		bool bfound = false;
		for (int j = 1; !bfound && j < pr.size() && pr[j] <= sq; j++)
			bfound = (i % pr[j] == 0);
		if (!bfound)
			pr.push_back(i);
	}
}

int toTwo(long long a, long long b)
{
	if (b&(1 << a)) return 1;
	else return 0;
}

vector<vector<int>> bigSt(9);

void learnBigSt()
{

	for (int k = 2; k < 11; k++)
	for (int j = 0; j < pr.size(); j++)
	{ 
		ll x = 1;
		for (int i = 0; i < 31; i++)
			x = (x*k) % pr[j];

		bigSt[k-2].push_back(x);
	}
	
}

int main()
{
	primeNum();
	learnBigSt();

	int n;
	in.open("input.in");
	out.open("c_large.txt");
	cin >> n;
	out << "Case #1:" << endl;

	for (int g = 1; g <= n; g++)
	{
		int q, w;
		cin >> q >> w;
		for (ll i = 1; w > 0; i += 2)
		{
			ll st[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1};
			ll ch[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
			ll ch1[9];

			fj(16)
			{						
				for (int l = 0; l < 9; l++)
				{
					if (i & (1 << j)) ch[l] += st[l];
					st[l] *= (l+2);
				}
			}

			bool isOk = true;
			for (int j = 0; j < 9 && isOk; j++)
			{
				isOk = false;
				for (int l = 0; l < pr.size(); l++)
				{
					if (((ch[j])% pr[l] +bigSt[j][l])%pr[l] == 0)
					{
						ch1[j] = pr[l];
						isOk = true;
						break;
					}
				}
			}

			if (isOk)
			{
				w--;
				out << 1;
				for (int l = q - 2; l > -1; l--)
					out << toTwo(l, i);//(i&(1 << l));
				out << " ";
				for (int l = 0; l < 9; l++)
					out << ch1[l] << " ";
				out << endl;
			}
		}
	}
	out.close();
	in.close();
	return 0;
}
