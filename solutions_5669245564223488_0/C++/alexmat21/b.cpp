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
#define sec second
#define pii pair<int,int>

using namespace std;

vector < vector <int> > v;
vector < vector <int> > u;
int n;
string s[100];
int a[100];
int b[10];
int c[100];
int x[100];
int y[100];
long long m0=1000000007;
int k;


long long rek(int m){
	//cout << m  << " " << k << " $$$$"<< endl;
	//FOR(i,n)
	//	cout << b[i] << " " ;
	//cout << endl;
	if (m==0)
		return 1;
	long long x2=0;
	FOR(i,n){
		//cout << m << " " << i << " " << k << " " << x[i] << " " << y[i] << " " << b[i] << " ££££"<< endl;
		if (b[i]==0 && ( m==n || (k==x[i] && a[x[i]]==1 && (x[i]==y[i] || a[y[i]]==0) ) || (k!=x[i] && a[x[i]]==0 && a[y[i]]==0))){
			//cout << m << " " << i << " " << k << " " << x[i] << " " << y[i] << endl;
			int k1=k;
			b[i]=1;
			if (m!=n && k!=x[i]){
				a[k]=2;
				a[x[i]]=1;
				a[y[i]]=1;
				if (x[i]!=y[i])
					a[x[i]]=2;
				k=y[i];
				x2=(x2+rek(m-1))%m0;
				k=k1;
				a[x[i]]=0;
				a[y[i]]=0;
				a[k]=1;
				}
			else{
			k=y[i];
			a[x[i]]=2;
			a[y[i]]=1;
			x2=(x2+rek(m-1))%m0;
			a[y[i]]=0;
			if (m==n)
				a[x[i]]=0;
			else
				a[x[i]]=1;
			}
			k=k1;
			b[i]=0;
			}
		}
	return x2;
	}

int main (){
int t111;
cin >> t111;

for (int i111=0 ; i111<t111; i111++){
	cin >> n;
	FOR(i,n)
		cin >> s[i];
	FOR(i,100){
		vector <int> v1;
		v.push_back(v1);
		u.push_back(v1);
		a[i]=0;
		c[i]=-1;
		}
	FOR(i,n){
		x[i]=s[i][0];
		y[i]=s[i][s[i].length()-1];
		x[i]-=97;
		y[i]-=97;
		a[x[i]]=1;
		a[y[i]]=1;
		v[y[i]].push_back(i);
		u[x[i]].push_back(i);
		}
	int t=1;
	FOR(i,n){
		int j1=0;
		int s1=s[i].length();
		while (j1<s1 && s[i][j1]==s[i][0])
			j1++;
		int j2=s1-1;
		while (j2>=0 && s[i][j2]==s[i][s1-1])
			j2--;
		int j=j1;
		while (j<=j2){
			if ( a[s[i][j]-97]==1){
				t=0;
				break;
				}
			if ( s[i][0]==s[i][s[i].length()-1]){
				t=0;
				break;
				}
			if (c[s[i][j]-97]!=-1){
				t=0;
				break;
				}
			else{
				int ch=s[i][j];
				c[s[i][j]-97]=i;
				while (j<=j2 && ch==s[i][j])
					j++;
				j--;
				}
			j++;
			}
		}
	if (t==0)
		cout << "Case #"<< i111 +1 << ": " << 0 << endl;
	else{
		memset(b,0,sizeof b);
		memset(a,0,sizeof a);
		long long x1=rek(n);
		k=-1;
		cout << "Case #"<< i111 +1 << ": " << x1 << endl;
		}
	v.clear();
	u.clear();
	}
return 0;
}
