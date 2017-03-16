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

struct pnt{
	int n,w,e,s,dd,dp,ds;
};

int solveOne(){
	vector <pnt> a[680000];
	int wall[4000];
	memset(wall,0,sizeof(wall));
	int ans=0;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		pnt t;
		int sd;
		cin>>sd>>t.n>>t.w>>t.e>>t.s>>t.dd>>t.dp>>t.ds;
		t.w++;
		a[sd].push_back(t);
	}
	for (int i=0;i<680000;i++){
		for (int j=0;j<a[i].size();j++){
			for (int k=a[i][j].w;k<=a[i][j].e;k++){
				if (wall[2000+k]<a[i][j].s){
					ans++;
					break;
				}
			}
		}
		for (int j=0;j<a[i].size();j++){
			for (int k=a[i][j].w;k<=a[i][j].e;k++){
				wall[2000+k]=max(wall[2000+k],a[i][j].s);
			}
			a[i][j].w+=a[i][j].dp;
			a[i][j].e+=a[i][j].dp;
			a[i][j].s+=a[i][j].ds;
			a[i][j].n--;
			if (a[i][j].n>0){
				a[i+a[i][j].dd].push_back(a[i][j]);
			}
		}
		a[i].clear();
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