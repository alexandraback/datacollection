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

int perm[8];

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

	rep(i,N)perm[i] = i;
	int can[111];
	int lis[111],l;
	int ok = 0;
	do{
		int dbg = 1;
		rep(i,N){
			if(q[perm[i]] != i)dbg = 0;
		}
		fill(can,can+N,0);
		can[s] = 1;
		int city = s;
		lis[0] = s;
		l = 1;
		rep(i,N-1){
			int dest = q[perm[i+1]];
			while(1){
				/*if(dbg){
					cout<<"dbg "<<i<<" "<<city<<endl;
				}*/
				if(mat[city][dest] == 1){
					can[dest] = 1;
					city = dest;
					lis[l++] = city;
					break;
				}
				else{
					can[city] = 0;
					if(l <= 1) goto fail;
					l--;
					city = lis[l-1];
				}
			}
		}
		ok = 1;
		//cout<<"OK"<<endl;
		//rep(i,N)cout<<perm[i]<<" ";cout<<endl;
		rep(i,N)cout<<postal[q[perm[i]]];cout<<endl;
		break;
		fail:;
	}while(next_permutation(perm+1,perm+N));
	if(!ok){
		cout<<N<<" "<<M<<endl;
	}
	assert(ok);
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
