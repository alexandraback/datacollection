#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

bool hopcroftKarp_dfs(int a, int layer, const vector<vi>& AtoB,
    vi& BtoA, vi& layerA, vi& layerB){
    if(layerA[a] != layer) return false;
    layerA[a] = -1;
    int layerNextB = layer + 1, layerNextA = layer + 2;
    rep(i,0,AtoB[a].size()){
        int b = AtoB[a][i];
        if(layerB[b] != layerNextB) continue;
        layerB[b] = -1;
        if(BtoA[b] == -1 || hopcroftKarp_dfs(BtoA[b],layerNextA,AtoB,BtoA,layerA,layerB)){
                    return BtoA[b] = a, true;}
    }
    return false;
}

int hopcroftKarp(const vector<vi>& AtoB, vi& BtoA){
    int incrMatching = 0, bfsAEnd, bfsANextEnd;
    vi layerA(AtoB.size()), layerB(BtoA.size()),
        bfsA(AtoB.size()), bfsANext(AtoB.size());
    while(5){
        fill(layerA.begin(), layerA.end(), 0);
        fill(layerB.begin(), layerB.end(), -1);
        rep(b,0,BtoA.size())
            if(BtoA[b] != -1) layerA[BtoA[b]] = -1;
        bfsAEnd = 0;
        rep(a,0,AtoB.size())
            if(layerA[a] == 0) bfsA[bfsAEnd++] = a;
        for(int layerNext = 1;; ++layerNext){
            bool layerIsLast = false;
            bfsANextEnd = 0;
            rep(bfsAPos,0, bfsAEnd){
                int a = bfsA[bfsAPos];
                rep(i,0,AtoB[a].size()){
                    int b = AtoB[a][i];
                    if(BtoA[b] == -1){
                        layerB[b] = layerNext;
                        layerIsLast = true;
                    }
                    else if(BtoA[b] != a && layerB[b]==-1){
                        layerB[b] = layerNext;
                        bfsANext[bfsANextEnd++] = BtoA[b];
                    }
                }
            }
            if(layerIsLast) break;
            if(!bfsANextEnd) return incrMatching;
            ++layerNext;
            rep(bfsANextPos,0, bfsANextEnd){
                int a = bfsANext[bfsANextPos];
                layerA[a] = layerNext;
            }
            bfsAEnd = bfsANextEnd;
            bfsA.swap(bfsANext);
        }
        rep(a,0, AtoB.size())
            if(hopcroftKarp_dfs(a,0,AtoB,BtoA,layerA,layerB))
                ++incrMatching;
    }
}

int main(){
	srand(5);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	rep(t,1,T+1){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		vector<vector<string> > tops(n, vector<string>(2));
		vector<vi> rtop(n,vi(2));
		rep(i,0,n) rep(j,0,2) cin >> tops[i][j];
		map<string,int> ren[2];
		int ix[2] = {};
		rep(i,0,2) rep(j,0,n){
			if(!ren[i].count(tops[j][i]))
				ren[i][tops[j][i]] = ix[i]++;
			rtop[j][i] = ren[i][tops[j][i]];
		}
		vector<vi> AtoB(ix[0]);
		vi BtoA(ix[1],-1);
		rep(i,0,n) AtoB[rtop[i][0]].pb(rtop[i][1]);
		cout << n - (ix[0] + ix[1] - hopcroftKarp(AtoB,BtoA)) << endl;
	}
}