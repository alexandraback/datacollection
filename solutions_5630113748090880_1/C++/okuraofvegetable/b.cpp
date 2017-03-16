#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int cnt[3010];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		memset(cnt,0,sizeof(cnt));
		int N;
		scanf("%d",&N);
		for(int i=0;i<2*N-1;i++){
			for(int j=0;j<N;j++){
				int k;
				scanf("%d",&k);
				cnt[k]++;
			}
		}
		printf("Case #%d:",t+1);
		for(int i=0;i<=3000;i++){
			if(cnt[i]%2==1)printf(" %d",i);
		}
		printf("\n");
	}	
	return 0;
}
