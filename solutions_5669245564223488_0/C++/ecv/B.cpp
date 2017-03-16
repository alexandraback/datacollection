// CF.cpp: define el punto de entrada de la aplicaci?n de consola.
#pragma warning ( disable: 4996 )
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <iostream>

typedef std::pair<int,int> ii;
typedef long long int Int;
typedef unsigned long long int uInt;
typedef std::vector<int> vi;
typedef std::vector<double> vd;
typedef std::vector<vi> vvi;
typedef std::vector<std::string> vs;
typedef std::vector<ii> vii;
#define sz(X) int((X).size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,v) for(int i = 0; i < int(v.size()); ++i)
#define ALL(v) v.begin(),v.end()
using namespace std;
Int factorial(int n){
	if(n==0) return 1L;
	return Int(n)*factorial(n-1);
}
int main(){
	FILE *f = freopen("in.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	scanf("%d",&ntsts);
	for(int ntst = 1; ntst<=ntsts; ++ntst){
		int N; 
		Int Res=0;
		scanf("%d\n",&N);
		vs S(N);
		char buffer[200];
		for(int i = 0; i<N; ++i){
			scanf("%s",&buffer); S[i]=buffer;
		}
		vector<Int> Num(127);
		vi L(127,-1),R(127,-1),E(127);
		vi used(N);
		vi mid(127);
		for(int i = 0; i<N; ++i){
			string s = S[i];
			if(s[0] == s.back()){
				for(int j = 0; j<s.length(); ++j)
					if(s[j]!=s[0]) goto fail;
			} else {
				for(int j = 1; j+1<s.length(); ++j)
					if(s[j] != s[j-1] && s[j] != s.back() )
						mid[s[j]] ++;
					else if(s[j]!=s[j+1]&&s[j]!=s[0])
						mid[s[j]] ++;
			}
		}
		for(int i = 0; i<N; ++i){
			string s = S[i];
			if(s[0] != s.back()){
				if(mid[s[0]] > 0) goto fail;
				if(L[s[0]]!=-1) goto fail;
				if(mid[s.back()] > 0) goto fail;
				if(R[s.back()]!=-1) goto fail;
				L[s[0]] = i;
				R[s.back()] = i;
			} else {
				if(mid[s[0]]) goto fail;
				E[s[0]]++;
			}
		}

		Int T = 1L;;
		int num = 0;
		for(int j = 0; j<127; ++j){
			if( R[j] == -1 && L[j] == -1){
				T *= factorial(E[j]);
				if( E[j] > 0)
					num++;
			}
		}
		for(int i = 0; i<N; ++i){
			if(S[i][0] != S[i].back() && !used[i]){
				Int ac = 1L;
				if(!used[i]){
					used[i] = true;
					int j = i;
					while(1){
						if(L[S[j].back()]==-1)
							break;
						int k = L[S[j].back()];
						if(used[k]) goto fail;
						used[k] = 1;
						ac *= factorial(E[S[j].back()]);
						j = k;
					}
					ac *= factorial(E[S[j].back()]);
					j = i;
					while(1){
						char c = S[j].front();
						if(R[c]==-1)
							break;
						int k = R[S[j][0]];
						if(used[k]) goto fail;
						used[k] = 1;
						ac *= factorial(E[S[j][0]]);
						j = k;
					}
					ac *= factorial(E[S[j][0]]);
				}
				T *= ac;
				num++;
			}
		}
		T *= factorial(num);
		Res = T;

		fail:
		cout<<"Case #"<<ntst<<": "<<Res<<endl;
	}
	//printf("%I64d\n", nr);
	return 0;
}
