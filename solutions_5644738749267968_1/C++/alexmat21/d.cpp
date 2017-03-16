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
int n;
vector <double> a;
vector <double> b;
double r;
for (int i111=0 ; i111<t111; i111++){
	cin >> n;
	for (int i=0; i<n ; i++){
		cin >> r;
		a.push_back(r);
		}
	for (int i=0; i<n ; i++){
		cin >> r;
		b.push_back(r);
		}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	//for (int i=0; i<n; i++)
	//	cout << a[i] << " " ;
	//cout << endl;
	//for (int i=0; i<n; i++)
	//	cout << b[i] << " " ;
	//cout << endl;
	int y=0;
	for (int i=0; i<n; i++){
		if (a[i]>b[y])
			y++;
		}
	int z=0;
	int j=0;
	for (int i=0; i<n; i++){
		while (j<n && b[j]<a[i])
			j++;
		if (j==n){
			z=n-i;
			break;
			}
		j++;
		}
	cout << "Case #"<< i111 +1 << ": " << y << " " << z << endl;
	a.clear();
	b.clear();
	}
return 0;
}
