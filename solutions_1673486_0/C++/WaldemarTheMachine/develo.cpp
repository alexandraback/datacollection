// develo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <set>

#pragma comment(linker, "/STACK:67108864")

#define LL long long
#define fr(i,n) for(i=0;i<n;i++)
#define INF (2000000000)
#define FOR(n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset(x,0,sizeof(x))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))

using namespace std;

int a,b;
long double x[100001];
long double best;

int main ()
{
	freopen("input.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int tt = 1;tt<=t;tt++){
		//CODE
		x[0]=1;
		cin >> a >> b;
		best = 2+b;
		for(int i = 1;i<=a;i++){
			cin >> x[i];
			x[i]*=x[i-1];
			//long double l = a-i+x[i]*(b-a+1)+(1-x[i])*(b-a+1+b+2);
			if (a-i+x[i]*(b-i+1)+(1-x[i])*(b-i+1+b+1) < best)
				best =a-i+x[i]*(b-i+1)+(1-x[i])*(b-i+1+b+1);
		}
		//best = max(best,x[a]*(b-a+1)+(1-x[ia])*(b-a+1+b+2));


		//OUTPUT
		cout << "Case #" << tt<<": "<< fixed << setprecision(12) << best<<endl;
	}

	return 0;
}