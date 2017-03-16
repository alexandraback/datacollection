/*
 *	
 *	Coded by Ziyi Tang
 *
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

bool check(string x, string y){
	if(x.size() != y.size()) return false;
	int sz = x.size();
	REP(i,0,sz){
		if(x[i] != y[i] && x[i] != '?' && y[i] != '?'){
			return false;
		}
	}
	return true;
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		string a,b;
		cin >> a;
		cin >> b;
		int sz = a.size();
		int cc = INF,jj = INF;
		int min = INF;
		REP(i,0,(int)pow(10,sz)) REP(j,0,(int)pow(10,sz)){
			//if(i > 10*sz || j > 10*sz) continue;
			string tmpa = to_string(i);
			string tmpb = to_string(j);
			while(tmpa.size() < sz){
				tmpa = '0' + tmpa;
			}
			while(tmpb.size() < sz){
				tmpb = '0' + tmpb;
			}
			// cout << tmpa << " " << tmpb << endl;
			// cout << a << " " << b << endl;
			if(check(a, tmpa) && check(b, tmpb)){
				if(abs(i-j) < min){
					cc = i;
					jj = j;
					min = abs(i-j);
				}
				// else if(abs(i-j) == min){
				// 	if(i < cc){
				// 		cc = i; jj = j;
				// 	}
				// 	if(cc == i && j < jj){
				// 		jj = j;
				// 	}
				// }
				
			}
		}
		string rea = to_string(cc);
		string reb = to_string(jj);
		while(rea.size() < sz){
			rea = '0' + rea;
		}
		while(reb.size() < sz){
			reb = '0' + reb;
		}
		printf("Case #%d: %s %s\n",t, rea.c_str(), reb.c_str());
	}
	return 0;
}