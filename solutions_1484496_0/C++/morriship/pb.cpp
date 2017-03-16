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
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

int in[30],pre[4000000];

int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("bout.txt","w",stdout);
	int t,tt,i,j,k,n;
	cin >> t;
	memset(pre,-1,sizeof(pre));
	for(tt=1 ; tt<=t ; tt++){
		int ox(false);
		cout << "Case #" << tt <<  ":" << endl;
		cin >> n;
		rep(i,n){
			cin >> in[i];
		}
		stack<int> a,b;
		memset(pre,0,sizeof(pre));
		pre[2000000];
		int maxn(2000000),minx(2000000);
		rep(i,n){
			int now=in[i];
			if(pre[2000000+now]!=0){
				a.push(now);
				for(j=2000000+now ; j!=2000000 ; j=j-pre[j]){
					if(pre[j]<0){
						a.push(pre[j]);
					}
					else{
						b.push(pre[j]);
					}
				}
				break;
			}
			for(j=minx ; j<=maxn ; j++){
				if(pre[j]!=0 || j==2000000){
					pre[j-now]=-now;
					minx=min(minx,j-now);
				}
			}
			for(j=maxn ; j>=minx ; j--){
				if((pre[j]!=0 || j==2000000 )&& pre[j]!=-now){
					pre[j+now]=now;
					maxn=max(maxn,j+now);
				}
			}
		}
		if(a.empty()){
			cout << "Impossible" << endl;
		}
		else{
			cout << abs(a.top());
			a.pop();
			while(!a.empty()){
				cout << ' ' << abs(a.top());
				a.pop();
			}
			cout << endl;
			cout << abs(b.top());
			b.pop();
			while(!b.empty()){
				cout << ' ' << abs(b.top());
				b.pop();
			}
			cout << endl;
		}
	}
}
