#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#define maxn 101000
using namespace std;

typedef long long ll;

pair<ll,int> b[1100000];
ll a[510];
int two[30];
int n;
void out(int x){
	vector<ll> v;
	v.clear();
	for(int i=0;i<n;++i){
		if(x&two[i])v.push_back(a[i]);
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i];
		if(i+1==v.size())cout<<endl;else cout<<" ";
	}
}

void solve(){
	cin>>n;
	int i,j;
	for(i=0;i<n;++i)cin>>a[i];
	two[0]=1;
	for(i=1;i<=20;++i)two[i]=two[i-1]<<1;
	for(i=1;i<two[20];++i){
		b[i].first=0;b[i].second=i;
		for(j=0;j<n;++j)if(two[j]&i)b[i].first+=a[j];
	}
	sort(&b[1],&b[two[20]]);
	for(i=1;i+1<two[20];++i)if(b[i].first==b[i+1].first){
		out(b[i].second);
		out(b[i+1].second);
		return;
	}
	cout<<"Impossible"<<endl;
}

int main(){
	int t,i;
	ios::sync_with_stdio(false);
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<":"<<endl;
		solve();
	}
	return 0;
}