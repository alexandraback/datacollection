#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int t,n,m,ct;
char A[1000],B[1000],cons[1000];
long long dp[10000][10][4];


long long C(int n,int m){
	long long ans = 1;
	for ( int i = n ; i > n-m ; i-- ) ans = ans*i;
	for ( int i = 2 ; i <= m ; i++ ) ans = ans/i;
	return ans;
}
long long all_n_pos(int n){
	if (n==1) return 3;
	long long ans = 1+(n%2);
	int pos = n/2-1;
	if (n%2){//first-1
		//mid-0
		if (pos>=0) ans += C(pos,0);
		if (pos>=1) ans += C(pos,1);
		if (pos>=2) ans += C(pos,2);
		if (pos>=3) ans += C(pos,3);
		//mid-1
		if (pos>=0) ans += C(pos,0);
		if (pos>=1) ans += C(pos,1);
		if (pos>=2) ans += C(pos,2);
		if (pos>=3) ans += C(pos,3);
		//mid-2
		if (pos>=0) ans += C(pos,0);
		if (pos>=1) ans += C(pos,1);
	} else{
		if (pos>=0) ans += C(pos,0);
		if (pos>=1) ans += C(pos,1);
		if (pos>=2) ans += C(pos,2);
		if (pos>=3) ans += C(pos,3);
	}
	return ans;
}

long long work(char* A){
	int n = strlen(A),mid = n/2,state,cost;
	long long ans = 0;
	if (n==1){return min(A[0]-'0',3);}
	for ( int i = 1 ; i < n ; i++ )
		ans += all_n_pos(i);
/*	if (A[0]>'2') ans += all_n_pos(n);
	if (A[0]=='2'){
		ans += all_n_pos(n);
		memset(cons,'0',sizeof(cons));
		cons[0] = cons[n-1] = '2',cons[n] = 0;
		if (strcmp(A,cons)<0) ans -= 1;
		if (n%2){
			cons[mid] = '1';
			if (strcmp(A,cons)<0) ans -= 1;
		}
	}
	if (A[0]=='1'){*/
	if (true){
		memset(dp,0,sizeof(dp));
		dp[0][9][0] = 1;
		for ( int i = 0 ; i <= mid ; i++ ){
			if (i==mid && (n%2)==0) break;
			for ( int j = 0 ; j < 10 ; j++ ){
				for ( int k = 0 ; k < 4 ; k++ ) if (dp[i][j][k]>0){
					for ( int next = (i==0)?1:0 ; next < 3 ; next++ ){
						if (i==mid) cost = next*next ; else cost = next*next*2;
						if ((k&2)==0 && next>A[i]-'0') continue;
						if (j-cost<0) continue;
						state = k;
						if (next<A[i]-'0') state |= 2;
						if (next>A[n-1-i]-'0') state |= 1;
						dp[i+1][j-cost][state] += dp[i][j][k];
					}
				}
			}
		}
		mid += n%2;
		for ( int j = 0 ; j < 10 ; j++ ){
			for ( int k = 0 ; k < 4 ; k++ ){
				if (k!=1) ans += dp[mid][j][k];
			}
		}
	}
	return ans;
}
void init(){
	scanf("%s%s",A,B);
}
int main(){
	freopen("C.out","r",stdin);
	freopen("C2.out","w",stdout);
	for ( scanf("%d",&t),ct = 1 ; ct <= t ; ct++ ){
		printf("Case #%d: ",ct);
		init();
		cout << work(B)-work(A) << endl;
	}
}

