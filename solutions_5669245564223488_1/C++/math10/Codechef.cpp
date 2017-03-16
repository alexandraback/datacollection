/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case #%d:",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

string st[111];
int cnt[30],n,cut,take[30],hh[110];
set<int >start[30],end[30],arr[30];
int64 fact[110];

void call(string stt) {
    int len = stt.size();
    take[stt[len-1]-'a'] = true;
    take[stt[0]-'a'] = true;
    int cc = stt[len-1] - 'a';
    if(start[cc].size() == 1) {

        forstl(it,start[cc]) {
            if(hh[*it]) continue;
            hh[*it] = true;
            call(stt + st[*it]);
            return;
        }
    } else {
        cc = stt[0] - 'a';
        if(end[cc].size() == 1) {

            forstl(it,end[cc]) {
                if(hh[*it]) continue;
                hh[*it] = true;
                call(st[*it] + stt);
                return;
            }
        }
    }
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    fact[0] = 1;
    For(i,100) {
        fact[i] = (fact[i-1]*i)%mod;
    }
    int t = II;
    For(cs,t) {
        n = II;
        memo(cnt,0);
        memo(take,0);
        memo(hh,0);
        rep(i,n) {
            cin >> st[i] ;
            string tmp = "";
            set<char >s;
            int len = st[i].size();
            rep(j,len) {
                char ch = st[i][j];
                tmp += st[i][j];
                cnt[ch-'a']++;
                while(j<len && ch == st[i][j]) {
                    j++;
                }
                j--;
                s.insert(ch);
            }
            if(s.size() == 1) {
                arr[st[i][0]-'a'].insert(i);
            } else {
                start[st[i][0]-'a'].insert(i);
                end[st[i][st[i].size()-1]-'a'].insert(i);
            }
            st[i] = tmp;
        }

        bool flag = true;
        rep(i,n) {
            int len = st[i].size();
            For(j,len-2) {
                char ch = st[i][j];
                if(ch != st[i][j-1] && ch != st[i][j+1] && cnt[ch-'a'] > 1) {
                    //cout << j << " " << ;
                    flag = false;
                }
            }
        }
        cut = 0;
        rep(i,26) if(start[i].size() > 1 || end[i].size() > 1) flag = false;
        OC;
        if(flag == false) cout << " 0\n";
        else {
            rep(i,30) {
                if(take[i]) continue;
                int a = arr[i].size() ,b = start[i].size() ,c = end[i].size() ;
                if(b != 0) {
                    int id ;
                    forstl(it,start[i]) {
                        id = *it;
                        break;
                    }
                    hh[id] = true;
                    cut++;
                    call(st[id]);
                } else if(c != 0) {
                    int id;
                    forstl(it,end[i]) {
                        id = *it;
                        break;
                    } cut++;
                    hh[id] = true;
                    call(st[id]);
                } else if(a != 0) {
                    int id;
                    forstl(it,arr[i]) {
                        id = *it;
                        break;
                    } cut++;
                }
            }
            int64 ans = fact[cut]%mod;
            //cout << cut << endl;
            rep(i,26){
                ans = (ans*fact[arr[i].size()])%mod;
            }
            cout << " " << ans << endl;
        }
        rep(i,27){
            start[i].clear();
            end[i].clear();
            arr[i].clear();
        }
    }
}
