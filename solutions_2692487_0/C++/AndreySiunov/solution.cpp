#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>
 
#pragma comment(linker, "/STACK:256000000")
 
#define EPS 1e-7
 
const long double PI = 3.1415926535897932384626433832795;
 
using namespace std;
 
int aabs(int a){
	if (a<0) return -a;
	return a;
}

int solveOne(){
	int n;
	int b,a[113];
	cin>>b;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=n;
	if (b==1) return ans;
	for (int i=0;i<n;i++){
		int cr=b;
		int crans=n-i-1;
		for (int j=0;j<=i;j++){
			while (cr<=a[j]){
				crans++;
				cr+=cr-1;
			}
			cr+=a[j];
		}
		ans=min(ans,crans);
	}
	return ans;
}

void solveAll(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solveOne()<<"\n";
		//cout<<"Case #"<<i<<": "; solveOne(); cout<<"\n";
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cout.setf(ios::fixed);
	cout.precision(6);
	solveAll();
	return 0;
}