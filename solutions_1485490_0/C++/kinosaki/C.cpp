#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long

ll N,M;
vector<ll> An,At,Bn,Bt;
int main(){
  ll T;
  cin >> T;
  for (ll testCase =1; testCase<=T; testCase++){
    An.clear();
    Bn.clear();
    At.clear();
    Bt.clear();
    cin >> N >> M;
    for (ll i=0; i<N; i++){
      ll a,b;
      cin >> a >> b;
      An.push_back(a);
      At.push_back(b);
    }

    for (ll i=0; i<M; i++){
      ll a,b;
      cin >> a >> b;
      Bn.push_back(a);
      Bt.push_back(b);
    }

    ll dp[N+1][M+1];
    for (ll i=0; i<=N; i++){
      for (ll j=0; j<=M; j++){
	dp[i][j] = 0;
      }
    }
    for (ll i=1; i<=N; i++){
      for (ll j=1; j<=M; j++){
	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	for (ll k=0; k<i; k++){

	  ll num = 0;
	  for (ll m=j-1; m>=0; m--){
	    if (Bt[m] == Bt[j-1]){
	      num += Bn[m];

	      for (ll l=k; l<i; l++){
		if (At[l] == Bt[m]){

		  ll num2 = 0;
		  for (ll n=l; n>=0; n--){
		    if (At[n] == Bt[m]){
		      num2 += An[n];
		      dp[i][j] = max(dp[i][j], dp[n][m] + min(num,num2));
		    }
		  }
		}
	      }

	    }
	  }

	}

	for (ll k=0; k<j; k++){

	  ll num = 0;
	  for (ll m=i-1; m>=0; m--){
	    if (At[m] == At[i-1]){
	      num += An[m];

	      for (ll l=k; l<j; l++){
		if (Bt[l] == At[i-1]){

		  ll num2 = 0;
		  for (ll n=l; n>=0; n--){
		    if (Bt[n] == At[m]){
		      num2 += Bn[n];
		      dp[i][j] = max(dp[i][j], dp[m][n] + min(num,num2));
		    }
		  }
		}
	      }
	    }
	  }
	}

      }
    }
    /*
    for (ll i=0; i<=N; i++){
      for (ll j=0; j<=M; j++){
	prllf ("%d %d = %lld \n",i,j,dp[i][j]);
      }
    }
    */
    printf("Case #%lld: %lld\n",testCase, dp[N][M]);
    //   cout << dp[N][M] << endl;

  }
}
