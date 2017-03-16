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
int f[26],c[10];

int main()
{
	fr;fw;
    int T,cases=1;
    cin >> T;
    while(T--){
    	CLEAR(f);
    	CLEAR(c);
    	string s;
    	cin >> s;
    	REP(i,s.size()){
    		f[s[i]-'A']++;
    	}

    	string res = "";
    	int val ;
    	
    	REP(i,f['Z'-'A']) c[0]++;
    	val =  f['Z'-'A'];
    	f['Z'-'A'] -= val;
    	f['E'-'A'] -= val;
    	f['R'-'A'] -= val;
    	f['O'-'A'] -= val;

    	REP(i,f['W'-'A']) c[2]++;
    	val =  f['W'-'A'];
    	f['W'-'A'] -= val;
    	f['T'-'A'] -= val;
    	f['O'-'A'] -= val;

    	REP(i, f['U'-'A']) c[4]++;
    	val =  f['U'-'A'];
    	f['U'-'A'] -= val;
    	f['R'-'A'] -= val;
    	f['O'-'A'] -= val;
    	f['F'-'A'] -= val;

    	REP(i, f['X'-'A']) c[6]++;
    	val =  f['X'-'A'];
    	f['X'-'A'] -= val;
    	f['S'-'A'] -= val;
    	f['I'-'A'] -= val;

    	REP(i, f['G'-'A']) c[8]++;
    	val =  f['G'-'A'];
    	f['G'-'A'] -= val;
    	f['E'-'A'] -= val;
    	f['I'-'A'] -= val;
    	f['H'-'A'] -= val;
    	f['T'-'A'] -= val;

    	REP(i, min(f['O'-'A'],min(f['N'-'A'],f['E'-'A']))) c[1]++;
    	val = min(f['O'-'A'],min(f['N'-'A'],f['E'-'A']));
    	f['N'-'A']  -=  val;
    	f['O'-'A']  -=  val;
    	f['E'-'A']  -=  val;

    	
    	REP(i,  min(f['H'-'A'],min(f['R'-'A'],min(f['T'-'A'],f['E'-'A']/2) )) )c[3]++;
    	val = min(f['H'-'A'],min(f['R'-'A'],min(f['T'-'A'],f['E'-'A']/2) ));
    	f['T'-'A'] -= val;
    	f['H'-'A'] -= val;
    	f['R'-'A'] -= val;
    	f['E'-'A'] -= 2*val;

    	
    	
    	REP(i, min(f['F'-'A'],min(f['V'-'A'],min(f['I'-'A'],f['E'-'A'])))) c[5]++;
    	val = min(f['F'-'A'],min(f['V'-'A'],min(f['I'-'A'],f['E'-'A'])));
    	f['V'-'A'] -= val;
    	f['F'-'A'] -= val;
    	f['I'-'A'] -= val;
    	f['E'-'A'] -= val;
    	
    	
    	
    	REP(i, min(f['S'-'A'],min(f['E'-'A']/2,min(f['N'-'A'],f['V'-'A'])))) c[7]++;
    	val = min(f['S'-'A'],min(f['E'-'A']/2,min(f['N'-'A'],f['V'-'A'])));
    	f['V'-'A'] -= val;
    	f['E'-'A'] -= 2*val;
    	f['N'-'A'] -= val;
    	f['S'-'A'] -= val;
    	
    	
    	REP(i, min(f['N'-'A']/2,min(f['E'-'A'],f['I'-'A']))) c[9]++;

    	REP(i,10){
    		REP(j,c[i]){
    			res+= '0'+i;
    		}
    	}

    	printf("Case #%d: ", cases++);cout<<res<<"\n";
    }
	return 0;
}
