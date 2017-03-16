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

int use[2000001];

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.txt","w",stdout);
	
	int a,b;
	int i,j,k,n,t,tt;
	sca(tt);
	xrep(t,1,tt+1){
		memset(use,0,sizeof(use));
		cout << "Case #" << t << ": ";
		cin >> a >> b;
		int c=a,len(0),xl(1);
		while(c){
			c/=10;
			len++;
			xl*=10;
		}
		xl/=10;
		int ans(0);
		for(i=a ; i<=b ; i++){
			if(!use[i]){
				use[i]=1;
				int j=i,w=1;
				for(int www=1 ; www<len ; www++){
					j=j/10+(j%10)*xl;
					if(!use[j] && j>=a && j<=b){
						w++;
					}
					use[j]=1;
				}
				ans+=w*(w-1)/2;
			}
		}
		cout << ans << endl;
	}
}
































