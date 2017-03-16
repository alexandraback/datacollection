#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const int inf = 150;
int n, m, a[120][120];
vector< pii > q;

inline int val(const pii& x){
	return a[x.fi][x.se];
}

bool cmp(const pii& l, const pii& r){
	return val(l) > val(r);
}

inline void Read(){
	scanf("%d %d\n", &n, &m);
	int temp;
	q.resize(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			scanf("%d ", &temp);
			a[i][j] = temp;
			q.pb( mp(i,j) );
		}
		scanf("%d\n", &temp);
		a[i][m-1] = temp;
		q.pb(mp(i,m-1));
	}
}

bool cor(const pii& x){
	bool flag1 = false, flag2 = false;
	for(int i=0;i<m;i++)
		if(flag1 = ( (a[x.fi][i] != a[x.fi][x.se]) && (a[x.fi][i] != inf) ))
			break;
	for(int i=0;i<n;i++)
		if(flag2 = ( (a[i][x.se] != a[x.fi][x.se]) && (a[i][x.se] != inf) ))
			break;
	if(!flag1)
		for(int i=0;i<m;i++)
			a[x.fi][i] = inf;
	if(!flag2)
		for(int i=0;i<n;i++)
			a[i][x.se] = inf;		
	return !(flag1 && flag2);
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
 	scanf("%d\n", &T);
 	for(int t=1;t<=T;t++){
		Read();
		sort(q.begin(), q.end(), cmp);
		bool ans = true;
		while(q.size())
			if(val(q.back()) == inf)
				q.pop_back();
			else
				if( ans = !cor(q.back()) )
					break;	
        printf("Case #%d: %s\n", t, ans ? "NO" : "YES");		
	}
	return 0;
}
