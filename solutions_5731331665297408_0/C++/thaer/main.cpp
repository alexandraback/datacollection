/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on May 3, 2014, 10:31 AM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>

#define INF 999999999
#define pb push_back
typedef long long LL;

using namespace std;

const int maxN = 9;


vector<string> zip;
vector<vector<int> > graph(maxN);
int outbounds[maxN][maxN];
int parent[maxN];
bool visited[maxN];
string res;
int verts;
void backtrack(int node, int numVisited, int start, string val) {
    int i, j, v;
    //cout<<node<<endl;
    if (numVisited == verts) {
        if (res == "") res = val;
        else res = min(res, val);
    } else {
        for (i = 0; i < graph[node].size(); i++) {
            v = graph[node][i];
            if (v != start) {
                if (!visited[v]) {
                    visited[v] = true;
                    outbounds[v][node] = 1;
                    backtrack(v, numVisited + 1, start, val + zip[v]);
                    visited[v] = false;
                    outbounds[v][node] = 0;
                }
            }
        }
        for (i = 0; i < verts; i++) {
            if (outbounds[node][i]) {
                outbounds[node][i] = 0;
                backtrack(i, numVisited, start, val);
                outbounds[node][i] = 1;
            }
        }
    }
}
/*
 * 
 */
int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        int i, j, k;
        int n, m;
        cin>>n>>m;
        int a, b;
        zip.clear();
        res = "";
        verts = n;
        for (i = 0; i < n; i++) {
            string aux;
            cin>>aux;
            zip.pb(aux);
            graph[i].clear();
            
            visited[i] = false;
            parent[i] = -1;
            for (j = 0; j < n; j++) {
                outbounds[i][j] = 0;
            }
        }
        for (i = 0; i < m; i++) {
            cin>>a>>b;
            a--; b--;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        //cout<<"here"<<endl;
        for (i = 0; i < n; i++) {
            visited[i] = true;
            string v = zip[i];
            backtrack(i, 1, i, v);
            visited[i] = false;
        }
        
        printf("Case #%d: ", tc);
        cout<<res<<endl;
    }
    return 0;
}

