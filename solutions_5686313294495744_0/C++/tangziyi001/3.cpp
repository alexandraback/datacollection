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

vector<pair<string,string> > all;
vector<pair<string,string> > tmp; // Real
int n;
bool check(){
	int sz = all.size();
	int ssz = tmp.size();
	REP(i,0,sz){
		int flag1 = 0;
		int flag2 = 0;
		REP(j,0,ssz){
			if(all[i].first == tmp[j].first)
				flag1 = 1;
			if(all[i].second == tmp[j].second)
				flag2 = 1;
		}
		if(!flag1 || !flag2)
			return false;
	}
	return true;
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		all.clear();
		tmp.clear();
		cin >> n;
		REP(i,0,n){
			string a,b;
			cin >> a >> b;
			all.push_back(make_pair(a,b));
		}
		int num = -1;
		int k = 0;
		int re = 0;
		for( ;k < (1 << n); k++){
			tmp.clear();
			int num = 0;
			REP(i,0,n){
				if(k & (1 << i)){
					num++;
					tmp.push_back(all[i]);
				}
			}
			if(check()){
				re = max(re, n-num);
			}
		}
		printf("Case #%d: %d\n", t, re);
	}
	return 0;
}