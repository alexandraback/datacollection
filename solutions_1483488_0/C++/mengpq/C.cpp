#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-10;
const double pi=acos(-1.0);

int n,m,ca;
string a[10000];

void init(){
	cin>>n>>m;
}

string int_to_string(int value){
	string ret="";
	if (value==0) ret+='0';
	while (value){
		char ch='0'+value%10;
		ret=ch+ret;
		value/=10;
	}
	return ret;
}

void solve(){
	for (int i=n; i<=m; i++) a[i]=int_to_string(i);
	int ret=0;
	for (int i=n; i<=m; i++){
		string st=a[i]+a[i];
		for (int j=i+1; j<=m; j++)
			if (a[i].size()==a[j].size())
				if (st.find(a[j])!=-1) ++ret;
	}
	cout<<ret<<endl;
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>ca;
	for (int i=0; i<ca; i++){
		cout<<"Case #"<<i+1<<": ";
		init();
		solve();
	}
	return 0;
}
