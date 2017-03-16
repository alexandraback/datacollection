#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

vector<pair<LL, int> > boxes;
vector<pair<LL, int> > toys;
int N, M;
LL DP[105][105], compDP[105][105];
LL falta[105][105];

LL solve2(){
	F(i, N){
		F(j, M){
			compDP[i][j] = 0LL;
			DP[i][j] = 0LL;
			falta[i][j] = toys[j].first;
		}
	}
	LL maxi = 0LL, aux, aux2;
	F(i, N){
		F(j, M){
			if(boxes[i].second == toys[j].second){
				compDP[i][j] = aux2 = DP[i][j] = aux = min(boxes[i].first, toys[j].first);
				F(k, i){
					DP[i][j] = max(DP[i][j], DP[k][j] + aux);
					if(compDP[i][j] < compDP[k][j] + aux2){
						compDP[i][j] = compDP[k][j] + aux2;
						falta[i][j] = falta[k][j] - aux2;
					}
				}
			}
			else if(j){
				DP[i][j] = DP[i][j-1];
				compDP[i][j] = compDP[i][j-1];
				falta[i][j] = falta[i][j];
			}
			maxi = max(maxi, compDP[i][j]);
			maxi = max(maxi, DP[i][j]);
		}
	}
	return maxi;
}

void solve(int caso){
	int b;
	LL a;
	scanf("%d %d", &N, &M);
	boxes.clear();
	toys.clear();
	F(i, N){
		cin>>a>>b;
		boxes.PB(MP(a, b));
	}
	F(i, M){
		cin>>a>>b;
		toys.PB(MP(a, b));
	}
	cout<<"Case #"<<caso<<": "<<solve2()<<endl;
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("C-small-attempt0.in.txt", "r", stdin);
	//freopen("C-large.in.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

