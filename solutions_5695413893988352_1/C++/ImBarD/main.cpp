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
        string s,t;
        string anss, anst;
        string as, at;
        cin>>s>>t;
        int n = s.length();
        bool eq = true;
        forn(i,0,n) {
            if (s[i] == t[i]) {
                if (t[i] != '?') {
                    anss.pb(s[i]);
                }
                else anss.pb('0');
            }
            else {
                if(s[i]=='?') anss.pb(t[i]);
                else if(t[i] == '?') anss.pb(s[i]);
                else {
                    eq = false;
                    break;
                }
            }
        }
        if(eq) {
            cout<<anss << " " << anss<<endl;
            continue;
        }
        ll bestdiff = 1e18 +1;
        ll best1 = 1e18 +1;
        ll best2 = 1e18 +1;
        forn(j,0,n) {
            anst.clear();
            anss.clear();
            // s[j] < t[j]
            eq = true;
            forn(i,0,j) {
                if (s[i] == t[i]) {
                    if (t[i] != '?') {
                        anss.pb(s[i]);
                    }
                    else anss.pb('0');
                }
                else {
                    if(s[i]=='?') anss.pb(t[i]);
                    else if(t[i] == '?') anss.pb(s[i]);
                    else {
                        eq = false;
                        break;
                    }
                }
            }
            if(!eq) break;
            anst = anss;
            if (s[j] == '?' && t[j] == '?') {
                anss.pb('0');
                anst.pb('1');
            }
            else if(s[j] == '?') {
                if(t[j] == '0') continue;
                else {
                    anst.pb(t[j]);
                    anss.pb((char)(t[j]-1));
                }
            }
            else if(t[j] == '?') {
                if(s[j] == '9') continue;
                else {
                    anss.pb(s[j]);
                    anst.pb((char)(s[j]+1));
                }
            }
            else if(s[j] < t[j]) {
                anss.pb(s[j]);
                anst.pb(t[j]);
            }
            else if(s[j] == t[j]) continue;
            else break;
            forn(i,j+1,n) {
                if(s[i] == '?') anss.pb('9');
                else anss.pb(s[i]);
                if(t[i] == '?') anst.pb('0');
                else anst.pb(t[i]);
            }
            ll snum = stoll(anss);
            ll tnum = stoll(anst);
            if ((abs(snum-tnum) < bestdiff) || (abs(snum-tnum) == bestdiff && snum < best1) || (abs(snum-tnum) == bestdiff && snum == best1 && snum < best2)) {
                bestdiff = abs(snum - tnum);
                best1 = snum;
                best2 = tnum;
                as = anss;
                at = anst;
            }
        }
        forn(j,0,n) {
            
            anst.clear();
            anss.clear();
            // s[j] > t[j]
            eq = true;
            forn(i,0,j) {
                if (s[i] == t[i]) {
                    if (t[i] != '?') {
                        anss.pb(s[i]);
                    }
                    else anss.pb('0');
                }
                else {
                    if(s[i]=='?') anss.pb(t[i]);
                    else if(t[i] == '?') anss.pb(s[i]);
                    else {
                        eq = false;
                        break;
                    }
                }
            }
            if(!eq) break;
            anst = anss;
            if (s[j] == '?' && t[j] == '?') {
                anss.pb('1');
                anst.pb('0');
            }
            else if(s[j] == '?') {
                if(t[j] == '9') continue;
                else {
                    anst.pb(t[j]);
                    anss.pb((char)(t[j]+1));
                }
            }
            else if(t[j] == '?') {
                if(s[j] == '0') continue;
                else {
                    anss.pb(s[j]);
                    anst.pb((char)(s[j]-1));
                }
            }
            else if(s[j] > t[j]) {
                anss.pb(s[j]);
                anst.pb(t[j]);
            }
            else if(s[j] == t[j]) continue;
            else break;
            forn(i,j+1,n) {
                if(s[i] == '?') anss.pb('0');
                else anss.pb(s[i]);
                if(t[i] == '?') anst.pb('9');
                else anst.pb(t[i]);
            }
            ll snum = stoll(anss);
            ll tnum = stoll(anst);
            if ((abs(snum-tnum) < bestdiff) || (abs(snum-tnum) == bestdiff && snum < best1) || (abs(snum-tnum) == bestdiff && snum == best1 && snum < best2)) {
                bestdiff = abs(snum - tnum);
                best1 = snum;
                best2 = tnum;
                as = anss;
                at = anst;
            }
        }
        cout << as <<" " << at <<endl;
    }
    
    
}

