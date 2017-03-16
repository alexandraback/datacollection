// Author : SAGORIKA DAS
// Google Code Jam
// Round 1B
// 
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iomanip>
#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define inf 1000000006
#define pb push_back
#define MAX 200002
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define CLEAR(a) memset(a,0,sizeof a)
#define pii pair< int , int >
#define piii pair< int , pii >
#define piiii pair< int, piii >
#define fr freopen("input.txt", "r", stdin);
#define fw freopen("output.txt", "w", stdout);
#define pause system("pause");
using namespace std;
int mn = inf,N;
string finalc="0",finalj="0";
int getval(string s){
	int res = 0;
	for(int i=0;i<s.size();i++){
		res  = res*10 + s[i]-'0';
	}
	return res;
}
    	
int getdiff(string c,string j){
	return abs(getval(c)- getval(j));
}

void solve(int i,string c, string j){

	if( i == N){
		int val = getdiff(c,j);
		if(mn > val){
			mn = val;
			finalc = c;
			finalj = j;
		}
		else if(mn == val){
			if( getval(finalc) > getval(c) ){
				finalc = c;
				finalj = j;
			}
			else if(getval(finalc)  ==  getval(c)){
				if(getval(finalj) > getval(j) ){
					finalj = j;
				}
			}
		}
		return ;
	}

	if(c[i] == '?' && j[i] == '?'){
		REP(p,10){
			REP(q,10){
				c[i] = '0'+p; j[i] = '0'+q;
				solve(i+1,c,j);
			}
		}
	}
	else if( c[i] == '?'){
		REP(p,10){
			c[i] = '0'+p;
			solve(i+1,c,j);
		}
	}
	else if(j[i] == '?'){
		REP(p,10){
			j[i] = '0'+p;
			solve(i+1,c,j);
		}
	}

	else{
	solve(i+1,c,j);
	}
}

int main()
{
	fr;fw;
    int T,cases=1;
    cin >> T;
    while(T--){
    	mn = inf;
    	string c,j;
    	cin >> c >> j;
    	N = c.size();
    	solve(0,c,j);
    	printf("Case #%d: ", cases++);cout<<finalc<<" "<<finalj<<"\n";
    }
	return 0;
}
