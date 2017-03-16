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

int in[111];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.txt","w",stdout);
	
	int i,j,k,t,tt,n,p,s;
	sca(tt);
	for(t=1 ; t<=tt ; t++){
		cout << "Case #" << t << ": ";
		cin >> n >> s >> p;
		rep(i,n){
			cin >> in[i];
		}
		int ans(0);
		sort(in,in+n);
		for(i=n-1 ; i>=0 ; i--){
		//	cout << in[i] << endl;
			if(in[i]>=p && (in[i]+2)/3>=p){
				ans++;
			}
			else if(s && in[i]>=p && (in[i]+4)/3>=p){
				ans++;
				s--;
			}
		}
		cout << ans << endl;
	}
}
































