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

int main()
{
	fr;fw;
    int T,cases=1;
    cin >> T;
    while(T--){
    	int n;
    	cin >> n;
    	string a[17],b[17];
    	map<string ,int>s1,s2;
    	REP(i,n){
    		cin >> a[i] >> b[i];
    		s1[a[i]]++; s2[b[i]]++;
    	}
    	int ans = 0;
    	REP(i,n){
    		if(s1[a[i]] >1 && s2[b[i]] >1) ans++;
    	}
    	printf("Case #%d: ", cases++);cout<<ans<<"\n";
    }
	return 0;
}
