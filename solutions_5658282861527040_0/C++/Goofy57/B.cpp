#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define pb push_back
#define mp make_pair 

using namespace std;

typedef long long ll; 

int A, B, K; 
int ITS = 1; 

ll stupid(ll a, ll b, ll k)
{
	if (a > 1000 || b > 1000) return 0; 
	ll cnt = 0; 
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((i & j) < k) cnt++; 
		}
	}
	return cnt; 
}

int used[60][10][10][10]; 
ll mas[60][10][10][10];

ll f(int pos, int anyx, int anyy, int anyk)
{
	if (pos == -1) return 0; 
	if (used[pos][anyx][anyy][anyk] == ITS) 
	{
		return mas[pos][anyx][anyy][anyk]; 
	}
	used[pos][anyx][anyy][anyk] = ITS; 
	int bx = 0; 
	if (anyx || ((A >> pos) & 1)) 
	{
		bx = 1; 
	}
	int by = 0; 
	if (anyy || ((B >> pos) & 1)) 
	{
		by = 1; 
	}

	//if (anyk) 
	//{
	//	return mas[pos][anyx][anyy][anyk] = (1LL << (2 * pos + 2)); 
	//}
	int bk = ((K >> pos) & 1) | anyk; 
	
	ll ret = 0; 
	for (int x = 0; x <= bx; x++)
	{
		for (int y = 0; y <= by; y++)
		{
			int bit = (x & y); 
			if (bit > bk) continue; 

			if (pos == 0) 
			{
				ret += (bit <= bk); 
			}
			else
			{
				ret += f(pos - 1, anyx | (x < bx), anyy | (y < by), (bit < bk) | anyk); 
			}
		}
	}
	
	return mas[pos][anyx][anyy][anyk] = ret; 
}

ll clever(ll a, ll b, ll k)
{
	A = a - 1; 
	B = b - 1; 
	K = k - 1; 
	ITS++; 
	return f(31, 0, 0, 0); 
}

void solve(int tc)
{
	cout << "Case #" << tc << ": "; 

	ll a, b, k; 
	cin >> a >> b >> k; 

	//cout << stupid(a, b, k) << " " << clever(a, b, k) << endl; 
	cout << clever(a, b, k) << endl;
}


int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

	int tst = 0;
	cin >> tst; 
	for (int tc = 0; tc < tst; tc++)
	{
		solve(tc + 1); 
	}

	/*for (int i = 1; i < 100; i++)
	{
		cerr << i << endl; 
		for (int j = 1; j < 100; j++)
		{
			for (int k = 1; k < 100; k++)
			{
				if (stupid(i, j, k) != clever(i, j, k)) 
				{
					cout << "WA\n"; 
					cout << i << " " << j << " " << k << endl; 
				}
			}
		}
	}*/


	return 0; 
}