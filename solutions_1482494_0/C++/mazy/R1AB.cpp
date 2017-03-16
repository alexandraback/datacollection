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

int a[2001];
int b[2001];
int c[2001];

int main()
{
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);//freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
	freopen("" QX "-small-attempt2.in","r",stdin);freopen("" QX "-small-attempt2.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        cl(a,0);
        cl(b,0);
        cl(c,0);
        bool ok=true;
        // input
        int N;
        cin>>N;
        rep(i,N){
            cin>>a[i]>>b[i];
            if (b[i]>2*N)
                ok=false;
		}
        int s=0;
        int C=0;
        while(ok && s<2*N) {
            ok=false;
            rep(i,N){
                if (c[i]==2)
                    continue;
                else if (s>=b[i]) {
                    ok=true;
            if (c[i]>=2)
                cout<<"****************";
                    s+=2-c[i];
                    c[i]=2;
                    C++;
                }
            }
            if (ok) continue;
            int wb=0;
            int wi=-1;
            rep(i,N){
                if (c[i]!=0) continue;
                if (s>=a[i]){
                    if (b[i]>wb) {wb=b[i];wi=i;}
                    ok=true;
                }
            }
            if (ok){
                    s+=1;
                    c[wi]=1;
                    C++;
                    
            }
        }
        //assert(s==2*N);
        // output
        if (s<2*N) {
            cout << "Case #"<<caseId<<": "<<"Too Bad"<<"\n";
        } else {
            if (s!=2*N)
                cout<<"****************";
            cout << "Case #"<<caseId<<": "<<C<<"\n";
        }
	}
    return 0;
}
