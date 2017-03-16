#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>

using namespace std;

vector<int> V(100000);
long long solve(){
	long long res=0ll;
	long long E,e,R,N;
	cin >> E >> R >> N; e = E;
	V.resize(N);
	for(int i=0;i<N;i++) cin >> V[i];
	long long b,dist,best;
	for(int i=0;i<N;i++){
		b=-1;
		for(int j=i;j<N;j++)if(V[i]<V[j]){ b =j; break; }
		dist = b-i;
		if(b!=-1)best = min(e,max(e-(E-R*dist),0ll));
		else best = e;
		e -= best;
		res+=best*V[i];
		e+=R;
	}
	return res;
}
int main(void){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		cout << "Case #" << t <<": "<< solve() << endl;
	}
}