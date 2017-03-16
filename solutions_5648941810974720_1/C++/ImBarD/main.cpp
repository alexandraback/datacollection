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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(alf,1, t+1) {
        cout<<"Case #" << alf<<": ";
        vi ans;
        string s;
        cin>>s;
        map<char, int> sym;
        for(auto x: s) sym[x]++;
        forn(i,0,sym['Z']) ans.pb(0);
        sym['E']-=sym['Z'];
        sym['R']-=sym['Z'];
        sym['O']-=sym['Z'];
        sym['Z']=0;
        forn(i,0,sym['W']) ans.pb(2);
        sym['O']-=sym['W'];
        sym['T']-=sym['W'];
        sym['W']=0;
        forn(i,0,sym['X']) ans.pb(6);
        sym['S']-=sym['X'];
        sym['I']-=sym['X'];
        sym['X']=0;
        forn(i,0,sym['G']) ans.pb(8);
        sym['E']-=sym['G'];
        sym['I']-=sym['G'];
        sym['H']-=sym['G'];
        sym['T']-=sym['G'];
        sym['G']=0;
        forn(i,0,sym['U']) ans.pb(4);
        sym['F']-=sym['U'];
        sym['O']-=sym['U'];
        sym['R']-=sym['U'];
        sym['U']=0;
        forn(i,0,sym['F']) ans.pb(5);
        sym['V']-=sym['F'];
        sym['I']-=sym['F'];
        sym['E']-=sym['F'];
        sym['F']=0;
        forn(i,0,sym['O']) ans.pb(1);
        sym['N']-=sym['O'];
        sym['E']-=sym['O'];
        sym['O']=0;
        forn(i,0,sym['H']) ans.pb(3);
        forn(i,0,sym['S']) ans.pb(7);
        forn(i,0,sym['I']) ans.pb(9);
        sort(all(ans));
        for(auto x:ans) cout<<x; cout<<endl;
    }
    
    
}

