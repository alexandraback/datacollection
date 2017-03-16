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
using namespace std;
inline long toInt(string s) {long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<long, long> PII;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) long((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
long pw(long x, long y){long ans = 1;for(long i = 0; i < y; i++){ans = ans * x;}return ans;}
long factorial(long x){long ans = 1; for(int i = 1 ;i < x+1; i++){ans = ans *i;}return ans;}
long combination(long x,long y){return factorial(x)/factorial(y)/factorial(x-y);}
long permutation(long x, long y){return factorial(x)/factorial(x-y);}
//コンテナ用のdump xdumpを定義する
template<class X> void xdump(list<X> &l){typename list<X>::iterator itr = l.begin();int cnt = 0;cerr << "dumping the list" << endl;while(1){if(itr == l.end()) break;cerr << cnt << ":" << (*itr) << endl;itr++;cnt++;}}
template<class X> void xdump(vector<X> &l){typename vector<X>::iterator itr = l.begin();int cnt = 0;cerr << "dumping the vector" << endl;while(1){if(itr == l.end()) break;cerr << cnt << ":" << (*itr) << endl;itr++;cnt++;	}}
template<class X> void xdump(queue<X> &l){typename queue<X>::iterator itr = l.begin();int cnt = 0;cerr << "dumping the queue" << endl;while(1){if(itr == l.end()) break;cerr << cnt << ":" << (*itr) << endl;itr++;cnt++;}}
template<class X> void xdump(stack<X> &l){  typename stack<X>::iterator itr = l.begin();  int cnt = 0;  cerr << "dumping the stack" << endl;  while(1){   if(itr == l.end()) break;   cerr << cnt << ":" << (*itr) << endl;   itr++;   cnt++;    }   }
template<class X,class Y> void xdump(vector<pair<X,Y> > v){  typename vector<pair<X,Y> >::iterator itr = v.begin();  int cnt = 0;  cerr << " dumping the vector with pair" << endl;  while(1){   if(itr == v.end()) break;   cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;   itr++;   cnt++;  }   }  
template<class X,class Y> void xdump(list<pair<X,Y> > v){  typename list<pair<X,Y> >::iterator itr = v.begin();  int cnt = 0;  cerr << " dumping the list with pair" << endl;  while(1){   if(itr == v.end()) break;   cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;   itr++;   cnt++;  }   } 
 template<class X,class Y> void xdump(queue<pair<X,Y> > v){  typename queue<pair<X,Y> >::iterator itr = v.begin();  int cnt = 0;  cerr << " dumping the queue with pair" << endl;  while(1){   if(itr == v.end()) break;   cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;   itr++;   cnt++;  }   }  
 template<class X,class Y> void xdump(stack<pair<X,Y> > v){  typename stack<pair<X,Y> >::iterator itr = v.begin();  int cnt = 0;  cerr << " dumping the stack with pair" << endl;  while(1){   if(itr == v.end()) break;   cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;   itr++;   cnt++;  }   }  
 template<class X,class Y> void xdump(map<X,Y> m){ typename map<X,Y> :: iterator itr = m.begin(); int cnt = 0; cerr << "dumping the map" << endl; while(1){ if(itr == m.end()) break; cerr << cnt << ":" << (*itr).first << "/" << (*itr).second << endl; cnt++; itr++;  } }
int flip(int x){string s;s = toString(x);string s2;for(int i = 0; i < s.size(); i++){s2 = toString(s[i]) + s2;}return toInt(s2);}
string flip(string s){string ss;for(int i = 0; i < s.size(); i++){ss = toString(s[i]) + ss;}return ss;}

//for Google Code Jam
//int T; cin >> T; for(int t = 0; t < T; t++){
//	cout << "Case #" << t+1 << ": " << endl;
//}
/*
縦に見ていくと
2 3 2 1
combinationをしてたす
横に見ていくと
2422

*/
int main(){
	
	int T; cin >> T; for(int t = 0; t < T; t++){
		string s;
		cin >> s;
		string ans;
		for(int i = 0; i < s.size(); i++){
			if((int)s[i] >= ans[0]){
				ans = toString(s[i]) + ans;
			}else{
				ans = ans + toString(s[i]);
			}
		}
		cout << "Case #" << t+ 1 << ": " <<ans << endl;
		
	}
	
}

