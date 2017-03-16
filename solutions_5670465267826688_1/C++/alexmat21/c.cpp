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

int mult(int x,int y){
int t=1;
if (x<0){
	t=-t;
	x=-x;
	}
if (y<0){
	t=-t;
	y=-y;
	}
if (y==1)
	return t*x;
else if (x==1)
	return t*y;
else if (y==2){
	if (x==2)
		return -t;
	else if (x==3)
		return -t*4;
	else
		return t*3;
	}
else if (y==3){
	if (x==2)
		return t*4;
	else if (x==3)
		return -t;
	else
		return -t*2;
	}
else {
	if (x==2)
		return -t*3;
	else if (x==3)
		return t*2;
	else
		return -t;
	}
}

int main (){
int a[10010];
int al[10010];
int ar[10010];
int t111;
cin >> t111;

for (int i111=0 ; i111<t111; i111++){
	string s;
	long long l,n;
	long long n1,m1,x1,y1,k1,z1,per,p;
	cin >> l >>n;
	cin >> s;
	FOR(i,l){
		if (s[i]=='i')
			a[i+1]=2;
		else if (s[i]=='j')
			a[i+1]=3;
		else
			a[i+1]=4;
		}	
	al[0]=1;
	for(int i=1; i<=l ; i++){
		al[i]=mult(al[i-1],a[i]);
		//cout << i << ' ' << al[i] << endl;
		}
	ar[l]=1;
	for(int i=l-1; i>=0 ; i--)
		ar[i]=mult(a[i+1],ar[i+1]);
	int t=0;
	per=1;
	p=al[l];
	while (p!=1){
		per++;
		p=mult(p,al[l]);
		}
	for (int i=0; i<=l ; i++){
		n1=0;
		x1=1;
		while (n1<per && mult(x1,al[i])!=2){
			n1++;
			x1=mult(x1,al[l]);
			}
		if (n1<per){
			//cout << i <<' ' << n1 << ' ' << x1 << endl;
			for (int j=0; j<=l ; j++){
				m1=0;
				y1=1;
				while (m1<per && mult(ar[j],y1)!=4){
					m1++;
					y1=mult(y1,al[l]);
					}
				if (m1<per){
					//cout << j <<' ' << m1 << ' ' << y1 <<  " !!!!"<< endl;
					k1=0;
					z1=1;
					while (k1<per && mult(mult(ar[i],z1),al[j])!=3){
						k1++;
						z1=mult(z1,al[l]);
						}
					//cout << k1 << ' ' << z1 <<  " $$$"<< endl;
					if (k1<per && (n1+m1+k1+2-n)%per==0){
						if (n1+m1+k1+2<=n ||(i<j && k1==per-1 && n1+m1+1<=n)){
							t=1;
							break;
							}
						}
					}
				}
			}
		if (t)
			break;
		}
	if (t)
		cout << "Case #"<< i111 +1 << ": YES" << endl;
	else
		cout << "Case #"<< i111 +1 << ": NO" << endl;
	}
return 0;
}
