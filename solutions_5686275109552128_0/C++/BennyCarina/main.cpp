#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
using namespace std;

#define d_pi 57.2957795
#define LL __int64
#define LarN 100000

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}

int P[1005], D;


bool check(int n, int m){
	int a = n - m;
	int acc = 0;
	for(int i = 0; i < D; i ++){
		acc += (P[i]-1)/a;
	}
	if(acc <= m)return true;
	else return false;
}


bool isPossible(int n){
	for(int i = 0; i < n; i ++){
		if(check(n, i))return true;
	}
	return false;
}

void solve(){
	scanf("%d", &D);
	for(int i = 0; i < D; i ++)scanf("%d", &P[i]);
	int left = 1, right = -1, mid;
	for(int i = 0; i < D; i ++)ReMax(right, P[i]);
	mid = (right + left)/2;
	while(right > left){
		mid = (right + left)/2;
		if(isPossible(mid)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	printf("%d\n", right);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d: ",i_case);
		solve();
	}
	return 0;
}
