#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
template<class T> T gcd(T x,T y){while(T t=x%y)x=y,y=t;return y;}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;

#define pmul(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define xmul(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))

#define FR(i,N) for(int i=0;i<N;i++)
#define FRS(i,S,E) for(int i=S;i<=E;i++)
#define FRD(i,S,E) for(int i=S;i>=E;i--)
#define SZ(x) ((int)(x).size())
#define fill(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define lowbit(x) ((x)&(-(x)))

bool isdig(char x){return x>='0'&&x<='9';}
bool isup(char x){return x>='A'&&x<='Z';}
bool isdown(char x){return x>='a'&&x<='z';}
bool islet(char x){return isup(x)||isdown(x);}

//--------CODE----------
int N;
string S[105];

int endWith[27];
int startWith[27];
int allIs[27];
void get_data(){
	cin>>N;
	FR(i, N)cin>>S[i];
}

bool pre(){
	memset(endWith, -1, sizeof(endWith));
	memset(startWith, -1, sizeof(startWith));
	memset(allIs, 0, sizeof(allIs));
	FR(i, N){
		if(S[i][0] == S[i][S[i].size() - 1]){
			FR(j, S[i].size()){
				if(S[i][j] != S[i][0])return false;
			}
			allIs[S[i][0] - 'a']++;
		}else{
			if(startWith[S[i][0] - 'a'] != -1)return false;
			startWith[S[i][0] - 'a'] = i;
			
			if(endWith[S[i][S[i].size() - 1] - 'a'] != -1)return false;
			endWith[S[i][S[i].size() - 1] - 'a'] = i;
		}
	}

	bool inmk[26];
	memset(inmk, 0, sizeof(inmk));
	
	FR(i, N){
		int s = 0, e = S[i].size() - 1;
		for(;s < S[i].size() && S[i][s] == S[i][0]; s++);
		for(;e >= 0 && S[i][e] == S[i][S[i].size() - 1]; e--);

		for(int ts = s; ts <= e; ts++){
			if(ts > s && S[i][ts] == S[i][ts - 1])continue;

			int t = S[i][ts] - 'a';
			if(inmk[t])return false;
			inmk[t] = true;
			if(allIs[t] > 0 || startWith[t] != -1 || endWith[t] != -1)return false;
		}
	}

	return true;
}

ll fpow2(int r){
	if(r <= 0)return 1;
	ll x = 1;
	while(r--){
		x *= 2;
		x %= MOD;
	}
	return x;
}
bool del[26];
bool oNO;
ll A(int x){
	if(x <= 0)return 1;
	ll r = 1;
	FR(i, x){
		r *= i + 1;
		r %= MOD;
	}
	return r;
}
void go(int ind, ll& r){
	string& s = S[ind];
	int ed = s[s.size() - 1] - 'a';
	r *= A(allIs[ed]);
	r %= MOD;
	
	FR(i, s.size()){
		if(i && s[i] == s[i - 1])continue;
		if(del[s[i] - 'a']){
			oNO = false;
			return;
		}
		del[s[i] - 'a'] = true;
	}
	if(startWith[ed] == -1)return;
	del[ed] = false;
	
	go(startWith[ed], r);
}



void getNewS(){
	ll r = 1;
	int n = 0;
	memset(del, 0, sizeof(del));
	bool ok = false;
	FR(i, 26){
		if(endWith[i] != -1)continue;
		if(allIs[i] == 0 && startWith[i] == -1)continue;
		ok = true;
		string t = "";
		ll tr = A(allIs[i]);
		oNO = true;
		if(startWith[i] == -1){

		}else{
			go(startWith[i], tr);
		}
		if(!oNO){
			cout<<0<<endl;
			return;
		}
		n++;
		r *= tr;
		r %= MOD;
	}
	if(!ok){
		cout<<0<<endl;
		return;
	}
	r *= A(n);
	r %= MOD;
	cout<<r<<endl;
}

void run(){
	if(!pre()){
		cout<<0<<endl;
		return;
	}
	getNewS();
}
int main(){
//	get_prime();
	freopen("B-small-attempt4.in","r",stdin);
	freopen("B-small-attempt4.out","w",stdout);
	int t;
	cin>>t;
	FR(i, t)
	{
	get_data();
	printf("Case #%d: ", i + 1);
	run();
	}
	return 0;
}
