#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
const int maxn=30;

int n;
string s0,t0;
string s,t;

LL ans;string res[2];

void calc0(int p){
	string ts=s,tt=t;
	for(int i=0;i<ts.size();++i)if(ts[i]=='?')ts[i]='0';
	for(int i=0;i<tt.size();++i)if(tt[i]=='?')tt[i]='9';
	
	LL x=atoll(ts.c_str()),y=atoll(tt.c_str());
	if(p==0){
		if(x-y<ans || (x-y==ans && (ts<res[p])) || (x-y==ans && ts==res[p] && (tt<res[p^1]))){
			ans=x-y;res[p]=ts;res[p^1]=tt;
		}
	}else{
		if(x-y<ans || (x-y==ans && (tt<res[p^1])) || (x-y==ans && tt==res[p^1] && (ts<res[p]))){
			ans=x-y;res[p]=ts;res[p^1]=tt;
		}
	}
}

void calc(int p){
	for(int i=0;i<s.size();++i){
		if(s[i]=='?'){
			if(t[i]=='?'){
				s[i]='1';t[i]='0';calc0(p);
				s[i]='0';t[i]='0';
			}else{
				if(t[i]!='9'){
					s[i]=t[i]+1;calc0(p);
				}
				s[i]=t[i];
			}
		}else{
			if(t[i]=='?'){
				if(s[i]!='0'){
					t[i]=s[i]-1;calc0(p);
				}
				t[i]=s[i];
			}else{
				if(s[i]<t[i])return;
				if(s[i]>t[i])calc0(p);
			}
		}
	}
	calc0(p);
}

void solve(){
	cin >> s0 >> t0;
	
	ans=INF;
	s=s0;t=t0;calc(0);
	s=t0;t=s0;calc(1);
	cout << res[0] << ' ' << res[1] << endl;
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
