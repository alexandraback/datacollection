#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i=0;i<int(n);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
typedef  long long   ll;


#define ALL(x)   (x).begin(),(x).end()
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}



class Node {
 public:
  int count;
  map<char, Node*> edges;
  Node(int _count) : count(_count) {};
};

int tot = 0;
class Trie {
  public:
   Node *root;
   Trie() {
     root = new Node(0);
   }
   void addWord(const string &s) {
     Node *aux = root;
     for (int i = 0; i < s.size(); ++i) {
       if (aux->edges.find(s[i]) != aux->edges.end()) {
         aux = aux->edges[s[i]];
       } else {
         // creamos el nodo... 
         aux->edges[s[i]] = new Node(0);
         aux = aux->edges[s[i]];
         tot++;
       }
     }
     aux->count++;
   }
};

string W;
Trie TT;
map<pair<int,Node *>, int> dp;
#define debug(s) ; // cout << s << endl;
int doit(Node *node, int step, int c) {
//  cout << node << "  " << step << "  " << W[step] << "  " << c << endl;
  if (step == W.size()) {
    if (!(node->count)) return 5000;
    return 0;
  }
  int res = 5000;
  if (c) {
    if (node->edges.find(W[step]) != node->edges.end())
      res = min(res, doit(node->edges[W[step]], step+1, c-1));
    if (node->count && node != TT.root)
      res = min( res, doit(TT.root, step, c));
    return res;
  }
  pair<int, Node *> MM = make_pair(step, node);
  if (dp.find(MM) != dp.end()) return dp[MM];
  // opcion uno, usarla si esta...
  if (node->edges.find(W[step]) != node->edges.end()) {
    debug("Tratamos de usarla");
    res = min( res , doit(node->edges[W[step]], step+1, 0) );
  }
  // trato cambiando...
  for (char d = 'a'; d <= 'z'; ++d) {
  if (d == 'o') debug("LLegamos ");
    if (d == W[step]) continue;
    if (node->edges.find(d) == node->edges.end()) continue;
    res = min( res, doit(node->edges[d], step+1, 4)+1 );
  }
  // ultima opcion, haber terminado en una palabra justiniano posex... 
  if (node->count && node != TT.root)
    res = min( res, doit(TT.root, step, c));
  return dp[MM] = res;
}


int main() {
  int i,j ,k;
  int casos; cin >> casos;
  // construimos el trie... 
  ifstream dict("garbled_email_dictionary.txt");
  string s;
  while (dict >> s) {
    TT.addWord(s);
  }
//  cout << tot << endl;
  for (int h = 0; h < casos; ++h) {
    dp.clear();
    cin >> W;
    cout << "Case #" << h+1 << ": " << doit(TT.root, 0, 0) << endl; 
  }
  return 0;
}
