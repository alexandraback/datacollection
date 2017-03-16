// author: misof
// language: c++
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
//template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
//template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
//template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE

class MaximumMatching {
    public:
    int A, B;
    vector<int> matching;
    vector< vector<int> > G;
    MaximumMatching(int A=0, int B=0) : A(A), B(B) { G.resize(A); }
    void addEdge(int left, int right);
    int getMatchingSize();
};
// {{{
inline void MaximumMatching::addEdge(int left, int right) { 
  if (left>=A) G.resize(left+1);
  A=max(A,left+1);
  B=max(B,right+1);
  G[left].push_back(right);
}

int MaximumMatching::getMatchingSize() {
  // greedy matching
  matching.clear(); matching.resize(B,-1);
  for (int a=0; a<A; ++a) FOREACH(it,G[a]) if (matching[*it]==-1) { matching[*it]=a; break; }

  // improvements
  while (1) {
    vector<bool> done(B,false);
    vector<int> lpred(A,-2), first(B,-1), next, rpred, unmatched, layer, temp;

    for (int b=0; b<B; ++b) if (matching[b]>=0) lpred[matching[b]]=-1;
    for (int a=0; a<A; ++a) if (lpred[a]==-2) layer.push_back(a);
    
    // repeatedly extend layering structure by another pair of layers
    while (!layer.empty() && unmatched.empty()) {
      temp.clear();
      FOREACH(u,layer) FOREACH(v,G[*u]) if (!done[*v]) {
        int n = rpred.size(), s = first[*v];
        rpred.push_back(*u);
        next.push_back(s);
        first[*v] = n;
        if (s==-1) temp.push_back(*v);
      }
      layer.clear();
      FOREACH(b,temp) {
        done[*b] = true;
        if (matching[*b]==-1) unmatched.push_back(*b); else {
          layer.push_back( matching[*b] );
          lpred[ matching[*b] ] = *b;
        }
      }
    }

    // # did we finish layering without finding any alternating paths?
    if (unmatched.empty()) {
      int result = 0;
      FOREACH(it,matching) result += (*it >= 0);
      return result;
    }

    // FOREACH(it,unmatched) recurse(*it);
    FOREACH(it,unmatched) {
      stack<int> vrchol, hrana, oldhrana;
      vrchol.push(*it); hrana.push(first[*it]); oldhrana.push(first[*it]);
      while (!vrchol.empty()) {
        int kde=vrchol.top(), ako=hrana.top(); 
        vrchol.pop(); hrana.pop(); oldhrana.pop();
        if (ako == -1) continue;
        vrchol.push(kde); hrana.push(next[ako]); oldhrana.push(ako);
        int kam = rpred[ako], p = lpred[kam];
        lpred[kam] = -1;
        if (p==-1) continue;
        if (p==-2) {
          while (!vrchol.empty()) { 
            matching[ vrchol.top() ] = rpred[oldhrana.top()];
            vrchol.pop(); oldhrana.pop();
          }
          break;
        }
        vrchol.push(p); hrana.push(first[p]); oldhrana.push(first[p]);
      }
    }
  }
}
// }}}

vector<int> FAIL {-1};

vector<bool> get_reachable(const vector< vector<int> > &G, int start) {
    int N = G.size()-1;
    vector<bool> seen(N+1,false);
    seen[start]=true;
    queue<int> Q; Q.push(start);
    while (!Q.empty()) {
        int kde = Q.front(); Q.pop();
        for (auto kam : G[kde]) if (!seen[kam]) { seen[kam]=true; Q.push(kam); }
    }
    return seen;
}

vector<int> solve(const vector<int> &unlocks, const vector<int> &chest_ids, const vector< vector<int> > &keys) {
    // returns the solution if possible, {-1} if impossible
    // DEBUG(unlocks); DEBUG(chest_ids); DEBUG(keys);
    
    int N = unlocks.size()-1;
    if (N==0) return vector<int>();

    vector< pair<int,int> > all_keys; // chest id or 0, key id
    for (int n=0; n<=N; ++n) for (int i=0; i<int(keys[n].size()); ++i) all_keys.push_back(make_pair(n,i));
    MaximumMatching MM(N+1,all_keys.size());
    for (int n=1; n<=N; ++n) for (int i=0; i<int(all_keys.size()); ++i) { auto ak=all_keys[i]; if (keys[ak.first][ak.second] == unlocks[n]) MM.addEdge(n,i); }
    int sz = MM.getMatchingSize();
    if (sz != N) return FAIL;

    // a teraz prichadza ta nekonecne zabavna chvila kedy treba zistit ci je to acyklicke a ak nie, skusit to na acyklicke prerobit
    while (true) {
        vector< vector<int> > G(N+1);
        for (int i=0; i<int(all_keys.size()); ++i) { 
            if (MM.matching[i]==-1) continue; // nepouzity kluc
            auto ak=all_keys[i];
            G[ak.first].push_back( MM.matching[i] );
            // cout << "po truhlici " << ak.first << " truhlica " << MM.matching[i] << endl;
        }
        vector<bool> reachable = get_reachable(G,0);
        bool all_reachable = true;
        for (int n=0; n<=N; ++n) all_reachable &= reachable[n];
        if (all_reachable) {
            // DA SA RIESIT, ideme najst jedno riesenie, vratit ho a skoncit
            for (int n=1; n<=N; ++n) {
                int unlocked_by = -1;
                for (int i=0; i<int(keys[0].size()); ++i) if (keys[0][i]==unlocks[n]) unlocked_by = i;
                if (unlocked_by == -1) continue; // touto nevieme zacat
                vector<int> nunlocks;
                for (int i=0; i<=N; ++i) if (i!=n) nunlocks.push_back(unlocks[i]);
                vector<int> nchestids;
                for (int i=0; i<=N; ++i) if (i!=n) nchestids.push_back(chest_ids[i]);
                vector< vector<int> > nkeys;
                for (int i=0; i<=N; ++i) if (i!=n) nkeys.push_back(keys[i]);
                nkeys[0].erase( nkeys[0].begin() + unlocked_by );
                nkeys[0].insert( nkeys[0].end(), keys[n].begin(), keys[n].end() );
                vector<int> SOL = solve(nunlocks,nchestids,nkeys);
                if (SOL == FAIL) continue;
                SOL.insert( SOL.begin(), chest_ids[n] );
                return SOL;
            }
            assert(false); // should not get here
        }

        // a teraz prichadza radostna chvila kedy treba najst nejaky kus vo zvysku ktory vieme pripojit
        bool nasiel = false;
        for (int n=1; n<=N; ++n) if (!reachable[n]) {
            int curkey = unlocks[n];
            // mam volny curkey? alebo aspon nejaky som pouzil?
            int nejaky = -1;
            int volny = -1;
            for (int i=0; i<int(all_keys.size()); ++i) { 
                auto ak=all_keys[i]; 
                if (!reachable[ak.first]) continue;
                if (keys[ak.first][ak.second]!=curkey) continue;
                nejaky = i;
                if (MM.matching[i]!=-1) continue;
                volny = i;
                break;
            }
            if (volny != -1) {
                // pouzijeme volny curkey na odomknutie truhlice n
                for (int i=0; i<int(all_keys.size()); ++i) if (MM.matching[i]==n) MM.matching[i]=-1; 
                MM.matching[volny]=n;
                nasiel = true;
                break;
            }
            if (nejaky == -1) continue; // nemam sancu
            // vyrobi odomknutie n volny curkey?
            int vyrobi = -1;
            vector<bool> nreachable = get_reachable(G,n);
            for (int i=0; i<int(all_keys.size()); ++i) { 
                auto ak=all_keys[i]; 
                if (!nreachable[ak.first]) continue;
                if (keys[ak.first][ak.second]!=curkey) continue;
                if (MM.matching[i]!=-1) continue;
                vyrobi = i;
                break;
            }
            if (vyrobi != -1) {
                for (int i=0; i<int(all_keys.size()); ++i) if (MM.matching[i]==n) MM.matching[i]=-1; 
                MM.matching[vyrobi]=MM.matching[nejaky];
                MM.matching[nejaky]=n;
                nasiel = true;
                break;
            }
            // este tam moze byt cyklus ktory otvori n
            for (int i=0; i<int(all_keys.size()); ++i) { 
                auto ak=all_keys[i]; 
                if (!nreachable[ak.first]) continue;
                if (keys[ak.first][ak.second]!=curkey) continue;
                if (MM.matching[i]!=n) continue;
                vyrobi = i;
                break;
            }
            if (vyrobi != -1) {
                MM.matching[vyrobi]=MM.matching[nejaky];
                MM.matching[nejaky]=n;
                nasiel = true;
                break;
            }
        }
        if (!nasiel) return FAIL;
    }
}


int main(void) {
    int T; cin >> T;
    for (int t=1; t<=T; ++t) {
        int K; cin >> K;
        int N; cin >> N;
        vector<int> unlocks(N+1);
        vector< vector<int> > contains_keys(N+1);
        while (K--) { int x; cin >> x; contains_keys[0].push_back(x); }
        for (int n=1; n<=N; ++n) {
            cin >> unlocks[n] >> K;
            while (K--) { int x; cin >> x; contains_keys[n].push_back(x); }
        }
        vector<int> chest_ids(N+1);
        for (int n=0; n<=N; ++n) chest_ids[n]=n;

        vector<int> SOL = solve(unlocks,chest_ids,contains_keys);
        if (SOL == FAIL) { printf("Case #%d: IMPOSSIBLE\n",t); continue; }
        printf("Case #%d:",t);
        for (auto x:SOL) printf(" %d",x);
        printf("\n");

    }
}
