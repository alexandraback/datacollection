#include<bits/stdc++.h>
#define LL long long 
#define PI acos(-1)
#define y second
#define PII pair<int,int>
#define F(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define feq(x,y) (fabs((x)-(y)) <= eps)
#define flt(x,y) ((x)+eps < (y))
#define fle(x,y) ((x)+eps <= (y))
#define fgt(x,y) ((x) > (y)+eps)
#define fge(x,y) ((x) >= (y)+eps)
using namespace std;

int T,n,ans,c,d,v;
int a[50], p[50], D[50], mx[50], my[50], vy[50], x[50];
int w[50][50], put[50];

bool dfs(int x){
    for(int i=0; i<50; i++){
	if(w[x][i] && !vy[i]){
	    vy[i] = 1;
	    if(my[i] == -1 || dfs(my[i])){
		mx[x] = i; my[i] = x;
		return true;
	    }
	}
    }
    return false;
}

int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d%d%d", &c,&d,&v);
	for(int i=0; i<d;i++) scanf("%d", &D[i]);
	memset(a,0, sizeof(a));
	memset(mx,-1,sizeof(mx)); 
	memset(my,-1, sizeof(my));
	memset(w,0,sizeof(w));
	memset(put,0,sizeof(put));
	a[0] = 1;
	for(int i=0; i<d; i++) for(int j=v; j>=D[i]; j--) a[j] = a[j-D[i]];
	int cnt = 0;	
	for(int i=0 ; i<=v; i++){
	    if(!a[i]) for(int j=i; j>=0; j--){
		if(a[i-j]) { if(!put[i]){ x[cnt++] = i;put[i] = 1;} w[i][j] = w[j][i] = 1;}
	    }
	}
	ans = 0;
	for(int i=0; i<cnt;i++){
	    memset(vy,0,sizeof(vy));
	    if(dfs(x[i])) ans++;
	}

	printf("Case #%d: %d\n", qwe, ans);
    }
    return 0;
}
