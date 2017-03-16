/*
 Some famous quotes about the greatest batsman on earth =>  <--------------SACHIN TENDULKAR------------------->
 "I want my son to become Sachin Tendulkar."-Brian Lara(WI)
 "We did not lose to a team called India, we lost to a man called Sachin."-Mark Taylor(AUS)
 "There are 2 kinds of batsmen in this world. 1)Sachin Tendulkar 2)All of the others."-Andy Flower(ZIM)
 "I have seen God. He bats at no.4 for India in tests."-Matthew Hayden(AUS)
 "I see myself when i see Sachin batting."-Don Bradman(AUS)
 "Commit you sins while Sachin is batting, for even the lord is watching"-(AUS fan)
 "Sachin is a genius , i am a mere mortal!"-Brian Lara(WI)
 "I would go to bed having nightemares of sachin dancing down the ground and hitting me for sixes."-Shane Warne(AUS)
 "Don't bowl him bad balls, he hits the good ones for fours."-Michael Kasprowicz(AUS)
 "Nothing bad can happen to us if we're on a plane in India with Sachin Tendulkar on it.(After terror attacks)"-Hashim Amla(RSA)
 "I never get tired during umpiring whenever sachin is on crease"-Rudi Kortzen(umpire)
 "Sachin Tendulkar! If he isn't the best player in the world, I want to see the best player in the world".-David Shepard(umpire)
 "If cricket is religion, Sachin is god"-(all fans)
 */

// <-------TEMPLATE--------->
// Author: suh_ash2008
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>

using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF (int)1e9
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair< int,int > ii;
typedef pair< int,ii > pii;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef set< int > si;
typedef vector< vi > vvi;
/*
 // <----------------------FAST I/O---------------------->
 #define MAXX 10000000
 char *ipos,*opos,InpFile[MAXX],OutFile[MAXX],DIP[30];
 inline int input_int(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');int x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
 inline LL input_LL(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');LL x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
 inline void input_st(char *s){while(*ipos<=32)++ipos;int pos=0;char c;while(true){c=*ipos++;if(c<=32){s[pos]='\0';break;}else s[pos++]=c;}}
 inline char input_ch(){while(*ipos<=32)++ipos;char c=*ipos++;return c;}
 inline void output(int x){int y;int dig=0;while(x||!dig){y=x/10;DIP[dig++]=x-((y<<3)+(y<<1))+'0';x=y;}while(dig--)*opos++=DIP[dig];}
 inline void InitFASTIO(){ipos=InpFile;opos=OutFile;fread_unlocked(InpFile,MAXX,1,stdin);}
 inline void FlushFASTIO(){fwrite_unlocked(OutFile,opos-OutFile,1,stdout);}
 // <----------------------END OF FAST I/O---------------------->
 */
// <----------------------END OF TEMPLATE---------------------->

// <---------------------MAIN CODE STARTS HERE--------------------->

string s[100];
#define MOD 1000000007

LL fact[105];

int seen[26];
int vis[26];

int main() {
    fact[0] = 1;
    FOR(i, 1, 105)  (fact[i] = fact[i-1]*i) %= MOD;
    int t = GI, kase = 0;
    while (t--) {
        REP(i, 26)  seen[i] = 0, vis[i] = 0;
        kase++;
        printf("Case #%d: ", kase);
        int n = GI;
        bool ok = true;
        bool c[26] = {false};
        int a[26] = {0};
        int b[26][26] = {0};
        int cnt1 = 0, cnt2 = 0;
        REP(i, n) {
            cin >> s[i];
            int st = 1, nd = sz(s[i])-2;
            while(st < sz(s[i]) && s[i][st] == s[i][st-1])  st++;
            while(nd >= 0 && s[i][nd] == s[i][nd+1])    nd--;
            if (st <= nd) {
                if (vis[ s[i][st]-'a' ]) {
                    ok = false;
                } else {
                    vis[ s[i][st]-'a' ] = 1;
                    FOR(j, st+1, nd+1) {
                        if (s[i][j] == s[i][j-1])   continue;
                        if (vis[ s[i][j]-'a' ]) {
                            ok = false;
                            break;
                        }
                        vis[ s[i][j]-'a' ] = 1;
                    }
                }
            }
            if (s[i][0] == s[i][sz(s[i])-1])    a[ s[i][0]-'a' ]++, cnt1++;
            else b[ s[i][0]-'a' ][ s[i][sz(s[i])-1]-'a' ]++, c[ s[i][0]-'a' ] = true, c[ s[i][sz(s[i])-1]-'a' ] = true, cnt2++;
            vis[ s[i][0]-'a' ] = 1, vis[ s[i][sz(s[i])-1]-'a' ] = 1;
        }
        if (!ok) {
            printf("0\n");
            continue;
        }
        int groups = 0;
        LL mul1 = 1;
        REP(i, 26) {
            (mul1 *= fact[ a[i] ]) %= MOD;
            if (a[i] > 0 && !c[i])  groups++;
        }
        int g[26] = {0};
        REP(i, 26) {
            g[i] = -1;
            int words = 0;
            REP(j, 26) {
                words += b[i][j];
                if (b[i][j] > 0)    g[i] = j;
            }
            if (words > 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            printf("0\n");
            continue;
        }
        int seenid = 0;
        REP(i, 26) {
            if (g[i] == -1 || seen[i])  continue;
            seenid++;
            queue<int> q;
            q.push(i);
            seen[i] = seenid;
            bool counted = false;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                if (g[x] == -1) continue;
                if (!seen[ g[x] ]) {
                    seen[ g[x] ] = seenid;
                    q.push(g[x]);
                }
                else if (seen[ g[x] ] < seenid) {
                    counted = true;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok == false)    break;
            if (!counted)   groups++;
        }
        if (ok == false) {
            printf("0\n");
            continue;
        }

        (mul1 *= fact[groups]) %= MOD;
        if (mul1 < 0)   mul1 += MOD;
        printf("%lld\n", mul1);
    }
}

