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
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "B"

bool debug=false;

int K,L,S;
char cl[7];

int check(char cs[7]){
    int ret=0;
    rep(i,S-L+1){
        int j=0;
        bool match=true;
        while(j<L){
            assert(j+i<S);
            if (cs[j+i]!=cl[j]){
                match=false;
                break;
            }
            j++;
        }
        if (match)
            ret++;
    }
    return ret;
}

#define DO {\
                cs[S]=0;\
                /*if (debug) cout<<cs<<" "<<ps<<endl;*/\
                int rp=check(cs); \
                if (rp>0){ \
                    if (rp>mx) mx=rp;\
                    ave+=ps*rp;\
                }\
                ps=pst;\
            }

int main()
{
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
	freopen("" QX "-small-attempt2.in","r",stdin);freopen("" QX "-small-attempt2.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cin>>K>>L>>S;
        if (debug) cout<<"K"<<K<<" L"<<L<<" S"<<S<<endl;
        int kk=0;
        char ck[7];
        long double p[7];
        rep(i,K){
            char ch;
            cin>>ch;
            bool dup=false;
            rep(j,kk){
                if (ch==ck[j]){
                    p[j]+=1/(double)K;
                    dup=true;
                    break;
                }
            }
            if (!dup){
                ck[kk]=ch;
                p[kk]=1/(double)K;
                kk++;
            }
        }
        rep(i,kk){
            if (debug) cout<<ck[i]<<" "<<p[i]<<endl;
        }
        rep(i,L){
            cin>>cl[i];
        }

        char cs[7];
        long double ps=1;
        int mx=0;
        long double ave=0;
        rep(i0,kk){
            cs[0]=ck[i0];
            long double pst=ps;
            ps*=p[i0];
            if (S>1) {rep(i1,kk){
                cs[1]=ck[i1];
                long double pst=ps;
                ps*=p[i1];
                if (S>2) {rep(i2,kk){
                    cs[2]=ck[i2];
                    long double pst=ps;
                    ps*=p[i2];
                    if (S>3) {rep(i3,kk){
                        cs[3]=ck[i3];
                        long double pst=ps;
                        ps*=p[i3];
                        if (S>4) {rep(i4,kk){
                            cs[4]=ck[i4];
                            long double pst=ps;
                            ps*=p[i4];
                            if (S>5) {rep(i5,kk){
                                cs[5]=ck[i5];
                                long double pst=ps;
                                ps*=p[i5];
                                if (S>6) {rep(i6,kk){
                                    cs[6]=ck[i6];
                                    long double pst=ps;
                                    ps*=p[i6];
                                    DO;
                                }ps=pst;} else DO;
                            }ps=pst;} else DO;
                        }ps=pst;} else DO;
                   }ps=pst; } else DO;
               }ps=pst; } else DO;
            }ps=pst;} else DO;
        }
        if (debug) cout<<"mx="<<mx<<endl;
        double ans=((double)mx) - ave;
        // output
        printf("Case #%d: %.7f\n",caseId, ans);
        //cout << "Case #"<<caseId<<": "<<ans<<"\n";
	}
    return 0;
}
