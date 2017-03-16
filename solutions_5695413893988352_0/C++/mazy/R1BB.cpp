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

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "B"

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
        string c, j;
        cin>>c>>j;
        assert(c.length() == j.length());
        int l = c.length();
        while (c.length() < 3) {
            c = "0" + c;
        }
        while (j.length() < 3) {
            j = "0" + j;
        }
        int m = 1000;
        string C,J;
        //cout<<c<<" "<<j<<endl;
        For (i, 0, 1000) {
            For (k, 0, 1000) {
                if ((c[2] == '?' || c[2] - '0' == (i % 10)) &&
                    (c[1] == '?' || c[1] - '0' == ((i/10) % 10)) &&
                    (c[0] == '?' || c[0] - '0' == ((i/100) % 10)) &&
                    (j[2] == '?' || j[2] - '0' == (k % 10)) &&
                    (j[1] == '?' || j[1] - '0' == ((k/10) % 10)) &&
                    (j[0] == '?' || j[0] - '0' == ((k/100) % 10))) {
                        int diff = i - k;
                        if (diff<0) diff = -diff;
                        if (diff < m) {
                            m = diff;
                            C=to_string(i);
                            J=to_string(k);
                            //cout<<i<<" "<<k<<endl;
                        }
                    }
            }
        }
        while (C.length() < l) {
            C = "0" + C;
        }
        while (J.length() < l) {
            J = "0" + J;
        }

        // output
        cout << "Case #"<<caseId<<": "<<C<<" "<<J<<"\n";
	}
    return 0;
}
