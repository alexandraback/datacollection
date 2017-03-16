//============================================================================
// Name        : code.cpp
// Author      : vlade087
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<sstream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#include <complex>
#include <numeric>
#include<list>
#include<deque>
#include <stdlib.h>
#define printnVector(R) cout<<R.size()<<endl;for(int i =0;i<R.size();i++) cout<<R[i]<<" ";
#define mod 1000000007
#define inf 200000000000000L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 205
#define EPS 1e-9
#define par pair<int,int>
using namespace std;
int n,m,k,tt,d,x,y,P,t,A[maxn][maxn],r,C[maxn],cc,R[maxn],a,b,c;
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	cin>>tt;
	for(int w = 1;w<=tt;w++)
	{
		cin>>a>>b>>c;
		r = 0;
		for(int i = 0; i < a;i++)
			for(int j = 0;j < b;j++)
			{
				if((i & j) < c) r++;
			}
		printf("Case #%d: %d\n",w,r);
	}
	return 0;
}
