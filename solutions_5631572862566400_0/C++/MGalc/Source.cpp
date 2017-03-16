#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
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
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

inline bool findchain(vector<int>& prevkids, int currentkid, vector<int>& kids) {
    bool lastlike = false;
    while (true) {
        if (find(prevkids.begin(), prevkids.end(), currentkid) != prevkids.end()) {
            bool val1 = prevkids.size() >= 2;
            bool val2 = (kids[prevkids[prevkids.size() - 1]] != prevkids[prevkids.size() - 2] && kids[prevkids[prevkids.size() - 1]] != prevkids[0]);
            if (val1) {
                if (val2)
                    prevkids.pop_back();
            }
            return lastlike;
        }
        prevkids.push_back(currentkid);
        if (currentkid == kids[kids[currentkid]])
            lastlike = true;
        else lastlike = false;
        currentkid = kids[currentkid];
    }
    return false;
}

inline void findkidlike(vector<int>& prevkids, int kidlike, vector<int>& kids) {
    vector<int> likes;
    for (int i = 0; i < kids.size(); i++) {
        if (kids[i] == kidlike) {
            if (find(prevkids.begin(), prevkids.end(), i) == prevkids.end())
                likes.push_back(i);
        }
    }
    int largest = 0;
    for (int i = 0; i < likes.size(); i++) {
        vector<int> prevs = prevkids;
        int likesval = likes[i];
        bool islike = false;
        do {
            islike = findchain(prevs, likesval, kids);
            if (prevs.size() > prevkids.size())
                prevkids = prevs;
            likesval = prevkids[prevkids.size() - 1];
        } while (islike == true);
    }
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

    cin >> N;
    rep2(nn, 1, N + 1) {
        printf("Case #%d: ", nn);

        ///////////////////////////////////////

        int valin;
        cin >> valin;
        vector<int> kids;
        int largestkid = -1;
        for (int i = 0; i < valin; i++) {
            int tmp;
            cin >> tmp;
            kids.push_back(tmp - 1);
        }

        int highest = 0;
        for (int i = 0; i < kids.size(); i++) {
            vector<int> prevkids;
            int amount = 1;
            int start = kids[i];
            bool lastlike = findchain(prevkids, i, kids);

            int kidsize = prevkids.size();
            int newsize = 0;
            if (lastlike) {
                findkidlike(prevkids, prevkids[prevkids.size() - 1], kids);
            }

            if (prevkids.size() > highest) {
                highest = prevkids.size();
                if (prevkids.size() == kids.size())
                    break;
            }
        }

        cout << highest;
        ///////////////////////////////////////

        cout << endl;
    }

    return 0;
}