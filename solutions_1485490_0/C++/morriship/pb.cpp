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

long long lcs[111][111],in1[111],ty1[111],in2[111],ty2[111],can[111][111];

long long min(long long a,long long b){
	if(a<b) return a;
	return b;
}

int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("cout.txt","w",stdout);
	int i,j,k,t,tt,n,m,l;
	cin >> t;
	for(tt=1 ; tt<=t ; tt++){
		cin >> n >> m;
		xrep(i,1,n+1){
			cin >> in1[i] >> ty1[i];
		}
		xrep(i,1,m+1){
			cin >> in2[i] >> ty2[i];
		}
		rep(i,m+1){
			can[0][i]=in2[i];
		}
		memset(lcs,0,sizeof(lcs));
		xrep(i,1,n+1){
			rep(j,i){
				xrep(k,1,m+1){
					ll ii=in1[i],ti=ty1[i];
					ll now=lcs[j][k];
					ll canx=can[j][k];
					if(ty2[k]==ti){
						ll w=min(canx,ii);
						ii-=w;
						canx-=w;
						now+=w;
					}
					if(lcs[i][k]<now || lcs[i][k]==now && can[i][k]<canx){
						lcs[i][k]=now;
						can[i][k]=canx;
					}
					
					xrep(l,k+1,m+1){
						canx=in2[l];
						if(ty2[l]==ti){
							ll w=min(in2[l],ii);
							ii-=w;
							canx-=w;
							now+=w;
						}
						if(i==2 && j==1 ){
						//	cout << "k " << k << ' ' <<  "l " << l << endl;
						}
						if(i==2 && j==1 && k==1 && l==4){
						//	cout << now << ' ' << canx << ' ' << "a" << endl;
						}
						if(lcs[i][l]<now || lcs[i][l]==now && can[i][l]<canx){
							if(i==1 && l==3){
							//	cout << now << ' ' << canx << ' ' << "b" << endl;
							}
							lcs[i][l]=now;
							can[i][l]=canx;
						}
					}
				}
			}
		}
		cout << "Case #" << tt << ": ";
		long long ans=-1;
		xrep(i,1,n+1){
			xrep(j,1,m+1){
				if(lcs[i][j]>ans){
					ans=lcs[i][j];
				}
			}
		}
		cout << ans << endl;
	}
//	system("pause");
}























