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

        int C,D,V;
        int n=D;
        int nu[10];

int get_min_missed()
{
    int vl[31];
    int mx=(1<<n);
    cl(vl,0);
    rep(i,mx){
        int ii=i;
        int v=0;
        rep(j,n){
            if (ii%2) {
                v+=nu[j];
            }
            ii>>=1;
        }
        if (v<=V){
            vl[v]=1;
        }
    }
    rep(i,V){
        if (vl[i]==0) return i;
    }
    return -1;
}

int main()
{
//	freopen("" QX ".txt","r",stdin);
	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-small-practice.in","r",stdin);freopen("" QX "-small-practice.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cin>>C>>D>>V;
        cl(nu,0);
        rep(i,D){
            cin>>nu[i];
        }
        n=D;
        while(true){
            int mm=get_min_missed();
            //cout<<mm<<endl;
            if (mm>=0){
                int l=1;
                while(l<=mm){
                    l<<=1;
                }
                l/=2;
                nu[n++]=l;
            }else{
                break;
            }
        }
        int ans = n-D;
        // output:
        cout << "Case #"<<caseId<<": "<<ans<<endl;
	}
    return 0;
}