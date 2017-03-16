#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;


#define li			long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)	for(li i=(li)(start);i<((li)(to));i++)
#define pb			push_back
#define sz(v)		((li)(v).size())
#define bgn(v)		((v).begin())
#define eend(v)		((v).end())
#define allof(v)	(v).begin(), (v).end()
#define dodp(v,n)		memset(v,(li)n,sizeof(v))
#define bit(n)		(1ll<<(li)(n))
#define mp(a,b)		make_pair(a,b)
#define rin	rep(i,n)
#define rjm	rep(j,m)
#define VV			vector


#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)		idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)		idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)	for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)		idp p2((x).F, (x).S)
#define dump(x,n)	idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)	idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)	idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)	idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}



#define EPS 1e-10
#define ETOL 1e-8
#define MOD 1000000007

#define PRIME_MAX 1000001

typedef pair<li, li> PI;


vector<li> edge[22];
vector<PI> edge_pair;
li b,m;
li dp[0];

void solve(li case_num){
	cout<<"Case #"<<case_num+1<<": ";
	cin>>b>>m;
	rep(i,b){
		edge[i].clear();
		dp[i]=0;
	}
	edge_pair.clear();
	rep(i,b){
		repp(j,i+1,b){
			edge_pair.pb({i,j});
		}
	}
	rep(i,bit(b*(b-1)/2)){
		// construct graph
		rep(j,b){
			edge[j].clear();
			dp[j]=0;
		}
		rep(j,b*(b-1)/2){
			if((i&bit(j))>0){
				edge[edge_pair[j].F].pb(edge_pair[j].S);
			}
		}
		dp[0]=1;
		rep(j,b){
			rep(k,sz(edge[j])){
				li next=edge[j][k];
				dp[next]+=dp[j];
			}
		}
		if(dp[b-1]==m){
			puts("POSSIBLE");
			rep(j,b){
				rep(k,b){
					if(find(allof(edge[j]),k) != edge[j].end()){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
				cout<<endl;
			}
			return;
		}
	}
	puts("IMPOSSIBLE");
}

int main(int argc, char *argv[]){
	li t;
	cin>>t;
	rep(case_num,t){
		solve(case_num);
	}
	return 0;
}
