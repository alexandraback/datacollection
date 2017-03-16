#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

ifstream cin("/Users/Nagi2/Downloads/GCJ2016/C-Large.in");
ofstream cout("/Users/Nagi2/Downloads/qwertyC.txt");




using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)

#define REPD(i,a,b) for (int i = (a); i >= (b); --i)

#define FORI(i,n) REP(i,1,n)

#define FOR(i,n) REP(i,0,int(n)-1)

#define mp make_pair

#define pb push_back

#define pii pair<int,int>

#define vi vector<int>

#define ll long long

#define SZ(x) int((x).size())

#define DBG(v) cerr << #v << " = " << (v) << endl;

#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)

#define fi first

#define se second

#define N 1005

int n; // IN: number of vertices

bool edge[N][N]; // IN: adjacency matrix (can be changed to vectors if needed)

int mate[N]; // OUT: matched vertex (-1 = none)

int label[N], base[N], prev1[N], prev2[N];

bool mark[N];

bool prepare (int v) {
    
    while(1) {
        
        mark[v] = !mark[v];
        
        if (mate[v] == -1) return mark[v];
        
        v = base[prev2[mate[v]]];
        
    }
    
}

int shrink (int v, int b1, int b2, queue<int> &Q) {
    
    while (mark[v]) {
        
        prev1[v] = b1; prev2[v] = b2;
        
        mark[mate[v]] = 1;
        
        Q.push(mate[v]);
        
        v = base[prev2[mate[v]]];
        
    }
    
    return v;
    
}

bool make_blos (int i, int j, int bi, int bj, queue<int> &Q) {
    
    if (label[i]!=1 || i==j) return 0;
    
    if (prepare(i), prepare(j)) return 1;
    
    int b = (shrink(i, bi, bj, Q), shrink(j, bj, bi, Q));
    
    FOR(v,n) if (mark[base[v]]) base[v] = b;
    
    return 0;
    
}

void rematch(int i, int j) {
    
    int nxt = mate[i];
    
    mate[i] = j;
    
    if (nxt==-1) return;
    
    mate[nxt] = -1;
    
    rematch(prev2[nxt], prev1[nxt]);
    
    rematch(prev1[nxt], prev2[nxt]);
    
}

bool augment() {
    
    queue<int> Q;
    
    FOR(i,n) {
        
        label[i] = mate[i]==-1;
        
        if (mate[i]==-1) Q.push(i);
        
        mark[i] = 0;
        
        base[i] = i;
        
    }
    while (!Q.empty()) {
        
        int cur = Q.front(); Q.pop();
        
        FOR(i,n) if (edge[cur][i] && i!=mate[cur]) {
            
            if (!label[i]) {
                
                label[i] = -1;
                
                label[mate[i]] = 1;
                
                Q.push(mate[i]);
                
                prev1[i] = i; prev2[i] = cur;
                
            } else if (make_blos(base[i], base[cur], i, cur, Q)) {
                
                rematch(i, cur); rematch(cur, i);
                
                return 1;
                
            }
            
        }
        
    }
    
    return 0;
}

    int compute_gcm() { // returns the cardinality of maximum matching
        
        fill_n(mate, n, -1);
        
        int res = 0;
        
        while (augment()) ++res;
        
        return res;
    }


       

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    //don't forget to change the #define constant for N;
    for(int t =0;t<T;t++){
        int nn;
        cin >> nn;
        pair<string,string> pss;
        vector <pair <string,string> > vp;
        vector <string> vs;

        map<string,int> inds;
        map<string,int> inds2;
        int id=0;
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                edge[i][j] = false;
            }
        }
        for(int i=0;i<nn;i++){
            string s;
            cin >> pss.first >> pss.second;
            int k,l;
            if(inds.count(pss.first)==0){
                vs.push_back(pss.first);
                inds[pss.first] = id;
                
                id++;
                
                
            }
            if(inds2.count(pss.second)==0){
                vs.push_back(pss.second);
                inds2[pss.second] = id;
                
                id++;
                
            }
            //MUST INITIALIZE EDGE to FAlse
            edge[inds[pss.first]][inds2[pss.second]] = true;
            edge[inds2[pss.second]][inds[pss.first]] = true;

            
            
            
        }
        n= id;
        int ans = compute_gcm();
        
        //total number of edges: nn
        //total number of vertices: id
        //max matching: ans
        //number of edges to add non fake:
        // (id-2*ans)
        //total number of fake nn-ans-(id-2*ans) = nn -id+ ans;
        cout << "Case #" << t+1 << ": "<< nn-id+ans <<endl;
        
    }
    return 0;
}
