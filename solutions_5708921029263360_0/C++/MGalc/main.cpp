#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <cstring>
#include <limits>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define lngth(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef vector<vector<char> > vcc;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

int largestt(vi& in) {
    int largest = 0;
    int indx = -1;
    rep(i, in.size()) {
        if (in[i] > largest) {
            largest = in[i];
            indx = i;
        }
    }
    return indx;
}

int N;
int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        freopen("small.in","rt",stdin);
        freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("a.txt", "rt", stdin);
    }
    
    cin>>N;
    rep2(nn,1,N+1) {
        printf("Case #%d: ", nn);
        ///////////////////////start//////////////

        int J, P, S, K;
        cin >> J >> P >> S >> K;
        vector<string> out;
        map<pair<int, int>, int> sp;
        map<pair<int, int>, int> sj;
        map<pair<int, int>, int> pj;
        map<pair<pair<int, int>, int>, int> jps;


        //l, m, s
        bool done = false;
        int is = 1, ip = 1, ij = 1;
        int k = K;
        int count = 0;
        auto isgood = [&](int j, int p, int s) {return (sp[make_pair(s, p)] < k) && (sj[make_pair(s, j)] < k) && (pj[make_pair(p, j)] < k) && (jps[make_pair(make_pair(j, p), s)] == 0); };
        while (!done) {
            if (isgood(ij, ip, is)) {
                count++;
                sp[make_pair(is, ip)]++;
                sj[make_pair(is, ij)]++;
                pj[make_pair(ip, ij)]++;
                jps[make_pair(make_pair(ij, ip), is)]++;
            }
            else {
                if (is < S) {
                    is++;
                }
                else {
                    if (ip < P) {
                        is = 1;
                        ip++;
                    }
                    else {
                        if (ij < J) {
                            is = 1;
                            ip = 1;
                            ij++;
                        }
                        else break;
                    }
                }
            }
        }
        cout << count << endl;
        map<pair<int, int>, int> spi;
        map<pair<int, int>, int> sji;
        map<pair<int, int>, int> pji;
        map<pair<pair<int, int>, int>, int> jpsi;
        auto isgood2 = [&](int j, int p, int s) {return (spi[make_pair(s, p)] < k) && (sji[make_pair(s, j)] < k) && (pji[make_pair(p, j)] < k) && (jpsi[make_pair(make_pair(j, p), s)] == 0); };
        done = false;
        is = 1, ip = 1, ij = 1;
        count = 0;
        while (!done) {
            if (isgood2(ij, ip, is)) {
                printf("%d %d %d\n", ij, ip, is);
                spi[make_pair(is, ip)]++;
                sji[make_pair(is, ij)]++;
                pji[make_pair(ip, ij)]++;
                jpsi[make_pair(make_pair(ij, ip), is)]++;
            }
            else {
                if (is < S) {
                    is++;
                }
                else {
                    if (ip < P) {
                        is = 1;
                        ip++;
                    }
                    else {
                        if (ij < J) {
                            is = 1;
                            ip = 1;
                            ij++;
                        }
                        else break;
                    }
                }
            }
        }
        ///////////////////////end////////////////
    }

    return 0;
}
