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

int N,M;
int p[111];
int q[111];
string postal[111];
int mat[111][111];

int vis[111];
bool forbid[111];
void dfs(int cur){
	vis[cur] = 1;
	rep(i,N)if(mat[cur][i] && !vis[i] && !forbid[i]){
		dfs(i);
	}
}

void main2(){
	cin>>N>>M;
	vector<pair<string,int>> v;
	rep(i,N){
		cin>>postal[i];
		v.pb(mp(postal[i],i));
	}
	sort(v.begin(),v.end());
	int s = v[0].sec;
	rep(i,N){
		p[v[i].sec] = i;
		q[i] = v[i].sec;
	}
	memset(mat,0,sizeof(mat));
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		mat[a][b]=mat[b][a] =1;
	}

	int lis[111],l;
	lis[0] = s;
	l = 1;
	int used[111] = {};
	used[s] = 1;
	string ans;
	ans += postal[s];
	const bool dbg = 0;
	memset(forbid,0,sizeof(forbid));
	rep(t,N-1){
		if(dbg){
			cout<<"List("<<l<<"):";
			rep(i,l)cout<<lis[i]<<" ";cout<<endl;
		}

		vector<int> rem;
		int back = l-1;
		for(int i = l-2; i >= 0; i--){
			//rem.pb(mp(lis[i],lis[i+1]));
			//mat[lis[i]][lis[i+1]] = mat[lis[i+1]][lis[i]] = 0;
			forbid[lis[i+1]] = 1;
			rem.pb(lis[i+1]);
			memset(vis,0,sizeof(vis));
			dfs(lis[i]);
			int ok = 1;
			rep(j,N) if(!used[j] && !vis[j]){
				//cout<<t<<" "<<lis[i]<<" -> "<<j<<endl;
				/*rep(ii,N)rep(jj,N){
					cout<<mat[ii][jj]<<(jj == N-1 ? "\n":" ");
				}*/
				ok=0;break;
			}
			if(!ok)break;
			back = i;
		}
		/*rep(i,sz(rem)){
			mat[rem[i].fir][rem[i].sec] = mat[rem[i].sec][rem[i].fir] = 1;
		}*/
		//memset(forbid,0,sizeof(forbid));
		rep(i,sz(rem))forbid[rem[i]] = 0;
		if(dbg)cout<<t<<" back : "<<back<<endl;
		
		int dst = -1;
		int backto = -1;
		rep(i,N){
			if(used[q[i]])continue;
			for(int j = l-1; j>=back; j--){
				//cout<<lis[j]<<endl;
				if(mat[lis[j]][q[i]]){
					backto = j;break;
				}
			}
			if(backto != -1){
				dst = q[i];
				break;
			}
		}
		//cout<<t<<" "<<dst<<endl;
		if(dst == -1){
			cout<<N<<" "<<M<<endl;
		}
		assert(dst != -1);
		ans += postal[dst];
		used[dst] = 1;
		//for(int i = l-2; i >= backto; i--){
		//	mat[lis[i]][lis[i+1]] = mat[lis[i+1]][lis[i]] = 0;
		//}
		for(int i = l-1; i > backto; i--){
			forbid[lis[i]] = 1;
		}
		l = backto + 1;
		lis[l++] = dst;
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
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
