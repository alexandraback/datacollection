#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define FOR(a,b) for(int a=0; a<b; a++)
#define ABS(a) ((a)<0 ? (-(a)) : (a))

using namespace std;

vector< int > h;
int hof=1000;

int dmg(int w, int e, int s, int u){
	int did=0;
	for(int i =w+hof; i<e+hof; i++)
		if(h[i]<s){
			did=1;
			if(u)
				h[i]=s;
		}
//	if(u==0)
//		printf("%d %d %d %d\n", w, e, s, did);
	return did;
}

int solveCase(){
	h.resize(0);
	h.resize(2*hof+1);

	vector < int > vw, ve, vs;
	priority_queue < pair < int, int > > poradie;
	
	int N;
	scanf("%d", &N);
//	printf("%d\n", N);
	
	FOR(i, N){
		int d, n, w, e, s, dd, dp, ds;
		scanf("%d", &d);
		scanf("%d", &n);
//		printf("%d\n", n);
		scanf("%d", &w);
		scanf("%d", &e);
		scanf("%d", &s);
		scanf("%d", &dd);
		scanf("%d", &dp);
		scanf("%d", &ds);
		
		FOR(i, n){
			poradie.push(make_pair(-(d+i*dd), vw.size()));
			vw.push_back(w+i*dp);
			ve.push_back(e+i*dp);
			vs.push_back(s+i*ds);
		}
	}
	
//	printf("%d\n", poradie.size());
	
	int ret=0;
	vector < pair < int, int > > dnes;
	while(!poradie.empty()){
		dnes.push_back(poradie.top());
		poradie.pop();
		while(!poradie.empty() && poradie.top().first == dnes[0].first){
			dnes.push_back(poradie.top());
			poradie.pop();
		}
//		printf("Dnes: %d %d %d\n",dnes[0].first, dnes.size(), poradie.size());
		
		FOR(i, dnes.size())
			ret+=dmg(vw[dnes[i].second], ve[dnes[i].second], vs[dnes[i].second], 0); 

		FOR(i, dnes.size())
			dmg(vw[dnes[i].second], ve[dnes[i].second], vs[dnes[i].second], 1); 
		dnes.resize(0);
	}
	
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(i,T)
		printf("Case #%d: %d\n", i+1, solveCase());	
}
