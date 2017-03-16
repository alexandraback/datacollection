// jam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LONGLONG;

int calR(vector<pair<int, LONGLONG>> inputArr)
{
	int nAllsize = inputArr.size();
	map<double, vector<int>> timeMap;
	for (int i = 0; i < inputArr.size(); i++)
	{
		timeMap[(360.0-inputArr[i].first)*inputArr[i].second/360.00].push_back(i);
	}

	map<double, vector<int>> timeMapR;
	while (timeMapR.size() < nAllsize)
	{
		auto bb = timeMap.begin();
		double dTime = bb->first;
		vector<int> nArrT = bb->second;
		timeMapR[dTime] = nArrT;
		timeMap.erase(dTime);
		for (int i = 0; i < nArrT.size(); i++)
		{
			timeMap[dTime+inputArr[nArrT[i]].second].push_back(nArrT[i]);
		}
	}

	set<int> nUseSet;
	set<int> nUseSet2;
	int nPass = 0;
	int nMin = nAllsize;
	for (auto a = timeMapR.begin(); a != timeMapR.end(); ++a)
	{
		int nCur = nPass+nAllsize-nUseSet.size();
		if (nMin > nCur)
		{
			nMin = nCur;
		}
		for (int i = 0; i < a->second.size(); i++)
		{
			if (nUseSet.find(a->second[i]) == nUseSet.end())
			{
				nUseSet.insert(a->second[i]);
			}
			else
			{
				nPass +=1;
			}
		}
	}
	int nCur = nPass+nAllsize-nUseSet.size();
		if (nMin > nCur)
		{
			nMin = nCur;
		}
	
	return nMin;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSizeT;
	cin >> nSizeT;
	for (int i = 0; i < nSizeT; i++)
	{
		vector<pair<int, LONGLONG>> inputArr;
		int nSizeN;
		cin >> nSizeN;
		for (int j = 0; j < nSizeN; j++)
		{
			int di;
			int hi;
			LONGLONG mi;
			cin >> di >> hi >> mi;
			for (int k = 0; k < hi; k++)
			{
				inputArr.push_back(make_pair(di,mi+k));
			}
		}
		string sNote = "Case #";
		cout << sNote << i+1<<": "<<calR(inputArr)<<"\n";
	}
	return 0;
}
