#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back
#define fi first
#define se second

const int INF = 1000000000;

int n,m,r;
string s,t;
void input(){
	cin>>n>>m>>r;
	cin>>s>>t;
}

/*
1
6 2 2
GOOGLE
GO

*/

typedef pair<double, double> pdd;

pdd saiki(vector<char> dat, int depth){
	pdd ret;
	if(depth==r){
		int cnt = 0;
		rep(i,dat.size()-m+1){
			bool ok = true;
			rep(j,m){
				if(dat[i+j]!=t[j])ok=false;
			}
			if(ok)cnt++;
		}
		double per = 1;
		rep(i,r)per/=n;
		ret = pdd(cnt, per*cnt);
	}else{
		rep(i,n){
			dat[depth] = s[i];
			pdd res = saiki(dat, depth+1);
			ret.fi = max(res.fi, ret.fi);
			ret.se += res.se;
			dat[depth] = '*';
		}
	}
	
	//rep(i,dat.size())printf("%c",dat[i]);printf(" : %.3lf %.3lf\n",ret.fi, ret.se);
	
	return ret;
}

double solve(){
	if(n>7 || m>7)return -1;
	
	vector<char> dat(r);
	rep(i,r)dat[i]='*';
	pdd res = saiki(dat, 0);
	return res.fi-res.se;
}


int main(){
	int T;
	cin>>T;
	reps(i,1,T+1){
		input();
		printf("Case #%d: %.10lf\n",i, solve());
	}
}