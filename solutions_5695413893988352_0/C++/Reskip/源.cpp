#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

char datac[19];
char dataj[19];
long long  kc, kj, ansc, ansj;

void get(int i)
{
	if (i == 18)
	{
		sscanf(datac, "%lld", &kc);
		sscanf(dataj, "%lld", &kj);
		if (abs(kc - kj) < abs(ansc - ansj))
		{
			ansc = kc;
			ansj = kj;
		}
		return;
	}
	if (datac[i] == '?'&&dataj[i] == '?')
	{
		datac[i] = '0';
		dataj[i] = '0';
		get(i + 1);
		datac[i] = '0';
		dataj[i] = '1';
		get(i + 1);
		datac[i] = '0';
		dataj[i] = '9';
		get(i + 1);
		datac[i] = '1';
		dataj[i] = '0';
		get(i + 1);
		datac[i] = '9';
		dataj[i] = '0';
		get(i + 1);
		datac[i] = '?';
		dataj[i] = '?';
	}
	else if (datac[i] == '?')
	{
		datac[i] = '0';
		get(i + 1);
		if (dataj[i] > '0')
		{
			datac[i] = dataj[i] - 1;
			get(i + 1);
		}
		datac[i] = dataj[i];
		get(i + 1);
		if (dataj[i] < '9')
		{
			datac[i] = dataj[i] + 1;
			get(i + 1);
		}
		datac[i] = '9';
		get(i + 1);
		datac[i] = '?';
	}
	else if (dataj[i] == '?')
	{
		dataj[i] = '0';
		get(i + 1);
		if (datac[i] > '0')
		{
			dataj[i] = datac[i] - 1;
			get(i + 1);
		}
		dataj[i] = datac[i];
		get(i + 1);
		if (datac[i] < '9')
		{
			dataj[i] = datac[i] + 1;
			get(i + 1);
		}
		dataj[i] = '9';
		get(i + 1);
		dataj[i] = '?';
	}
	else
	get(i + 1);
}

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int t;
	cin >> t;
	int ss = 1;
	while (t--)
	{
		ansc = 0;
		ansj = 1e18;
		cout << "Case #" << ss << ": ";
		ss++;
		int len1, len2;
		for (size_t i = 0; i < 18; i++)
		{
			datac[i] = '0';
			dataj[i] = '0';
		}

		char temp[20];
		cin >> temp;
		len1 = strlen(temp);
		strcpy(datac + 18 - len1, temp);

		cin >> temp;
		len2 = strlen(temp);
		strcpy(dataj + 18 - len2, temp);

		get(0);
		
		int len3, len4;
		len3 = 1;
		len4 = 1;
		while (pow(10, len3)<=ansc)
		{
			len3++;
		}
		while (pow(10, len4)<=ansj)
		{
			len4++;
		}
		for (size_t i = 0; i < len1-len3; i++)
		{
			cout << "0";
		}
		cout << ansc;
		cout << " ";
		for (size_t i = 0; i < len2 - len4; i++)
		{
			cout << "0";
		}
		cout << ansj;
		cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
}