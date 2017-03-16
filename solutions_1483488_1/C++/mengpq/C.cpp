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

const int MAXN=2000001;
const int INF=0x7FFFFFFF;
const double eps=1e-10;
const double pi=acos(-1.0);

int n,m,ca;
string a[MAXN];

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

int check(int value){
	string st=a[value];
	int len=st.size(); st+=st;
	int p=1;
	for (int i=1; i<len; i++) p*=10;
	int temp=0;
	for (int i=1; i<=len; i++) temp=temp*10+(st[i]-'0');
	set<int> ret;
	if (temp>value && temp<=m) ret.insert(temp);
	for (int i=2; i<=len; i++){
		temp=(temp-(st[i-1]-'0')*p)*10+(st[i+len-1]-'0');
		if (temp>value && temp<=m) ret.insert(temp);
	}
	return ret.size();
}

void solve(){
	int ret=0;
	for (int i=n; i<=m; i++) 
        ret+=check(i);
	cout<<ret<<endl;
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>ca;
	for (int i=1; i<=2000000; i++) a[i]=int_to_string(i);
	for (int i=0; i<ca; i++){
		cout<<"Case #"<<i+1<<": ";
		init();
		solve();
	}
	return 0;
}
