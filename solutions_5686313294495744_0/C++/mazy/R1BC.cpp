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
#define LOG if (log) cout
const int oo=1000000;

#pragma warning(disable:4996)

#define QX "C"

int main()
{
//	freopen("../" QX ".txt","r",stdin);
//	freopen("../" QX "-small-attempt0.in","r",stdin);//freopen("../" QX "-small-attempt0.out","w",stdout);
//	freopen("../" QX "-small-attempt1.in","r",stdin);freopen("../" QX "-small-attempt1.out","w",stdout);
	freopen("../" QX "-small-attempt2.in","r",stdin);freopen("../" QX "-small-attempt2.out","w",stdout);
//	freopen("../" QX "-large.in","r",stdin);freopen("../" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        map<string,int> wc1;
        map<string,int> wc2;
        vector<pair<string,string> > wds;
        vector<pair<string,string> > wds2;
        map<string, bool> showed1;
        map<string, bool> showed2;

        int N;
        cin>>N;
        rep(i,N) {
            string s1,s2;
            cin>>s1>>s2;
            wc1[s1]++;
            wc2[s2]++;
            wds.push_back(make_pair(s1,s2));
            wds2.push_back(make_pair(s2,s1));
            showed1[s1] = false;
            showed2[s2] = false;
        }
        sort(wds.begin(),wds.end());
        sort(wds2.begin(),wds2.end());

        int counter = 0;
        rep(i,N) {
            if (wc1[wds[i].first] > 1 && wc2[wds[i].second] > 1) {
                counter++;
            }
        }
        //cout<<counter<<" "<<wc1.size()<<" "<<wc2.size()<<endl;

        string current;
        int subtotal = 0;
        int subfake = 0;
        int ans = 0;
        rep(i,N) {
            //cout<<wds[i].first<<" "<<wc1[wds[i].first]<<" + "<<wds[i].second<<" "<<wc2[wds[i].second]<<endl;
            if (current != wds[i].first) {
                current = wds[i].first;
                if (subfake > 0) {
                    ans += subfake;
                }
                subfake = 0;
                subtotal = 0;
            }
            if (!showed1[wds[i].first] && !showed2[wds[i].second]) {
                // let it pass
                showed1[wds[i].first] = true;
                showed2[wds[i].second] = true;
            } else if (wc1[wds[i].first] > 1 && wc2[wds[i].second] > 1) {
                subfake++;
                wc1[wds[i].first] --;
                wc2[wds[i].second] --;
                //cout<<"caught!"<<endl;
            }
            subtotal++;
        }
        if (subfake > 0) {
            ans += subfake;
        }

/*
        //cout<<endl;
        wc1.clear();wc2.clear();
        rep(i,N) {
            wc1[wds[i].first]++;
            wc2[wds[i].second]++;
        }
        int ans2 = 0;
        current = "";
        subfake = 0;
        subtotal = 0;
        rep(i,N) {
            //cout<<wds2[i].first<<" "<<wc2[wds2[i].first]<<" + "<<wds2[i].second<<" "<<wc1[wds2[i].second]<<endl;
            if (current != wds2[i].first) {
                current = wds2[i].first;
                if (subfake > 0) {
                    ans2 += subfake;
                }
                subfake = 0;
                subtotal = 0;
            }
            if (wc2[wds2[i].first] > 1 && wc1[wds2[i].second] > 1) {
                subfake++;
                wc1[wds2[i].second] --;
                wc2[wds2[i].first] --;
                //cout<<"caught!"<<endl;
            }
            subtotal++;
        }
        if (subfake > 0) {
            ans2 += subfake;
            //ans2 += (subfake == subtotal? subfake - 1: subfake);
        }

        if (ans != ans2) {
            cout<<"!!!"<<endl;
            cout<<ans<<" "<<ans2<<endl;
        }
*/

        // output:
        cout << "Case #"<<caseId<<": "<<ans<<endl;
	}
    return 0;
}
