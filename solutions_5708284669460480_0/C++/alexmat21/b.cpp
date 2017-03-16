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

int g,h,s;
int a[2][26];
int k[2];
int b[100];
string ss[2];

int rek(int n){
if (n<s){
	FOR(i,k[0]){
		b[n]=ss[0][i];
		rek(n+1);
		}
	}	
else{
	h++;
	for (int j=0; j<s; j++){
		int i=j;
		while (i<s && i-j<k[1] && b[i]==ss[1][i-j])
			i++;
		if (i-j==k[1]){
			g++;
			}
		}
	}
}

int main (){
int t111;
cin >> t111;

for (int i111=0 ; i111<t111; i111++){
	memset(a,0,sizeof a);
	cin >> k[0] >> k[1] >> s;
	FOR(i,2){
		cin >> ss[i];
		FOR (j,k[i]){
			a[i][ss[i][j]-65]++;
			}
		}
	int t=1;
	FOR(i,26){
		if (a[0][i]==0 && a[1][i]>0)
			t=0;	
		}
	if (s<k[1])
		t=0;
	double r;
	if (t==1){
		int m=0;
		for (int j=1; j<k[1]; j++){
			int i=j;
			while (i<k[1] && ss[1][i]==ss[1][i-j])
				i++;
			if (i==k[1]){
				m=j;
				break;
				}
			}
		if (m>0)
			t=(s-(k[1]-m))/m;
		else{
			m=k[1];
			t=s/m;
			}
		g=0;
		h=0;
		r=0;
		rek(0);
		r=(double)g/h;
		//cout << g << ' ' << h << ' ' << t << ' ' << r << endl;
		r=t-r;
		}
	else{
		r=t;}
	cout << "Case #"<< i111 +1 << ": " <<setprecision(10)<< r<< endl;
	}
return 0;
}
