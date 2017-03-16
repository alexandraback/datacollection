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

long long gcd(long long a, long long b){
	long long c;
	while (b!=0){
		c=a%b;
		a=b;
		b=c;
		}
	return a;
	}


int main (){
int t111;
cin >> t111;
string s;

for (int i111=0 ; i111<t111; i111++){
	long long p,q;
	p=0;
	q=0;
	cin >> s;
	int i=0;
	while (s[i]!='/'){
		p=p*10+(s[i]-48);
		i++;
		}
	i++;
	while (i<s.length()){
		q=q*10+(s[i]-48);
		i++;
		}
	//cout << q << " " << p << endl;
	long long d=gcd(p,q);
	p=p/d;
	q=q/d;
	int u=1;
	int n=0;
	int n0=-1;
	long long t=1;
	//cout << t << " " << q << " " << p << endl;
	while (t<q){
		//cout << t << " " << q << " " << p << endl;
		t=t*2;
		n++;
		if (t>q)
			u=0;
		else if (t==q){
			t=1;
			while (2*t<=p){
				t=t*2;
				n--;
				}
			break;
			}
		}
	if (u)
	cout << "Case #"<< i111 +1 << ": " << n<< endl;
	else
		cout << "Case #"<< i111 +1 << ": impossible"<< endl;
	}
return 0;
}
