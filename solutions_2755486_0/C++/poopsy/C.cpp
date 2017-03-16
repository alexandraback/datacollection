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
#include <limits.h>
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
#define INF 100000000000000000LL
#define EPS (double)1e-6
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
 #define MAXX 4000000
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

int h[2000];
int h2[2000];
int d[15];
int n[15];
int w[15];
int e[15];
int s[15];
int delta_d[15];
int delta_p[15];
int delta_s[15];

si valid_days;
vvi nomads(676061);

int main(){
    ifstream fin("C-small-attempt0.in");
    ofstream fout("C-small-attempt0.out");
    int t, kase = 0;
    fin >> t;
    while(t--) {
        kase++;
        fout << "Case #" << kase << ": ";
        int N;
        fin >> N;
        REP(i, 2000)    h[i] = h2[i] = 0;
        REP(i, 676061)  nomads[i].clear();
        nomads.clear();
        nomads.resize(676061);
        valid_days.clear();
        
        REP(i, N) {
            fin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
            w[i] = 2*(w[i] + 500), e[i] = 2*(e[i] + 500);
            delta_p[i] *= 2;
            REP(j, n[i]) {
                valid_days.insert(d[i] + j*delta_d[i]);
                nomads[d[i] + j*delta_d[i]].pb(i);
            }
        }
        int ret = 0;
        tr(it, valid_days) {
            int i = *(it);
            REP(j, sz(nomads[i])) {
                int inx = nomads[i][j];
                int k = (i - d[inx]) / delta_d[inx];
                int l = w[inx]+ k*delta_p[inx], r = e[inx]+ k*delta_p[inx];
                int s1 = s[inx]+ k*delta_s[inx];
                bool ok = 1;
                FOR(p, l, r+1) {
                    if(h[p] < s1) {
                        ok = 0;
                        break;
                    }
                }
                FOR(p, l, r+1)  h2[p] = max(h2[p], s1);
                if(!ok) ret++;
            }
            REP(i, 2000)    h[i] = h2[i];
        }
        fout << ret << endl;
    }
    fin.close();
    fout.close();
}
