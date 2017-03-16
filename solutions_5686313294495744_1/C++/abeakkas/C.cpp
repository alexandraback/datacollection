/*
 * abeakkas
 * Google CodeJam 2016 - Round 1B
 * Problem C
 * I hope it is correct.
 * This is the first ever problem that I've solved with a boss algorithm.
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

// #define pr pair<ll,ll>
// #define vpr vector<pair<ll,ll> >

// Code snippets:
// (int*)calloc(1000000, sizeof(int));
// (int*)malloc(1000000 * sizeof(int));
// cout << setprecision(20);

using namespace std; 
ifstream fin("C.in");
ofstream fout("C.out");

int graph[1000][1000];

int bip(int m, int N, int seen[], int matchR[]) {
    for(int n = 0; n < N; n++) {
        if(graph[m][n] && !seen[n]) {
            seen[n] = 1;
            if(matchR[n] < 0 || bip(matchR[n], N, seen, matchR)) {
                matchR[n] = m;
                return 1;
            }
        }
    }
    return 0;
}
// maximum bipartite matching
int maxmatch(int M, int N) {
    int matchR[N];
    for(int i = 0; i < N; i++) matchR[i] = -1;
    int res = 0;
    for(int m = 0; m < M; m++) {
        int seen[N];
        for(int i = 0; i < N; i++) seen[i] = 0;
        if(bip(m, N, seen, matchR)) {
            res++;
        }
    }
    return res;
}

int main(){
    int T;
    fin >> T;
    for(int iT = 1; iT <= T; iT++) {
        int N;
        int res = 0;
        fin >> N;
        vector<string> lefts, rights;
        vector<pair<int, int> > edges;
        for(int i = 0; i < N; i++) {
            string l, r;
            fin >> l >> r;
            int li = find(lefts.begin(), lefts.end(), l) - lefts.begin();
            int ri = find(rights.begin(), rights.end(), r) - rights.begin();
            if(li == lefts.size()) {
                lefts.push_back(l);
            }
            if(ri == rights.size()) {
                rights.push_back(r);
            }
            pair<int,int> e = make_pair(li,ri);
            if(find(edges.begin(), edges.end(), e) == edges.end()) {
                edges.push_back(e);
            } else {
                res++;
            }
        }
        for(int i = 0; i < lefts.size(); i++) {
            for(int j = 0; j < rights.size(); j++) {
                if(find(edges.begin(), edges.end(), make_pair(i, j)) == edges.end()) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = 1;
                }
            }
        }
        int match = maxmatch(lefts.size(), rights.size());
        res += edges.size() - (lefts.size() + rights.size() - match);
        /*for(int i = 0; i < edges.size(); i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }*/
        fout << "Case #" << iT << ": " << res << endl;
    }
	return 0;
}
