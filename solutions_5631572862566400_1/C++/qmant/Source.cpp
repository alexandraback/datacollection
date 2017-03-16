#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <iomanip>
#define ll long long
#define itn int
#define eps 1e-10
#define mp make_pair
#define pb push_back
#define inf 1e9 
#define vi vector<itn>
#define vvi vector<vi>
#define vii vector<pair<itn,itn> >
#define vvii vector<vii>
#define itn long long
using namespace std;

int qwert;
int glans;
vector<int> glus;

void rek(int ch, int lch, vector<int> &a,vector<int> &us,int gl)
{
	us[ch] = gl;
	glus[ch] = 1;
	if (a[ch] == lch)
	{
		glans = max(glans, us[ch]);
		for (int i = 0; i < a.size(); i++)
		{
			if (us[i] == 0)
			{
				rek(i, ch, a, us,gl+1);
			}
		}
	}
	else
	{
		if (us[a[ch]] == 0)
		{
			rek(a[ch], ch, a, us,gl+1);
		}
		else
		{
			glans = max(glans, us[ch] - us[a[ch]]+1);
		}
	}
	//us[ch] = 0;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
#endif
	/*cout << 100 << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << 1000 << endl;
		for (int j = 1; j < 501; j++)
		{
			cout << 2 * j << ' ' << 2 * j - 1 << ' ';
		}
		cout << endl;
	}
	return 0;*/
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	
	itn qw;
	cin >> qw;
	for (int i = 0; i < qw; i++)
	{
		glans = 0;
		int n;
		cin >> n;
		glus.assign(n, 0);
		vector<int> a(n);
		for (int q = 0; q < n; q++)
		{
			cin >> a[q];
			a[q]--;
		}
		int ans = 0;
		vector<int> used(n, 0);
		for (int q = 0; q < n; q++)
		{
			used.assign(n,0);
			if (glus[q]==0)
			rek(q, -1, a, used,1);
		}



		cout << "Case #" << i + 1 << ": " << glans << endl;
	}


	return 0;
}