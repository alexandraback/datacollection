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
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        int N,M,K;
        cin>>N>>M>>K;

        int ans = K;
        if (!(N<3||M<3||K<5)) {
             For(i,1,N-1){
                 For(j,1,M-1){
                     int c=2*i+2*j;
                     int v=c+i*j;
                     if (j<M-3 && i>2){
                         v += 2*(i-2);
                     } else if (j<M-2 && i>2) {
                         v += i-2;
                     }
                     if (i<N-3 && j>2){
                         v += 2*(j-2);
                     } else if (i<N-2 && j>2) {
                         v += j-2;
                     }
                     if (v>=K && c<ans) {
                         ans=c;
                     }
                     if (j<M-2 || i<N-2) {
                         c++;v+=2;
                         if (v>=K && c<ans) {
                             ans=c;
                         }
                     }
                     if ((j<M-3 || i<N-3) || (j<M-2 && i<N-2)) {
                         c++;v+=2;
                         if (v>=K && c<ans) {
                             ans=c;
                         }
                     }
                     if (j<M-3 && i<N-3) {
                         c++;v+=2;
                         if (v>=K && c<ans) {
                             ans=c;
                         }
                     }
                 }
             }
        }
        // output:
        cout << "Case #"<<caseId<<": "<<ans<<endl;
	}
    return 0;
}