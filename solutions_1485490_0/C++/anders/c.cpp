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

ull dp[101][101];

ull magic(int Ni,int Mi, ull Na, ull Ma){
	if(Ni==n || Mi==m) return 0;
	int Nt=N[Ni].second,Mt=M[Mi].second;
	if(Nt!=Mt)
		return max(magic(Ni+1,Mi,N[Ni+1].first,Ma),magic(Ni,Mi+1,Na,M[Mi+1].first));
	if(Na>Ma)
		return Ma+magic(Ni,Mi+1,Na-Ma,M[Mi+1].first);
	if(Na<Ma)
		return Na+magic(Ni+1,Mi,N[Ni+1].first,Ma-Na);
	return Na+magic(Ni+1,Mi+1,N[Ni+1].first,M[Mi+1].first);
}

int main(){
	int cases;
	cin >> cases;
	for(int c=1; c<=cases; ++c){
		printf("Case #%d: ",c);
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
		
		printf("%llu\n", magic(0,0,N[0].first,M[0].first));

		
	}

	return 0;
}

