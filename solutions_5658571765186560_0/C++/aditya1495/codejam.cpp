//Aditya Shah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()

#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)

#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define F first
#define S second

#define pb push_back
#define pf push_front
#define mp make_pair

const int inf=numeric_limits<int>::max();
const LL linf=numeric_limits<LL>::max();

string dp[5][5][5];

int main(){
	fr;
	fw;
	int test,x,n,m;
	forup(i,1,5){
		forup(j,1,5){
			forup(k,1,5){
				if(i == 1){
					dp[i][j][k] = "GABRIEL";
				} else if((j*k) % i != 0){
					dp[i][j][k] = "RICHARD";
				} else if(i == 2){
					dp[i][j][k] = "GABRIEL";
				} else if(i == 3){
					if(min(j,k) == 1){
						dp[i][j][k] = "RICHARD";
					} else {
						dp[i][j][k] = "GABRIEL";
					}
				} else {
					if(max(j,k) < 4 || min(j,k) <= 2){
						dp[i][j][k] = "RICHARD";
					} else {
						dp[i][j][k] = "GABRIEL";
					}
						
				}
			}
		}
	}
	gi(test);
	rep(c,test){
		printf("Case #%d: ",c+1);
		gi(x); gi(n); gi(m);
		puts(dp[x][n][m].c_str());
	}
	return 0;
}