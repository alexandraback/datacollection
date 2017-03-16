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
#define inf 9223372036854775807L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 1000005
#define EPS 1e-9
#define par pair<int,int>
using namespace std;
int T[maxn],n,tt;
int rev(int num){
	int ans = 0;
	while(num){
		ans*=10;
		ans+=num%10;
		num/=10;
	}
	return ans;
}
void calc(){
	memset(T,1,sizeof(T));
	T[1] = 1;
	queue<int> q;
	q.push(1);
	while(q.size()){
		int x = q.front();q.pop();
		if(x+1 < maxn && T[x+1] > T[x]+1){
			T[x+1] = T[x]+1;
			q.push(x+1);
		}
		int y = rev(x);
		if(y < maxn && T[y] > T[x]+1){
			T[y] = T[x]+1;
			q.push(y);
		}
	}
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>tt;
	calc();
	for(int w = 1;w<=tt;w++){
		cin>>n;
		printf("Case #%d: %d\n",w,T[n]);
	}
	return 0;
}
