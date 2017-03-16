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

#define QX "C"

map<string, set<string> > ln;

string run(set<string> lft, map<string,int> choo, stack<string> trace);

string core(string s, set<string> lft, map<string,int> choo, stack<string> trace) {
        const set<string>& go = ln[s];
        lft.erase(s);
        choo.erase(s);
        // check how to get to s
        while(!trace.empty()) {
            const set<string>& cln = ln[trace.top()];
            if (cln.find(s)!=cln.end()) {
                break;
            }
            for(set<string>::iterator it2 = cln.begin();it2!=cln.end();++it2){
                const string& ss = *it2;
                if (lft.find(ss) != lft.end()) {
                    choo[ss] = choo[ss] - 1;
                    if (choo[ss] <= 0)
                        choo.erase(ss);
                }
            }
            trace.pop();
        }
        trace.push(s);
        if (lft.empty()) {
            // done!
            return s;
        }
        for(set<string>::iterator it2 = go.begin();it2!=go.end();++it2){
            const string& ss = *it2;
            if (lft.find(ss) != lft.end())
                choo[ss] = choo[ss] ++;
        }
        if (choo.empty()){
            // failed!
            return "";
        }
        string ans = run(lft, choo, trace);
        if (!ans.empty())
            return s+ans;
        return "";
}

string run(set<string> lft, map<string,int> choo, stack<string> trace) {
    for(map<string,int>::iterator it = choo.begin();it!=choo.end();++it){
        string s = it->first;
        string ans = core(s,lft,choo,trace);
        if (!ans.empty())
            return ans;
    }
    return "";
}

int main()
{
//	freopen("" QX ".txt","r",stdin);
	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        int N,M;
        cin>>N>>M;
        vector<string> nm;
        rep(i,N){
            string s;
            cin>>s;
            nm.push_back(s);
            //cout<<s<<endl;
        }
        ln.clear();
        rep(i,M){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            ln[nm[a]].insert(nm[b]);
            ln[nm[b]].insert(nm[a]);
        }
        Sort(nm);
        set<string> lft;
        rep(i,nm.size()) {
            lft.insert(nm[i]);
        }
        string ans;
        for(set<string>::iterator it = lft.begin();it!=lft.end();++it){
            map<string,int> choo;
            choo[*it] = 1;
            ans = run(lft,choo, stack<string>());
            if (!ans.empty())
                break;
            choo.erase(*it);
        }
        // output
        cout << "Case #"<<caseId<<": "<<ans<<"\n";

	}
    return 0;
}