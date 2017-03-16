#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dhvan;
bool found;

bool cv[1010];
bool v[1010];
bool ct2[1010];
bool ct[1010];
int tt[1010];
int b[1010];
int a[1010];
int cc[1010];
int n;
void setCircle(int x, int jj)
{
	cv[x] = true;
	tt[x] = jj;
	b[jj] = x;
	if (cv[a[x]] == true)
	{
		found = true;
		int h = tt[a[x]];
		if (jj - h + 1> 2)
		{
			for (int i = h; i <= jj; i++)
			{
				v[b[i]] = true;
				ct[b[i]] = true;
			}
			dhvan = max(dhvan, jj - h + 1);
		}
	} else
		setCircle(a[x], jj + 1);
	cv[x] = false;
}

void whisker(int x, int jj)
{
	if (ct2[a[x]] == true)
		cc[a[x]] = max(cc[a[x]], jj + 1);
	else if (v[a[x]] == false)
		whisker(a[x], jj + 1);
}

int main()
{
	freopen("d:\\C-large.in", "r", stdin);
	freopen("d:\\output.txt", "w", stdout);
	int oo;
	scanf("%d", &oo);
	for (int o = 0; o < oo; o++)
	{
		dhvan = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			a[i]--;
		}
		memset(v, false, sizeof(v));
		memset(ct2, false, sizeof(ct2));
		memset(ct, false, sizeof(ct));
		memset(cv, false, sizeof(cv));
		for (int i = 0; i < n; i++)
			if (i == a[a[i]])
			{
				v[i] = true;
				v[a[i]] = true;
				cc[i] = 0;
				cc[a[i]] = 0;
				ct2[i] = true;
				ct2[a[i]] = true;
				dhvan = max(dhvan, 2);
			}
		//find other circles
		/*for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << endl;*/
		for (int i = 0; i < n; i++)
			if (!ct2[i])
			{
				found = false;
				setCircle(i, 0);
			}
		/*for (int i = 0; i < n; i++)
			cout << v[i] << " ";*/
		//cout << "yes";
		//Find whisker for all ct2
		for (int i = 0; i < n; i++)
			if (!v[i])
				whisker(i, 0);
		int rr = 0;
		for (int i = 0; i < n; i++)
			if (ct2[i] && i < a[i])
			{
				rr += 2 + cc[i] + cc[a[i]];
			}
		dhvan = max(dhvan, rr);
		printf("Case #%d: %d\n", o + 1, dhvan);
	}
	
}