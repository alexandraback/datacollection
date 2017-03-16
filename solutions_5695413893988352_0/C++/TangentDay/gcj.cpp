#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)
#define pi M_PI

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int n;
VI e;
VVI e2;
int d[50][50];

int dfs(int now, int past){
	int res = -1;
	REP(i,e2[now].size()){
		int next = e2[now][i];
		if (next == past) continue;
		res = max(res,dfs(next,now));
	}
	if (res>=0)
		return res+1;
	else
		return 0;

}

int main(void) {
	ifstream ifs("input.txt");
	FILE *fp;
	fp = fopen("out.txt","w");
	int t;
	ifs >> t;
	REP(cas,t){		
		fprintf(fp,"Case #%d: ",cas+1);

		string a, b;
		ifs >> a >> b;
		int n = a.length();
		int k = 0;
		while (k<n && (a[k]=='?' || b[k]=='?' || a[k]==b[k])) k++;

		string as, bs, at, bt;
		as = at = a;
		bs = bt = b;
		cout << cas+1 << " ";
		cout << k << " ";
		cout << a << " " << b << " ";

		bool f = 0;
		if (k<n && a[k]<b[k])
			f = 1;
		FORR(i,k-1,0){
			if (a[i]=='?' && b[i]=='?'){
				if (f){
					as[i] = '1';
					bs[i] = '0';
					f = 0;
				}else{
					as[i] = bs[i] = '0';
				}
			}else if (a[i]=='?'){
				if (f){
					if (b[i]=='9')
						as[i] = '0';
					else{
						as[i] = bs[i]+1;
						f = 0;
					}
				}else{
					as[i] = bs[i];
				}
			}else if (b[i]=='?'){
				if (f){
					if (a[i]=='0')
						bs[i] = '0';
					else{
						bs[i] = as[i]-1;
						f = 0;
					}
				}else{
					bs[i] = as[i];
				}
			}else{
				if (a[i]>b[i])
					f = 0;
				else if (a[i]<b[i])
					f = 1;
			}
		}
		FOR(i,k,n-1){
			if (a[i]=='?')
				as[i] = '0';
			if (b[i]=='?')
				bs[i] = '9';
		}

		f = 0;
		if (k<n && b[k]<a[k])
			f = 1;
		FORR(i,k-1,0){
			if (a[i]=='?' && b[i]=='?'){
				if (f){
					bt[i] = '1';
					at[i] = '0';
					f = 0;
				}else{
					at[i] = bt[i] = '0';
				}
			}else if (b[i]=='?'){
				if (f){
					if (a[i]=='9')
						bt[i] = '0';
					else{
						bt[i] = at[i]+1;
						f = 0;
					}
				}else{
					bt[i] = at[i];
				}
			}else if (a[i]=='?'){
				if (f){
					if (b[i]=='0')
						at[i] = '0';
					else{
						at[i] = bt[i]-1;
						f = 0;
					}
				}else{
					at[i] = bt[i];
				}
			}else{
				if (b[i]>a[i])
					f = 0;
				else if (b[i]<a[i])
					f = 1;
			}
		}
		FOR(i,k,n-1){
			if (b[i]=='?')
				bt[i] = '0';
			if (a[i]=='?')
				at[i] = '9';
		}

		cout << as << " " << bs << " ";
		cout << at << " " << bt << " ";

		ll xs, ys, xt, yt;
		xs = ys = xt = yt = 0;
		REP(i,n){
			xs *= 10;
			ys *= 10;
			xt *= 10;
			yt *= 10;
			xs += as[i]-'0';
			ys += bs[i]-'0';
			xt += at[i]-'0';
			yt += bt[i]-'0';
		}

		string ansa, ansb;
		if (abs(xs-ys)<abs(xt-yt)){
			ansa = as;
			ansb = bs;
		}else if (abs(xs-ys)>abs(xt-yt)){
			ansa = at;
			ansb = bt;
		}else{
			if (xs<xt){
				ansa = as;
				ansb = bs;
			}else if (xs>xt){
				ansa = at;
				ansb = bt;
			}else{
				if (ys<yt){
					ansa = as;
					ansb = bs;
				}else{
					ansa = at;
					ansb = bt;
				}
			}
		}

		printf("%s %s\n", ansa.c_str(), ansb.c_str());
		fprintf(fp,"%s %s\n", ansa.c_str(), ansb.c_str());
	}

	return 0;
}