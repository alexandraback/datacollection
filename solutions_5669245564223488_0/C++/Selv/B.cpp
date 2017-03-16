#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define SORT(X) sort(X.begin(),X.end())
#define fi first
#define se second

const ll MOD = 1000000007;

int te;
string S[110];
int Roz[110];
int zaj[30];
ll zaj2[30];
int NAS[110];
string N[110];

int check(int g){
	int posz = g;
	int WHERE = g;
	while(1){
		WHERE = NAS[WHERE];
		if(WHERE == posz) return 0;
		if(WHERE == -123) return 1;
	}
	return 1;
}

void test(){
	FOR(i,30) zaj[i] = 0;
	FOR(i,30) zaj2[i] = 0;
	int n;
	cin>>n;
	FOR(i,n){
		NAS[i] = -123;
		cin>>S[i];
		Roz[i] = S[i].size();
		N[i] = S[i][0];
		int last = 0;
		FOR(j,Roz[i]) if(S[i][j] != N[i][last]){
			N[i] += S[i][j];
			last++;
		}
		N[i][last+1] = 0;
		Roz[i] = last+1;
	//	cout << N[i][0] << N[i][Roz[i]-1] << " ";
	}
	printf("Case #%d: ",++te);
	FOR(i,n){
		FOR(j,Roz[i]) if(j != 0 && j != Roz[i]-1) zaj[N[i][j]-'a'] ++;
		if(Roz[i] > 1 && (N[i][0] == N[i][Roz[i]-1]) ){
			printf("0\n");
			return;
		}
	}
	FOR(i,n){
		if(zaj[N[i][0]-'a'] || zaj[N[i][Roz[i]-1]-'a']){
			printf("0\n");
			return;
		}
	}
	ll ans = 1;
	ll roz = n;
	FOR(i,n){
		if(Roz[i] == 1){
			zaj2[N[i][0]-'a']++;
			ans = (ans * zaj2[N[i][0]-'a']) % MOD;
			int CZ = 0;
			FOR(j,n) if((j > i || Roz[j] != 1) && (N[j][0] == N[i][0] || N[j][Roz[j]-1] == N[i][0])) CZ = 1; 	
			roz -= CZ;
		//	DBG(roz)
			continue;
		}
		else
		FOR(j,n){
			if(i == j) continue;
			if(Roz[j] != 1 && (N[i][0] == N[j][0] || N[i][Roz[i]-1] == N[j][Roz[j]-1])){
				printf("0\n");
				return;
			}
			if(Roz[j] > 1){
				if(N[i][0] == N[j][Roz[j]-1]){
					roz--;
					NAS[j] = i;
					if(check(j) == 0){
						printf("0\n");
						return;
					}
				}
			}
		}
		
	}
	
	FOR(i,30) if(zaj[i] > 1) {
		printf("0\n");
		return;
	}
//	DBG(roz)
//	DBG(ans)
	while(roz){
		ans = (ans * roz) % MOD;
		roz--;
	}
	
	printf("%lld\n",ans);
	
}

int main () {
	int t;
	cin>>t;
	while(t--) test();
}

/*
1
9
uueeennnbbdjjxx oooooooogg sssssaaaaaww iiiiiiiiiiiii yyssss iiiirrrryyyyy ggghhhfiii kkkqqqqzzzzzzzmmmm pppppppppccccc
*/
