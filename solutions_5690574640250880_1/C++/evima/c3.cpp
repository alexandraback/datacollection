// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int R,C,M,N;
int row[12];
int ans[12];
int found;

void dfs(int cur,int sum,int preC){
	if(found)return;
	if(cur==R){
		if(sum!=N)return;
		int a[12][12]={};
		int b[12][12]={};
		rep(i,R){
			rep(j,row[i]) a[i][j] = 1;
		}
		rep(i,R)rep(j,C)if(a[i][j]==1){
			rep2(dy,-1,2)rep2(dx,-1,2){
				if(i+dy<0 || i+dy>=R || j+dx<0 || j+dx>=C)continue;
				if(a[i+dy][j+dx] == 0) b[i][j]=1;
			}
		}
		int ok=1;
		rep(i,R)rep(j,C)if(b[i][j] == 1){
			int ok2 = 0;
			rep2(dy,-1,2)rep2(dx,-1,2){
				if(i+dy<0 || i+dy>=R || j+dx<0 || j+dx>=C)continue;
				if(a[i+dy][j+dx] == 1 && b[i+dy][j+dx] == 0) ok2 = 1;
			}
			if(ok2 == 0){
				ok = 0;
				goto end;
			}
		}
		if(ok){
			found = 1;
			rep(i,R)ans[i] = row[i];
			return;
		}
		end:;
		return;
	}
	rep(i,preC+1){
		row[cur] = i;
		dfs(cur+1, sum+i, i);
	}
}

void main2(){
	cin>>R>>C>>M;
	N = R*C - M;
	if(R==1){
		rep(i,N){
			cout<<(i==0 ? "c" : ".");
		}
		rep(i,M)cout<<"*";
		cout<<endl;
		return;
	}
	if(C==1){
		rep(i,N){
			cout<<(i==0 ? "c" : ".")<<endl;
		}
		rep(i,M)cout<<"*"<<endl;
		return;
	}
	
	if(N==1){
		rep(i,R)rep(j,C){
			cout<<(i==0&&j==0 ? "c":"*");
			if(j==C-1)cout<<endl;
		}
		return;
	}
	
	rep2(i,2,R+1)rep2(j,2,C+1){
		if(i*j==N){
			rep(y,R)rep(x,C){
				if(y+x==0)cout<<"c";
				else cout<<(y<i && x<j ? ".":"*")<<(x==C-1 ? "\n":"");
			}
			goto end;
		}
	}
	rep2(i,2,R+1)rep2(j,2,C+1){
		rep2(ii,1,R-i+1)rep2(jj,1,C-j+1){
			if((i+ii)*(j+jj) - ii*jj == N){
				rep(y,i)rep(x,C){
					if(y+x==0)cout<<"c";
					else cout<<(x<j+jj ? ".":"*")<<(x==C-1 ? "\n":"");
				}
				rep(y,R-i)rep(x,C){
					cout<<(y<ii && x<j ? ".":"*")<<(x==C-1 ? "\n":"");
				}
				goto end;
			}
			if(i+ii<R && j+jj<C && i*(j+jj+1) + ii*(j+jj) + 1*(j) == N){
				rep(y,i)rep(x,C){
					if(y+x==0)cout<<"c";
					else cout<<(x<j+jj+1 ? ".":"*")<<(x==C-1 ? "\n":"");
				}
				rep(y,ii)rep(x,C){
					cout<<(x<j+jj ? ".":"*")<<(x==C-1 ? "\n":"");
				}
				rep(y,R-i-ii)rep(x,C){
					cout<<(y<1 && x<j ? ".":"*")<<(x==C-1 ? "\n":"");
				}
				goto end;
			}
		}
	}
	if(R!=2 && C!=2 && !(N==2 || N==3 || N==5 || N==7)){cout<<R<<" "<<C<<" "<<N<<endl;exit(0);}
	
	cout<<"Impossible"<<endl;
	end:;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<":"<<endl;
		main2();
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
