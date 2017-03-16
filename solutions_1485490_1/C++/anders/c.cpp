#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<unsigned long long,int> pii;
typedef unsigned long long ull;

pii N[100];
pii M[100];
int n,m;

map<pair<pair<int,int>,long long>, long long> dp;

ull magic(int Ni,int Mi, long long val){
	if(Ni==n || Mi==m) return 0;
	pii p=make_pair(Ni,Mi);
	pair<pair<int,int>,long long> d = make_pair(p,val);
	if(dp.find(d)!=dp.end()) return dp[d];
	int Nt=N[Ni].second,Mt=M[Mi].second;
	long long Nv=N[Ni].first,Mv=M[Mi].first;
	if(val>0){
		Nv=val;
	}
	if(val<0){
		Mv=-val;
	}

	double ans=0;
	if(Nt!=Mt){
		if(val>0){
			ans=max(magic(Ni+1,Mi,0),magic(Ni,Mi+1,val));
		}else{
			ans=max(magic(Ni+1,Mi,val),magic(Ni,Mi+1,0));
		}
	}else{
		if(Nv==Mv){
			ans=Nv+magic(Ni+1,Mi+1,0);
		}
		if(Nv>Mv){
			ans=Mv+magic(Ni,Mi+1,Nv-Mv);
		}
		if(Nv<Mv){
			ans=Nv+magic(Ni+1,Mi,-(Mv-Nv));
		}
	}
	dp[d]=ans;
	return ans;
}

int main(){
	int cases;
	cin >> cases;
	for(int c=1; c<=cases; ++c){
		printf("Case #%d: ",c);
		dp.clear();
		cin >> n >> m;
		for(int i=0; i<n; ++i){
			ull num;
			int type;
			cin >> num >> type;
			N[i]=make_pair(num,type);
		}
		for(int i=0; i<m; ++i){
			ull num;
			int type;
			cin >> num >> type;
			M[i]=make_pair(num,type);
		}
		
		printf("%llu\n", magic(0,0,0));

		
	}

	return 0;
}

