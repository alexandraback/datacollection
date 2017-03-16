// TestC.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

template <class T>
int MinString(vector <T> &str) 
{
  int i, j, k; 
  vector <T> ss(str.size() << 1); 
  for (i = 0; i < str.size(); i ++) ss[i] = ss[i + str.size()] = str[i]; 
  for (i = k = 0, j = 1; k < str.size() && i < str.size() && j < str.size(); ) { 
    for (k = 0; k < str.size() && ss[i + k] == ss[j + k]; k ++); 
    if (k < str.size()) { 
      if (ss[i + k] > ss[j + k]) 
        i += k + 1; 
      else j += k + 1; 
      if (i == j) j ++; 
    }
  } 
  return i < j ? i : j; 
} 

vector<int> int2vec(int d) {
	static int arr[10];
	int n = 0;
	while(d) {
		arr[n ++] = d % 10;
		d /= 10;
	}
	vector<int> res;
	res.resize(n);
	for(int i = 0; i < n; i ++) {
		res[i] = arr[n-1-i];
	}
	return res;
}


void outputVec(const vector<int> & vec, int startIdx = 0) {
	for(int i = startIdx; i < vec.size(); i ++) {
		printf("%d", vec[i]);
	}
	for(int i = 0; i < startIdx; i ++) {
		printf("%d", vec[i]);
	}
	printf("\n");
}

long long cn2(long long n) {
	return n*(n-1) / 2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	freopen("data.txt", "w", stdout);

	for(int i = 1; i <= 2000000; i ++) {
		vector<int> v = int2vec(i);
		int idx = MinString(v);
		outputVec(v, idx);
	}*/

	freopen("data.txt", "r", stdin);
	static int arr[2000010];
	for(int i = 1; i <= 2000000; i ++) {
		scanf("%d", arr+i);
	}

	freopen("C-large.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int idx=1; idx<=n; idx++) {
		int A, B;
		scanf("%d%d", &A, &B);
		map<int,int> maps;
		for(int i = A; i <= B; i ++) {
			maps[ arr[i] ] ++;
		}
		long long ans = 0;
		for(map<int,int>::iterator iter = maps.begin(); iter != maps.end(); iter ++) {
			ans += cn2(iter->second);
		}
		cout << "Case #" << idx << ": " << ans << endl;
	}

	



	return 0;
}
