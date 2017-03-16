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

double in[300],n;

int go(int now,double all,double val){
	double sum=in[now]+all*val/100,ans(val);
	int i,j,k;
	rep(i,n){
		if(i==now) continue;
		double www=(sum-in[i])*100/all;
		if(www>0) ans+=www;
	}
	if(ans>=100){
		return 1;
	}
	return 0;
}

int main(){
	freopen("A-small-attempt2.in","r",stdin);
	freopen("aout.txt","w",stdout);
	int t,tt,i,j,k;
	cin >> t;
	for(tt=1 ; tt<=t ; tt++){
		cout << "Case #" << tt << ":";
		cin >> n;
		rep(i,n){
			cin >> in[i];
		}
		double ft,ed,mi,all(0);
		rep(i,n) all+=in[i];
		rep(i,n){
			rep(j,n){
				if(i!=j && in[j]==0.0){
					break;
				}
			}
		/*	if(j!=n){
				printf(" 0");
				continue;
			}*/
			ft=0.0,ed=100.0,mi=50.0;
			while(fabs(ft-ed)>1e-9){
			//	if(i==2) cout << "www" << endl;
				mi=(ft+ed)/2;
				if(go(i,all,mi)){
					ed=mi;
				}
				else{
					ft=mi;
				}
			}
			printf(" %.7lf",(ft+ed)/2);
		}
		cout << endl;
	}
}










