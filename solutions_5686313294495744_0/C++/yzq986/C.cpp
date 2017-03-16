#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

const int maxn=1010;

int A[maxn],B[maxn];
struct Node{
	int a,b;
	bool operator<(const Node& rhs)const{
		return A[a]+B[b]<A[rhs.a]+B[rhs.b];
	}
}a[maxn];

map<string,int> mp;
int idxN;
int idx(const string& s){
	if(mp.count(s))return mp[s];
	mp[s]=++idxN;return idxN;
}

int n;

void solve(){
	cin >> n;
	idxN=0;
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	for(int i=1;i<=n;++i){
		string s;
		cin >> s;a[i].a=idx(s);++A[a[i].a];
		cin >> s;a[i].b=idx(s);++B[a[i].b];
	}
	sort(a+1,a+1+n);
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	int res=0;
	for(int i=1;i<=n;++i){
		res+=(A[a[i].a] && B[a[i].b]);
		++A[a[i].a];++B[a[i].b];
	}
	cout << res << endl;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase,i=0;cin >> kase;
	for(int i=1;i<=kase;++i){
		cout << "Case #" << i << ": ";
		solve();
	}
//	for(;;);
	return 0;
}
