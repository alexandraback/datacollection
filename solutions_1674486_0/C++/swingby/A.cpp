#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<queue>
#include<cctype>
#include<functional>
#include<fstream>
#include<sstream>
#include<complex>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

#define EPS 1.0e-10
#define ALL(t) t.begin(),t.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(it,c) for(__typeof((c).begin()) it = (c).begin();it != (c).end();++it)
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
const ll mod=1000000007LL;
const int SIZE = 1001;

int main(){
	int T;
	cin>>T;
	REP(test,T){
		string ans="Yes";
		int n,m,c;
		cin>>n;
		vector<int>root[SIZE];
		REP(i,n){
			cin>>m;
			REP(j,m){
				cin>>c;
				root[i+1].pb(c);
			}
		}
		bool ok=true;
		REP(k,n){
			queue<int>Q;
			Q.push(k+1);
			int ct[SIZE]={0};
			while(!Q.empty()){
				int b=Q.front();
				Q.pop();
				ct[b]++;
				if(ct[b]>=2){
					ok=false;
					break;
				}
				REP(i,root[b].size()) Q.push(root[b][i]);
			}
		}
		if(ok) ans="No";
		cout<<"Case #"<<test+1<<": "<<ans<<endl;;
	}
	return 0;
}
