#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#define maxl 1000000000
#define maxn 600
#define maxm 10000
using namespace std;



void solve(){
	unsigned long long r,t,small,big,mid;
	cin>>r>>t;
	small=1;big=t;
	while(small<big){
		mid=(small+big)/2+1;
		if(t/mid<r+r+2*mid-1)big=mid-1;else small=mid;
	}
	cout<<small<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}