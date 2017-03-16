#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
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
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define MAXN 1000005
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

//Main code starts here
vector<vector<string> >word_list(25);
map<pair<int, int>, int> M;
string str;
int len;

void pre() {
    fstream f;
    f.open("garbled_email_dictionary.txt", ios::in);
    string word;
    while(f>>word) {
        int sz = word.size();
        assert(sz < 25);
        word_list[sz].push_back(word);
    }
    f.close();
}

inline pair<int, int> doit(string & cand, string & word) {
    int last = -1;
    int cnt = 0;
    assert(word.size() == cand.size());

    int sz = word.size();
    REP (i, sz) { 
        if (word[i] != cand[i]) {
            cnt++;
            if (cnt >= 2 && i - last < 5)
                return make_pair(-1, -1);
            last = i;
        }
    }

    if (cnt == 0) return make_pair(0, 0);

    int pre = max(0, last - sz + 5);

    return make_pair(cnt, pre);
}

bool has_prefix(string &s, string &prefix) {
    assert(s.size() >= prefix.size());
    return (s.substr(0, prefix.size()) == prefix);
}

int solve(int index, int match) {
    assert(index <= len);
    if (index == len) return 0;
    if (M.find(make_pair(index, match)) != M.end()) return M[make_pair(index, match)];

    int anss = INF;

    FOR (word_len, 1, min(len - index, 24)) {
        vector<string> words = word_list[word_len];

        if (words.size() == 0)  continue;

        int match_len = min(match, word_len);
        string prefix = str.substr(index, match_len);

        int lo = 0;
        int hi = int(words.size()) - 1;
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2 ;
            string wd = words[mid];

            if (wd >= prefix) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        int lb = ans;

        //cout<<index<<" "<<match<<" "<<word_len<<" "<<match_len<<" "<<prefix<<" "<<lb<<" "<<words[lb]<<endl;

        //if (prefix == "o")
        //    REP (i, words.size())
        //        cout<<words[i]<<endl;

        for (int i = lb; i < words.size(); i++) {
            string word = words[i];

            bool ok = true;
            REP (j, match_len)
                if (prefix[j] != str[index+j]) {
                    ok = false;
                    break;
                }

            if (!ok) {
                //cout<<index<<" "<<match<<" "<<word_len<<" "<<match_len<<" "<<prefix<<" "<<i<<" "<<words[i]<<endl;
                break;
            }

            string cand = str.substr(index, word_len);

            pair<int, int> vals = doit(cand, word);

            if (vals.first == -1) continue;

            if (vals.first >= anss) continue;

            anss = min(anss, vals.first + solve(index + word_len, vals.second));
        }
    }

    return M[make_pair(index, match)] = anss;
}

int main()
{
    pre();
    int t = GI;
    FOR (cas, 1, t) {
        M.clear();
        cin>>str;

        len = str.size();

        if (11 <= cas && cas <= 20) {
            int val = solve(0, 0);

            cout<<"Case #"<<cas<<": "<<val<<endl;
        }
    }

	return 0;
}
