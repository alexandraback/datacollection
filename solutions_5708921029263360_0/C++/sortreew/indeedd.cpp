#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define S second
#define F first
using namespace std;
typedef long long LL;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef pair<ut,pr> ppr;
typedef vector<ppr> Vppr;
typedef queue<pr> PQ;
const int INF=1<<30;
const int SIZE=5+1e+5;
const LL p=7+1e9;
int stock[12][12][12];
int J,P,S,K;
bool solved=false;
int ans=0;
int solve(int j,int p,int s,int users){
	if(j>J) return solve(1,p+1,s,users);
	if(p>P) return solve(j,1,s+1,users);
	if(s>S){
		if(solved && users==ans) return INF;
		return users;
	}
	int maxim=0;
	stock[j][p][0]++;
	stock[j][0][s]++;
	stock[0][p][s]++;
	if(stock[j][0][s]>K || stock[0][p][s]>K || stock[j][p][0]>K);
	else{
		maxim=max(maxim,solve(j+1,p,s,users+1));
		if(maxim>=INF){
			cout << j << " " << p <<" " << s << endl;
			return maxim;
		}
	}
	stock[j][p][0]--;
	stock[j][0][s]--;
	stock[0][p][s]--;
	maxim=max(maxim,solve(j+1,p,s,users));
	return maxim;
}
int main(){
	int T;
	cin >> T;
	FOR(d,1,T+1){
		solved=false;
		ans=0;
		cout << "Case #"<<d <<": ";
		cin >> J >> P >> S >> K;
		ans=solve(1,1,1,0);
		cout << ans << endl;
		solved=true;
		solve(1,1,1,0);
		REP(i,10)REP(j,10)REP(k,10){
			stock[i][j][k]=0;
		}
		/*
		int maxim=0,maxer=0;
		for(LL i=0;i<(1LL<<(S+P+J));i++){
			int able=0;
			if(check(i)){
				REP(j,S+P+J){
					if(i&(1<<j)) able++;
				}
				maxim=max(maxim,able);
				maxer=i;
			}
		}
		
		int nowS=1;
		REP(i,K)
			FOR(j,1,J+1)
				FOR(k,1,P+1){
					if(nowS>S) goto outs;
					
				}
		
		PQ qj,qp;
		FOR(i,1,S+1){

			FOR(i,1,J+1) FOR(j,1,P+1){
				stock[i][j]=K;	
			}		
			qj.clear();
			qp.clear();
			FOR(j,1,J+1){
				qj.push(pr(K,j));
			}
			FOR(j,1,P+1){
				qp.push(pr(K,j));
			}
			while(true){
				int now=qj.front().S,times=qj.front().F;
				bool sucusess=false;
				qj.pop();
				if(times==0) continue;
				REP(j,P){
					int nowp=qp.front().S,timesp=qu.front().S;
					qp.pop();
					if(stock[now][nowp]==0){
						qp.push(pr(times,qp));
						continue;
					}
					sucusess=true;
					stock[now][nowp]--;

					break;
				}
				
				if(sucusess)
					qj.push(pr(times-1,now));
				else
					qj.push(pr(times,now));
				
				
			}
		}
		*/
	}

	return 0;
}