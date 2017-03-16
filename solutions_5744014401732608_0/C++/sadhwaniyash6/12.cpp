/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define mod 1000000007

	
#define MAXN 60
#define SQRT 330
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>
#define F first
#define S second

ll modpow(ll base, ll exponent,ll modulus){
	if(base==0&&exponent==0)return 0;
	ll result = 1;
	while (exponent > 0){
		if (exponent % 2 == 1)
		    result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}


ll B, M;

int arr[MAXN][MAXN];

ll pw[MAXN];

inline void ReadInput(void){
	sl(B); sl(M);
}

inline void solve(int t){
	printf("Case #%d: ", t);
	if(pw[B - 2] < M) printf("IMPOSSIBLE\n");
	else{
		printf("POSSIBLE\n");
		M--; arr[1][B] = 1;
		int a = 1;
		while(M){
			if(M & 1){
				arr[a + 1][B] = 1;
			}
			M /= 2;
			a++;
		}

		for(int i = 1; i <= B; i++){
			for(int j = 1; j <= B; j++) cout << arr[i][j];
			cout << endl;
		}
	}
}

inline void Refresh(void){
	for(int i = 1; i <= B; i++){
		for(int j = 1; j <= B; j++) arr[i][j] = 0;
	}
	for(int i = 1; i <= B; i++){
		for(int j = i + 1; j < B; j++) arr[i][j] = 1;
	}
}

int main()
{	
	//ios_base::sync_with_stdio(false);
	int t; si(t);
	int g = 1;
	pw[0] = 1;
	for(int i = 1; i < 60; i++) pw[i] = pw[i - 1] * 2LL;
	while(t--){
		ReadInput();
		Refresh();
		solve(g);
		g++;
	}
    return 0;
}

// U COME AT THE KING, BETTER NOT MISS !!!