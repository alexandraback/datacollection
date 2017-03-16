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

int toTwo(int a, int b)
{
	if (b&(1 << a)) return 1;
	else return 0;
}

int main()
{
	primeNum();

	
	int n;
	in.open("input.in");
	out.open("output.txt");
	cin >> n;
	cout << "Case #1:" << endl;

	for (int g = 1; g <= n; g++)
	{
		int q, w;
		cin >> q >> w;
		for (ll i = (1 << q - 1) + 1; w > 0; i += 2)
		{
			ll st[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1};
			ll ch[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
			ll ch1[9];

			fj(q)
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
					if (ch[j] % pr[l] == 0)
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
				for (int l = q - 1; l > -1; l--)
					cout << toTwo(l, i);//(i&(1 << l));
				cout << " ";
				for (int l = 0; l < 9; l++)
					cout << ch1[l] << " ";
				cout << endl;
			}
		}
	}
	out.close();
	in.close();
	return 0;
}
