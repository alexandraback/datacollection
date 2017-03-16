#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define repsr(i,j,k) for(int i = (j); i >= (k); --i)
#define repr(i,j) repsr(i,j,0)
#define all(a) a.begin(),a.end()
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int, ll> Pil;
typedef vector<int> vi;
typedef vector<vi> vvi;

int memo[52];
bool Matrix[52][52];
int End;
void dfs(int idx,int bit){
	memo[idx]++;
	rep(i,End){
		if(Matrix[idx][i] && !((bit>>i)&1)){
			dfs(i,bit|(1<<i));
		}
	}
	return ;
}
int count(bool matrix[52][52],int end){
	memset(memo,0,sizeof(memo));
	End = end;
	rep(i,end){
		rep(j,end){
			Matrix[i][j] = matrix[i][j];
		}
	}
	dfs(0,0);
	return memo[end-1];
}

int main(){
	int Q;
	scanf("%d",&Q);
	rep(q,Q){
		//input
		int N,M;
		scanf("%d%d",&N,&M);

		int bit ;
		bit = 1 << 15;
		
		bool flg = false;

		rep(i,bit){
			bool mat[52][52]={{}};
			int cnt=0;
			rep(j,N){
				reps(k,j+1,N){
					if(((i>>cnt)&1)){
						mat[j][k] = true;
					}
					cnt++;
				}
			}
			/*puts("**************");
			rep(j,N){
				rep(k,N){
					printf("%d",mat[j][k]);
				}
				puts("");
			}*/
			int ans = count(mat,N);
			if(ans >= M){
				printf("Case #%d: POSSIBLE\n",q+1);
				rep(j,N){
					rep(k,N){
						printf("%d",mat[j][k]);
					}
					puts("");
				}
				flg = true;
			}
			if(flg){
				break;
			}
		}



		//output
		if(!flg){
			printf("Case #%d: IMPOSSIBLE\n",q+1);
		}
		
	}
	return 0;
}