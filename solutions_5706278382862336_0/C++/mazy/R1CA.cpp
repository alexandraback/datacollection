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

int main()
{
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0-debug.out","w",stdout);
	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);
//	freopen("" QX "-large-practice.in","r",stdin);freopen("" QX "-large-practice.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    std::string cc;
    // for \n
    getline(std::cin, cc);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        ll P,Q;
        int L = 0;
        int n = 0;
        getline(std::cin, cc, '/');
        std::istringstream ssp(cc);
        ssp >> P;
        getline(std::cin, cc);
        std::istringstream ssq(cc);
        ssq >> Q;
        //cout<<P<<","<<Q<<"-";
        int g = 0;
        ll q = Q;
        bool ok = true;
        ll bar = 1;
        int ans = 1;
        while(q % 2 == 0) {
            q /= 2;
            if (g)
              bar *= 2;
            g++;
        }
        if (q != 1) {
            ok=false;
        }else{
            while(P<bar){
                ans++;
                bar/=2;
            }
        }
        // output
        //printf("Case #%d: %.6f\n", caseId,V);
        if (ok)
          cout << "Case #"<<caseId<<": "<<ans<<"\n";
        else
          cout << "Case #"<<caseId<<": impossible"<<"\n";

	}
    return 0;
}