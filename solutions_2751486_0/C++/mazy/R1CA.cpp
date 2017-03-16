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
	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large-practice.in","r",stdin);freopen("" QX "-large-practice.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    std::string cc;
    // for \n
    getline(std::cin, cc);
    int* mm = new int[1024000];
    //int mm[1000];
	for (int caseId=1;caseId<=T;caseId++)
	{
        memset(mm,0,1024000*sizeof(int));
        // input
        int L = 0;
        int n = 0;
        getline(std::cin, cc);
        rep(i, cc.length()) {
          if (cc[i] == ' ') {
              L = i;
              n = atoi(cc.substr(i+1).c_str());
              cc.resize(i);
              break;
          }
        }
        int s=-1;
        rep(i,L) {
            char ch = cc[i];
            if (ch !='a' && ch !='e' && ch !='i' && ch !='o' && ch !='u') {
                if (s == -1)
                    s = i;
            } else {
                if (s >= 0) {
                    int l = i - s;
                    For(j,s,i) {
                        mm[j] = l--;
                    }
                }
                s = -1;
            }
        }
        if (s >= 0) {
            int l = L - s;
            For(j,s,L) {
                mm[j] = l--;
            }
        }
        ll res = 0;
        int qq=0;
        rep(p,L-n+1){
            //For(q,max(p,qq),L){
            For(q,p,L){
                if (mm[q]>=n){
                    qq = q;
                    res += (ll) (L-q-n+1);
                    break;
                }
            }
        }

        // output
        //printf("Case #%d: %.6f\n", caseId,V);
        cout << "Case #"<<caseId<<": "<<res<<"\n";

	}
    return 0;
}