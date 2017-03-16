#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
bool poly(ll n){
	string s="",t;
	while(n){
		s=s+char('0'+(n%10));
		n/=10;
	}
	t=s;
	reverse(t.begin(),t.end());
	if(t==s)
		return true;
	else return false;
}

int main(){
	//freopen("1.txt","r",stdin);
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-out.txt","w",stdout);
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-out-1.txt","w",stdout);
	vector<ll> a;
	for(ll i=1;i<=10000000;i++)
		if(poly(i))
			if(poly(i*i))
				a.push_back(i*i);
	int T=0;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		ll n,m;
		cin>>n>>m;
		int ans=0;
		for(int i=0;i<a.size();i++)
			if(n<=a[i] && a[i]<=m)
				ans++;
		printf("%d\n",ans);
	}
}