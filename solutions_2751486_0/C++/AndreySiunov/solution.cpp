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

inline bool isVowel(char ch){
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

long long solveOne(){
	string s;
	int k;
	cin>>s>>k;
	int n=s.size();

	int a[1000013];
	int c=0;
	for (int i=0;i<k;i++){
		if (!isVowel(s[i])){
			c++;
		}
	}
	a[0]=c;
	for (int i=k;i<n;i++){
		if (!isVowel(s[i])){
			c++;
		}
		if (!isVowel(s[i-k])){
			c--;
		}
		a[i-k+1]=c;
	}
	int last=-1;
	int lst[1000013];
	for (int i=n-k;i>=0;i--){
		if (a[i]==k){
			last=i;
		}
		lst[i]=last;
	}
	long long ans=0;
	for (int i=0;i<=n-k;i++){
		if (lst[i]<0) break;
		ans+=n-(lst[i]+k-1);
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