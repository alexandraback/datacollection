// Author : SAGORIKA DAS

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
#define int long long
using namespace std;
int b[55][55],W[55];
map<int,int> M;

string bin(int w){
	string res = "";
	while(w){
		if(w%2) res+="1";
		else res+="0";
		w/=2;
	}
	return res;
}

 main()
{
	fr;fw;
	int T,cases=1;
	cin >>T;
	while(T--){
		CLEAR(b);CLEAR(W);M.clear();
		printf("Case #%d: ",cases++);
		int n,m;
		cin >> n >> m;
		W[n-1] = 1;
		M[1] = n-1;
		for(int i=n-2;i>=1;i--){
			W[i] = W[i+1]*2;
			M[W[i]] = i;
		}
		if( m > W[1] ) {
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<"POSSIBLE\n";
        int j =  n-1;
		while(1){
			if(m <= 0 || j == 1) break;

			if(m >= W[j]){
				for(int i=j+1;i<=n;i++) b[j][i] = 1;
					m-=W[j];
			}
			else{
				string s = bin(m);
				int p = 1;
				for(int i=0;i<s.size();i++){
					if(s[i] == '1'){
						b[j][M[p]] = 1;
					}
					p =p*2;
				}
				m = 0;
			}
			j--;
		}

		if( m == 0 ){ 
			for(int i=j+1;i<=n-1;i++) b[1][i] = 1;
		}
		else{
			for(int i=2;i<=n;i++) b[1][i] = 1;
		}
	FOR(i,1,n+1){
	FOR(k,1,n+1){
		cout<< b[i][k];
	}
	cout<<"\n";
    }
	}

	return 0;
}
