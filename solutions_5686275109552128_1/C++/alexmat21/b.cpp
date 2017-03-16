// Created by alex_mat21. And it works!

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <string> 
#include <iomanip>
#include <cmath>
#include <utility>
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sd second
#define pii pair<int,int>

using namespace std;

int main (){
int a[1001][1001];
for (int i=1; i<=1000; i++){
	FOR(j,i+1)
		a[j][i]=0;
	for(int j=i+1; j<=1000; j++){
		a[j][i]=a[j-1][i]+1;
		for (int k=2; k<=j/2 ; k++)
			a[j][i]=min(a[j][i],a[j-k][i] +a[k][i]+1);
		}
	}

int t111;
cin >> t111;
int d,k,t,m,x;
for (int i111=0 ; i111<t111; i111++){
	m=0;
	vector <int> b;
	cin >> d;
	FOR(i,d){
		cin >> k;
		b.push_back(k);
		m=max(m,k);
		}
	x=m;
	for (int i=1; i<=m; i++){
		t=i;
		FOR(j,d){
			t+=a[b[j]][i];
			//cout << b[j] << ' ' << i << ' ' << a[b[j]][i] << " !!!"<< endl;
			}
		//cout << i << ' ' << t << ' ' << m << endl;
		x=min(t,x);
		}
	cout << "Case #"<< i111 +1 << ": " <<x << endl;
	b.clear();
	}
return 0;
}
