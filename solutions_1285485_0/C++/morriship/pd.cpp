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
#define EPS (1e-12)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

char in[100][100],cant[2600][2600],cantx[2600][2600];
int dir[4][2]={0,1,0,-1,-1,0,1,0},dis[4];

int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}

int main(){
	freopen("D-small-attempt3.in","r",stdin);
	freopen("d.txt","w",stdout);
	
	long long i,j,k,l,x,y,n,m,len,t,tt;
	int o,p,op;
	cin >> tt;
	for(t=1 ; t<=tt ; t++){
		cout << "Case #" << t << ": ";
		cin >> n >> m >> len;
		long long lenx=len*len;
		rep(i,n){
			cin >> in[i];
		}
		rep(i,n){
			rep(j,m){
				if(in[i][j]=='X'){
					x=i,y=j;
				}
			}
		}
		long long a,b;
		long long ans(0);
		rep(i,4){
			int xx=x,yy=y;
			a=dir[i][0],b=dir[i][1];
			for(j=0 ; in[xx][yy]!='#' ; j++){
				xx+=a;
				yy+=b;
			}
			if(j+j-1<=len){
				ans++;
			}
			dis[i]=j-1;
		}
		memset(cant,0,sizeof(cant));
		memset(cantx,0,sizeof(cantx));
		for(i=dis[0]+dis[0]+1 ; i<=len ; i+=dis[0]+dis[0]+1){
			for(j=dis[2]+dis[2]+1 ; i*i+j*j<=lenx ; j+=dis[2]+dis[2]+1){
				o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				j+=dis[3]+dis[3]+1;
				if(i*i+j*j<=lenx){
					o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				}
			}
			for(j=dis[3]+dis[3]+1 ; i*i+j*j<=lenx ; j+=dis[3]+dis[3]+1){
				o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				j+=dis[2]+dis[2]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				}
			}
			i+=dis[1]+dis[1]+1;
			if(i>len) break;
			for(j=dis[2]+dis[2]+1 ; i*i+j*j<=lenx ; j+=dis[2]+dis[2]+1){
									o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				j+=dis[3]+dis[3]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				}
			}
			for(j=dis[3]+dis[3]+1 ; i*i+j*j<=lenx ; j+=dis[3]+dis[3]+1){
									o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				j+=dis[2]+dis[2]+1;
				if(i*i+j*j<=lenx){
									o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				}
			}
		}
		
		
		memset(cant,0,sizeof(cant));
		memset(cantx,0,sizeof(cantx));
		for(i=dis[1]+dis[1]+1 ; i<=len ; i+=dis[1]+dis[1]+1){
			for(j=dis[2]+dis[2]+1 ; i*i+j*j<=lenx ; j+=dis[2]+dis[2]+1){
					o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				j+=dis[3]+dis[3]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				}
			}
			for(j=dis[3]+dis[3]+1 ; i*i+j*j<=lenx ; j+=dis[3]+dis[3]+1){
									o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				j+=dis[2]+dis[2]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				}
			}
			i+=dis[0]+dis[0]+1;
			if(i>len) break;
			for(j=dis[2]+dis[2]+1 ; i*i+j*j<=lenx ; j+=dis[2]+dis[2]+1){
									o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				j+=dis[3]+dis[3]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cant[o][p]){
						ans++;
						cant[o][p]=1;
					}
				}
			}
			for(j=dis[3]+dis[3]+1 ; i*i+j*j<=lenx ; j+=dis[3]+dis[3]+1){
								o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				j+=dis[2]+dis[2]+1;
				if(i*i+j*j<=lenx){
										o=i,p=j,op=gcd(i,j);
					o/=op;
					p/=op;
					if(!cantx[o][p]){
						ans++;
						cantx[o][p]=1;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
































