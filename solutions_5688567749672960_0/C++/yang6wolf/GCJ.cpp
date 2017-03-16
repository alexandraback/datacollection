// GCJ.cpp : 定义控制台应用程序的入口点。
//

// Standing Ovation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<sstream>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; (C); ++I)
#define CASET int ___t, case_n = 1; cin>>___t; while (___t-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
#define SIZE 1000

long long S2N(string src)
{
	long long ans = 0;
	istringstream In(src);
	In >> ans;

	return ans;
}

long long S2N(char src)
{
	string Temp;
	Temp += src;
	return S2N(Temp);
}

string N2S(long long src)
{
	string ans = "";
	ostringstream Out;
	Out << src;
	ans = Out.str();

	return ans;
}

int nData[1000050];

/*
int GetTimes(int n)
{
	if (n<=21)
	{
		return n;
	}

	
	string strOri = N2S(n);
	strOri[strOri.length() - 1] = '1';
	int Temp = S2N(strOri);
	string strTar(strOri.rbegin(), strOri.rend());
	int nTar = S2N(strTar);

	while (Temp >= n || nTar >= n)
	{
		Temp -= 10;
		strOri = N2S(Temp);

		string strTemp(strOri.rbegin(), strOri.rend());
		nTar = S2N(strTemp);
	}
	
	return GetTimes(nTar) + n-Temp+1;
}

*/

void Init()
{
	for (int i = 2; i <= 1000000; i++)
	{
		string strOri = N2S(i);
		string strTar(strOri.rbegin(), strOri.rend());
		int nTar = S2N(strTar);

		if (nTar < i && strTar.find('0')!=0)
		{
			nData[i] = min(nData[i - 1] + 1, nData[nTar] + 1);
		}
		else
		{
			nData[i] = nData[i - 1] + 1;
		}
	}
}
int GetTimes(int n)
{
	return nData[n];
}
int _tmain(){
	freopen("E:\\CodeJam\\a.in", "r", stdin);
	freopen("E:\\CodeJam\\a.out", "w", stdout);

	memset(nData, 0, sizeof(nData));
	nData[1] = 1;
	Init();

	CASET{

		cout << "Case #" << case_n++ << ": ";

		int n;
		cin >> n;

		int ans = GetTimes(n);
		cout << ans<< endl;
	}
	return 0;
}



