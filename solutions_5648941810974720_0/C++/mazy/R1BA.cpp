#include <fstream>
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
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const double pi=acos(-1.0);
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
typedef map<string, int> simp;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
template<class T> inline void Swap(T &a,T &b){T c=a;a=b;b=c;}
#define Sort(v) sort((v).begin(), (v).end())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const ull oo=1ULL<<31;

#pragma warning(disable:4996)

#define QX "A"

#define I(ch) ch - 'A'
int main()
{
//	freopen("../" QX ".txt","r",stdin);
	freopen("../" QX "-small-attempt0.in","r",stdin);freopen("../" QX "-small-attempt0.out","w",stdout);
//	freopen("../" QX "-small-attempt1.in","r",stdin);freopen("../" QX "-small-attempt1.out","w",stdout);
//	freopen("../" QX "-large.in","r",stdin);freopen("../" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        string s;
        cin>>s;
        int l = s.length();
        int c[10];
        cl(c,0);
        int w[26];
        cl(w,0);
        rep(i, l) {
            w[I(s[i])]++;
        }
        // 0 - Z
        c[0] = w[I('Z')];
        w[I('Z')] = 0;
        w[I('E')] -= c[0];
        w[I('R')] -= c[0];
        w[I('O')] -= c[0];

        // 2 - W
        c[2] = w[I('W')];
        w[I('W')] = 0;
        w[I('T')] -= c[2];
        w[I('O')] -= c[2];

        // 6 - X
        c[6] = w[I('X')];
        w[I('X')] = 0;
        w[I('S')] -= c[6];
        w[I('I')] -= c[6];

        // 7 - S
        c[7] = w[I('S')];
        w[I('S')] = 0;
        w[I('E')] -= c[7];
        w[I('V')] -= c[7];
        w[I('E')] -= c[7];
        w[I('N')] -= c[7];

        // 5 - V
        c[5] = w[I('V')];
        w[I('V')] = 0;
        w[I('F')] -= c[5];
        w[I('I')] -= c[5];
        w[I('E')] -= c[5];

        // 4 - F
        c[4] = w[I('F')];
        w[I('F')] = 0;
        w[I('O')] -= c[4];
        w[I('U')] -= c[4];
        w[I('R')] -= c[4];

        // 1 - O
        c[1] = w[I('O')];
        w[I('O')] = 0;
        w[I('N')] -= c[1];
        w[I('E')] -= c[1];

        // 3 - R
        c[3] = w[I('R')];
        w[I('R')] = 0;
        w[I('T')] -= c[3];
        w[I('H')] -= c[3];
        w[I('E')] -= c[3];
        w[I('E')] -= c[3];

        // 1 - O
        c[8] = w[I('G')];
        w[I('G')] = 0;
        w[I('E')] -= c[8];
        w[I('I')] -= c[8];
        w[I('H')] -= c[8];
        w[I('T')] -= c[8];

        // 9 - I
        c[9] = w[I('I')];
        w[I('I')] = 0;
        w[I('N')] -= c[9];
        w[I('N')] -= c[9];
        w[I('E')] -= c[9];

        rep(i,26) {
            assert(w[i] == 0);
        }
        string ans;
        rep(i,10) {
            rep(j,c[i]) {
                ans.push_back((char)i+'0');
            }
        }

        // output:
        cout << "Case #"<<caseId<<": "<<ans<<endl;
	}
    return 0;
}
