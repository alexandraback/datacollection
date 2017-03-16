#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

vector<int> edge[1111];
int use[1111],can[1111];

int go(int x,int now){
	int i,j,k,y;
	rep(i,edge[now].size()){
		y=edge[now][i];
		if(use[y]==x){
			return 1;
		}
		use[y]=x;
		if(go(x,y)){ return 1; }
	}
	return 0;
} 

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("aout.txt","w",stdout);
	int i,j,k,t,tt,n,x,y,m;
	cin >> t;
	for(tt=1 ; tt<=t ; tt++){
		cin >> n;
		memset(can,1,sizeof(can));
		xrep(i,1,n+1){
			edge[i].clear();
			cin >> m;
			rep(j,m){
				sca(y);
				edge[i].push_back(y);
				can[y]=0;
			}
		}
		cout << "Case #" << tt << ": ";
		memset(use,0,sizeof(use));
		xrep(i,1,n+1){
			if(can[i]){
				if(go(i,i)){
					cout << "Yes" << endl;
					break;
				}
			}
		}
		if(i==n+1){
			cout << "No" << endl;
		}
	}
}























