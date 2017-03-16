#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define repm(i, j, k) for(int i = j; i >= k; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mp make_pair
typedef long long ll;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string ans(string s){
	if(s=="")
	return s;
	int len=s.length();
	char mxm=s[0];
	int mxmid=0;
	rep(i,1,len-1){
		if(s[i]>=mxm){
			mxm=s[i];
			mxmid=i;
		}
	}
	string subs=s.substr(0,mxmid);
	int anotherlen=len-mxmid-1;
	string tmp="";
	tmp+=mxm;
	return tmp+ans(subs)+s.substr(mxmid+1,anotherlen);
}
int T;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("ans","w",stdout);
	cin>>T;
	rep(i,1,T){
		string tmp;
		cin>>tmp;
		cout<<"Case #"<<i<<": "<<ans(tmp)<<endl;
	}
}
