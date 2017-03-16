# include <bits/stdc++.h>

# define ff first
# define ss second
# define mp(x,y) make_pair(x,y)
# define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

template<typename A, typename B> inline void amax(A &x, B y) {if(x < y) x = y;}
template<typename A, typename B> inline void amin(A &x, B y) {if(!(x < y)) x = y;}

typedef long long lld;

using namespace std;

int dp[1000009];
bool seen[1000009];

int main(){
	seen[1] = 1;
	dp[1] = 1;
	
	queue<int> Q;
	
	Q.push(1);
	
	int tmp, nw, _nw;
	
	while(!Q.empty()){
		nw = Q.front();
		
		Q.pop();
		
		if(seen[nw+1] == 0  &&  nw < 1000000){
			seen[nw+1] = 1;
			dp[nw+1] = dp[nw] + 1;
			Q.push(nw+1);
		}
		
		tmp = 0;
		_nw = nw;
		
		while(_nw){
			tmp = tmp * 10 + _nw % 10;
			_nw /= 10;
		}
		
		if(seen[tmp] == 0  &&  tmp <= 1000000){
			seen[tmp] = 1;
			dp[tmp] = dp[nw] + 1;
			Q.push(tmp);
		}
		
		_nw = tmp;
		tmp = 0;
		
		while(_nw){
			tmp = tmp * 10 + _nw % 10;
			_nw /= 10;
		}
		
		if(seen[tmp] == 0  &&  tmp <= 1000000){
			seen[tmp] = 1;
			dp[tmp] = dp[nw] + 1;
			Q.push(tmp);
		}
	}
	
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int t, n;
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		scanf("%d",&n);
		printf("Case #%d: %d\n",i+1,dp[n]);
	}
}

