#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>

#define fi first
#define se second
#define pb push_back
#define sz(a) (((int)a.size()))
#define dist(a,b) ((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se))

using namespace std;

typedef pair<int,int> ii;
typedef long long int Lint;

const int MAXN=1e5+15;

int N,T,res=0;
string ar[MAXN][2];

set<string> S1,S2;

bool bit[MAXN];

void f( int pl ){
	
	if( pl == N ){
		
		int cur=0;
		
		for( int i=0 ; i<N ; i++ )
			if( bit[i] ){
				S1.insert(ar[i][0]);
				S2.insert(ar[i][1]);
			}
		
		for( int i=0 ; i<N ; i++ )
			if( !bit[i] && S1.find(ar[i][0])!=S1.end() && S2.find(ar[i][1])!=S2.end() )
				cur++;
		
		res = max(res,cur);
		S1.clear();
		S2.clear();
		return;
	}
	
	bit[pl]=0;
	f(pl+1);
	bit[pl]=1;
	f(pl+1);
}

int main(){
	
	scanf("%d",&T);
	
	string s1,s2;
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		res = 0;
		scanf("%d",&N);
		
		for( int i=0 ; i<N ; i++ )
			cin >> ar[i][0] >> ar[i][1];
		
		f(0);
		
		printf("Case #%d: %d\n",Case,res);
	}
	
	return 0;
}