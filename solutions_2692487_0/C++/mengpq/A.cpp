#include<cctype>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100001;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

#define rep(i,st,ed) for (int i=st; i<ed; i++)

int size,n,a[MAXN];

void init(){
	cin>>size>>n;
	rep(i,1,n+1) cin>>a[i];
	sort(a+1,a+n+1);
}

int solve(){
	int ret=n,delta=0;
	if (size==1){
		return n;
	}
	rep(i,1,n+1){
		while (size<=a[i]){
			size+=size-1;
			++delta;
		}
		size+=a[i];
		ret=min(ret,n-i+delta);
	}
	return ret;
}

int main(){
	freopen("A.out","w",stdout);
	int ca;
	cin>>ca;
	rep(i,0,ca){
		init();
		cout<<"Case #"<<i+1<<": "<<solve()<<endl;
	}
	return 0;
}
