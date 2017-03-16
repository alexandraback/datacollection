#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define INP_FILE "input.txt"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

class Solver1 {
    vector<string> codes;
    vector<vector<int> > a;
    vector<bool> used;
    vector<int> rev;
    int n_used;
    int n, m;
public:
    bool qq(int id, const string &cur, string & best) {
        best = cur+"X";
        bool upd =false;
        string r;
        rp(i, a[id].size()) {
            int to = a[id][i];
            
            if (!used[to] && go(to, id, cur, r)) {
                upd = true;
                if (r<best) {
                    best =r;
                }
            }
        }
        if (rev[id]!=-1 && qq(rev[id], cur, r)) {
            upd = true;
            if (r<best) {
                best =r;
            }
        }
        return upd;
    }
    bool go(int to, int from, const string &cur, string & best) {
        string z = cur + codes[to];
        used[to] = 1; ++n_used; rev[to] = from;
        if (n_used == n) {
            best = z;
            used[to] = 0; --n_used; return true;
        }
        bool r = qq(to, z, best);
        used[to] = 0; --n_used; return r;
    }
    string solve() {
         cin>>n>>m;
        string s;
        rp(i,n) { cin>>s; codes.pb(s);}
        a.resize(n);
        used.resize(n, false);
        rev.resize(n, -2);
        n_used= 0;
        rp(i, m) {
            int q, w; cin>>q>>w;--q;--w;
            a[q].pb(w);
            a[w].pb(q);
        }
        string ans = "X";
        string tmp="";
        rp(i, n) {
            string t;
            if (go(i, -1, tmp, t) && t < ans) {
                ans = t;
            }
        }
        return ans;
    }
};

class Solver {
    vector<string> codes;
    vector<vector<int> > a;
    vector<bool> used;
    vector<int> rev;
    int n_used;
    int n, m;
public:
    string solve() {
         cin>>n>>m;
        string s;
        rp(i,n) { cin>>s; codes.pb(s);}
        a.resize(n);
        used.resize(n, false);
        rev.resize(n, -2);
        n_used= 0;
        rp(i, m) {
            int q, w; cin>>q>>w;--q;--w;
            a[q].pb(w);
            a[w].pb(q);
        }
        priority_queue<pair<string, int> , vector<pair<string, int> >,  greater<pair<string, int> > > q;
        int root = min_element(all(codes)) - codes.begin();
        q.push(mp(codes[root], root));used[root]=1;
        string ans = "";
        while (!q.empty()) {
            pair<string, int> t = q.top(); q.pop();
            ans += t.first;
            rp(i, a[t.second].size()) {
                int id = a[t.second][i];
                if (!used[id]) {
                    used[id] = 1; q.push(mp(codes[id], id));
                }
            }
        }
        //string ans = "X";
        //string tmp="";
        //rp(i, n) {
        //    string t;
        //    if (go(i, -1, tmp, t) && t < ans) {
        //        ans = t;
        //    }
        //}
        return ans;
    }
};

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        Solver s;
        printf("Case #%d: %s\n",tst, s.solve().c_str());
	}
	
	return 0;
}