#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (a); i >= (b); i--)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define itr iterator

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

int dist[1000010];

int main(){
	int nc;
	cin >> nc;
	FOR(caso, 1, nc){
		REP(i, 1000010)
				dist[i] = -1;
		dist[1] = 1;
		queue<int> q;
		q.push(1);
		int n;
		cin >> n;
		while(!q.empty()){
			int prox = q.front();
			q.pop();
			if(dist[prox+1] == -1 && prox < 1000000){
				q.push(prox+1);
				dist[prox+1] = dist[prox] + 1;
			}
			int rev = 0;
			int cp = prox;
			while(cp > 0){
				rev *= 10;
				rev += cp % 10;
				cp /= 10;
			}
			if(dist[rev] == -1 && rev <= 1000000){
				q.push(rev);
				dist[rev] = dist[prox] + 1;
			}
		}
		cout << "Case #" << caso << ": " << dist[n]<< endl;
	}
	return 0;
}