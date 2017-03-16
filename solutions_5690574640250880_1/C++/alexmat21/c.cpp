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
#include <iomanip> // za setprecision() !!
#include <cmath> // za abs()
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sec second
#define pii pair<int,int>

using namespace std;

int main (){
int t111;
cin >> t111;
int r,c,m;
char a[50][50];
for (int i111=0 ; i111<t111; i111++){
	cin >> r >> c >> m;
	int m0=m;
	m=r*c-m;
	memset(a,'*',sizeof(a));
	int t=0;
	int u=1;
	int k;
	if (r<c){
		k=r;
		r=c;
		c=k;
		t=1;
		}
	if (c==1){
		for (int i=0; i<m; i++)
			a[0][i]='.';
		}
	else if (c==2){
		if (m==1)
			a[0][0]='.';
		else if (m>=4 && m%2==0){
			m=m/2;
			for (int i=0; i<m; i++){
				a[0][i]='.';
				a[1][i]='.';
				}
			}
		else
			u=0;
		}
	else{
		if (m==1)
			a[0][0]='.';
		else if (m==4){
			a[0][0]='.';
			a[1][0]='.';
			a[0][1]='.';
			a[1][1]='.';
			}
		else if (m==6){
			a[0][0]='.';
			a[1][0]='.';
			a[0][1]='.';
			a[1][1]='.';
			a[2][0]='.';
			a[2][1]='.';
			}
		else if (m>=8){
			if (m>=2*c){
				int m1=m/c;
				int m2=m%c;
				for (int j=0; j<m1 ; j++)
					for (int i=0; i<c; i++)
						a[i][j]='.';
				if (m==2*c+1){
					a[0][2]='.';
					a[1][2]='.';
					a[2][2]='.';
					a[c-1][0]='*';
					a[c-1][1]='*';
					}
				else if (m2==1){
					a[0][m1]='.';
					a[1][m1]='.';
					a[c-1][m1-1]='*';
					}
				else{
					for (int i=0; i<m2; i++)
						a[i][m1]='.';
					}
				}
			else{
				int m1=m/2;
				if (m%2==0){
					for (int i=0; i<m1; i++){
						a[i][0]='.';
						a[i][1]='.';
						}
					}
				else{
					for (int i=0; i<m1-1; i++){
						a[i][0]='.';
						a[i][1]='.';
						}
					a[0][2]='.';
					a[1][2]='.';
					a[2][2]='.';
					}
				}
			}
		else 
			u=0;
		}
	
	cout << "Case #"<< i111 +1 << ":" << endl;//<< " " << r << " " << c << " " << m0 << " " << r*c-m0<< endl;
	if (u==0)
		cout << "Impossible"<< endl;
	else{
		a[0][0]='c';
		if (t==0){
			for (int i=0; i<r; i++){
				for (int j=0 ; j<c ; j++)
					cout << a[j][i];
				cout << endl;	
				}
			}
		else{
			for (int i=0; i<c; i++){
				for (int j=0 ; j<r ; j++)
					cout << a[i][j];
				cout << endl;	
				}
			}
		}
	}
return 0;
}
