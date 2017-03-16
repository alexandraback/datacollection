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
#define RSort(v) sort((v).rbegin(), (v).rend())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "C"

bool mk[2000001];
int main()
{
	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    int d[1001];
    int n[1001];
    int w[1001];
    int l[1001];
    int s[1001];
    int dd[1001];
    int dp[1001];
    int ds[1001];
    int att[1001];
    int off=200;
    int wll[400];
    for (int caseId=1;caseId<=T;caseId++)
	{
        cl(d,0);
        cl(n,0);
        cl(w,0);
        cl(l,0);
        cl(s,0);
        cl(dd,0);
        cl(dp,0);
        cl(ds,0);
        cl(att,0);
        cl(wll,0);
        // input
        int N;
        cin>>N;
        rep(i,N){
            int e;
            cin>>d[i]>>n[i]>>w[i]>>e>>s[i]>>dd[i]>>dp[i]>>ds[i];
            l[i]=e-w[i];
        }
        int res = 0;
        while(true) {
            int ddd=oo;
            bool done = true;
            rep(i,N){
                if (att[i]==n[i]) continue;
                done = false;
                int tddd=d[i]+att[i]*dd[i];
                if (tddd<ddd)
                    ddd = tddd;
            }
            if (done)
                break;
            rep(i,N){
                if (att[i]==n[i]) continue;
                int tddd=d[i]+att[i]*dd[i];
                if (tddd==ddd){
                    int tw = w[i]+att[i]*dp[i];
                    int ts = s[i]+att[i]*ds[i];
                    For(j,off+tw,off+tw+l[i]){
                        if (wll[j]<ts) {
                            res++;
                            //cout<<tddd<<","<<i<<","<<att[i]<<","<<ts<<endl;
                            break;
                        }
                    }
                }
            }
            rep(i,N){
                if (att[i]==n[i]) continue;
                int tddd=d[i]+att[i]*dd[i];
                if (tddd==ddd){
                    int tw = w[i]+att[i]*dp[i];
                    int ts = s[i]+att[i]*ds[i];
                    For(j,off+tw,off+tw+l[i]){
                        if (wll[j]<ts) {
                            wll[j] = ts;
                        }
                    }
                    att[i]++;
                }
            }
        }
        // output:
        cout << "Case #"<<caseId<<": "<<res<<endl;
	}
    return 0;
}