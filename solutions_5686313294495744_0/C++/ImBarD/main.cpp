#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    forn(alf,1, T+1) {
        //cout<<"Case #" << alf<<": ";
        printf("Case #%d: ", alf);
        map<string, int> index1, index2;
        int cnt1 = 0, cnt2 = 0;
        int N;
        scanf("%d\n", &N);
        string s;
        string t;
        n=0;
        k=0;
        g.clear();
        forn(i,0,N) {
            getline(cin, s);
            int cur =0;
            while(s[cur] != ' ') cur++;
            cur++;
            t= s.substr(cur, 30);
            s =s.substr(0, cur-1);
            //cout << s<<"lol"<<t<<endl;
            if(index1[s] == 0) {
                n++;
                g.pb(vi());
                cnt1++;
                index1[s] = cnt1;
            }
            if(index2[t] == 0) {
                k++;
                cnt2++;
                index2[t] = cnt2;
            }
//            cout<<s<<" " <<index1[s]<<endl;
//            cout<<t<<" " <<index2[t]<<endl;
            g[index1[s]-1].pb(index2[t]-1);
        }
        mt = vi(k, -1);
        for (int v=0; v<n; ++v) {
            used.assign (n, false);
            kuhn (v);
        }
        int pairs = 0;
        for (int i=0; i<k; ++i)
            if (mt[i] != -1)
                pairs++;
        printf("%d\n", N-cnt1-cnt2+pairs);
    }
    
    
}

