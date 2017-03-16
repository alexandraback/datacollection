#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8

typedef long long ll;
typedef pair<int,int> ii;

#define N 110
int t,j,p,s,k;
ii arr[N];
int c01[N][N];
int c02[N][N];
int c12[N][N];
int ans[1010][3];
int q;

int comp(ii b, ii c){
	return b > c;
}

void go(int a){
	if (a <= 0) return;
	frd(i2,p,0){
		frd(i,j,0){
			if (c01[i][i2] < k && c02[i][a] < k && c12[i2][a] < k
			 && c01[i2][i] < k && c02[a][i] < k && c12[a][i2] < k){
				c01[i][i2]++;
				if (i != i2) c01[i2][i]++;
				
				c02[i][a]++;
				if (i != a) c02[a][i]++;
				c12[i2][a]++;
				if (i2 != a) c12[a][i2]++;
				ans[q][0] = i;
				ans[q][1] = i2;
				ans[q][2] = a;
				q++;
			}
			}
		}
	go(a-1);
}

void solve(){
	SET(c01,0);
	SET(c02,0);
	SET(c12,0);
	q = 0;
	go(s);
	
	printf("%d\n",q);
	fr(i,0,q) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);

}



int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%d%d%d%d",&j,&p,&s,&k);
		solve();
	}

	return 0;
}