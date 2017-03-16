#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int d[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

long long L,X;
string s,t;
bool v[5];

int change(int a,int b){
	int ok1 = 1, ok2 = 1;
	if(a < 0) ok1 = 0;
	if(b < 0) ok2 = 0;
	a = abs(a), b = abs(b);
	int res = d[a-1][b-1];
	if(ok1 + ok2 == 1) res = -res;
	return res;
}

int main()
{
	freopen("C-large.in","rb",stdin);
	freopen("test.out","wb",stdout);
	int T;scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas){
		cin>>L>>X; s.clear();t.clear();
		cin>>s; t = s + s; t = t + t;t = t + t;
		if(L * X < 3LL){
			cout<<"Case #"<<cas<<": "<<"NO"<<endl;
			continue;
		}
		long long ll = L * X;
		int res = t[0] - 'i' + 2, l = t.size(), i = 0,ret = 0;
		if(ll < (long long)(l)) l = (int)(ll);
		bool ok1 = res == 2,ok2 = false,ok = false;
		if(!ok1){
			for(i=1;i<l;++i){
				res = change(res,t[i]-'i'+2);
				if(res == 2){
					ok1 = true;
					break;
				}
			}
		}
		if(!ok1){
			cout<<"Case #"<<cas<<": "<<"NO"<<endl;
			continue;
		}
		//cout<<"ok1"<<endl;
		if(i<l) res = t[++i] - 'i' + 2,ok2 = res == 3;
		else{
			cout<<"Case #"<<cas<<": "<<"NO"<<endl;
			continue;
		}
		if(!ok2){
			for(i++;i<l;++i){
				res = change(res,t[i] - 'i' + 2);
				if(res == 3){
					ok2 = true;
					break;
				}
			}
		}
		//cout<<i<<endl;
		if(!ok2){
			cout<<"Case #"<<cas<<": "<<"NO"<<endl;
			continue;
		}
		//cout<<"ok2"<<endl;
		if(i<l) res = t[++i] - 'i' + 2;
		else{
			cout<<"Case #"<<cas<<": "<<"NO"<<endl;
			continue;
		}
		for(i++;i<l;++i) res = change(res,t[i] - 'i' + 2);
		//cout<<res<<endl;
		ret = s[0] - 'i' + 2;
		for(i=1;i<s.size();++i) ret = change(ret,s[i] - 'i' + 2);
		int ans = ret;
		if(ll > (long long)(l)){
			X-=8;
			if(X % 4 == 0) ans = 1;
			else if(X % 4 == 1) ans = ret;
			else if(X % 4 == 2) ans = change(ret,ret);
			else ans = change(ret,change(ret,ret));
			res = change(res,ans);
		}
		cout<<"Case #"<<cas<<": "<<(res == 4 ? "YES":"NO")<<endl;
	}
	return 0;
}
