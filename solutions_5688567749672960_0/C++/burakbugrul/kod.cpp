#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define fi first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
#define dist(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

using namespace std;

typedef long long int Lint;
typedef pair<int,int> ii;

const int MAXN=1e6+14;
const int MAXM=1e4;

int N,M,T;
int ten[20];
int dn[MAXN];

priority_queue<ii,vector<ii>,greater<ii> > pq;

inline int rev( int num ){
	
	int rev=0;
	vector<int> vec;
	
	while(num){
		vec.pb(num%10);
		num/=10;
	}
	
	for( int i=0,j=sz(vec)-1 ; j>=0 ; i++,j-- )
		rev+=vec[j]*ten[i];
	
	return rev;
}

int main(){
	
	ten[0]=1;
	for( int i=1 ; i<9 ; i++ )
		ten[i]=ten[i-1]*10;
	
	scanf("%d",&T);
	
	pq.push(ii(1,1));
	
	while( !pq.empty() ){
		
		ii tmp=pq.top();
		pq.pop();
		
		if( tmp.se>=MAXN || dn[tmp.se] )
			continue;
		
		dn[tmp.se]=tmp.fi;
		
		int r=rev(tmp.se);
		pq.push(ii(tmp.fi+1,tmp.se+1));
		pq.push(ii(tmp.fi+1,r));
	}
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		scanf("%d",&N);
		
		printf("Case #%d: %d\n",Case,dn[N]);
	}
	
	return 0;
}
