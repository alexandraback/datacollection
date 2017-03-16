#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstring>
#include<ctime>
#include<map>
#define REP(i,N) for(int i=0;i<N;i++)
#define REPD(i,N) for(int i=(int)N-1;i>=0;i--)
#define foru(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define ford(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define inp(a,n) cin >> n; REP(i,n) cin >> a[i]
#define inp2(x,y,n) cin >> n; REP(i,n) cin >> x[i] >> y[i]
#define out(a,n) REP(i,n) cout << a[i] << ' '
#define read freopen("","r",stdin)
#define write freopen("","w",stdout)
#define fi first
#define se second
#define sz size()
#define pb push_back
#define pf push_front
#define ins insert
#define be begin()
#define en end()
#define iall begin(),end()
#define sqr(a) (a)*(a)
#define setp(x) cout.precision(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const float eps=1e-8;
const ll lloo=1e18;
const int oo=1e9;
const char mul[4][4]={    {1,2,3,4},
                    {2,1,4,3},
                    {3,4,1,2},
                    {4,3,2,1}     };
const int dau[4][4]={ {1,1,1,1},
                {1,-1,1,-1},
                {1,-1,-1,1},
                {1,1,-1,-1}    };
int get(char a) {
    switch (a) {
        case '1': return 1;
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
    }
}
char rev(int x) {
    switch(x) {
        case 1: return '1';
        case 2: return 'i';
        case 3: return 'j';
        case 4: return 'k';
    }
}
char nhan(char a, char b, int &d) {
    d=d*dau[get(a)-1][get(b)-1];
    return rev(mul[get(a)-1][get(b)-1]);
}
string s,tmps;
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("result.out","w",stdout);
    int T;
    cin >> T;
    foru(test,1,T) {
        string res="NO";
        int L,X;
        cin >> L >> X;
        cin >> s;
        tmps=s;
        int d=1;
        char tich='1';
        REP(i,L) tich=nhan(tich,s[i],d);
        int d3=1;
        if (X/2%2) d3=-1;
        if (d==-1&&(X%2==0)) d=1;
        if ((get(tich)>1&&(X%2==0)&&(d*d3==-1))||(get(tich)==1&&d==-1)) {
            foru(st,1,min(X,4)) {
                char tich1='1';
                char tich2='1';
                int luui;
                int luuj;
                REP(i,s.size()) {
                    tich1=nhan(tich1,s[i],d);
                    luui=i;
                    if (tich1=='i') break;
                }
                REPD(i,s.size()) {
                    tich2=nhan(tich2,s[i],d);
                    luuj=i;
                    if (tich2=='k') break;
                }
                if (luui<luuj) {
                    res="YES";
                    break;
                }
                s+=tmps;
            }
        }
        cout << "Case #" << test<< ": " << res << endl;
    }
}
