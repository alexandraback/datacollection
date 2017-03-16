/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-05-04 01:09:42
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <sstream>
#include <utility>
#include <cctype>
using namespace std;
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi firsst
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 0;
int t, a, b, k;

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d%d%d", &a, &b, &k);
		int cnt = 0;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i & j) < k) {
					cnt++;
				}
		printf("Case #%d: %d\n", cas, cnt);
	}
	return 0;
}

