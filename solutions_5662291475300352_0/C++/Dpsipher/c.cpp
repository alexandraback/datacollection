
/**
 * author : dpsipher
 */
#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fill(x,y) memset(x,y,sizeof(x))
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%l64d",&x)
#define ul(x) scanf("%l64u",&x)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;                         
typedef vector<int> vi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;

using namespace std;

int main()
{
    int tests;
    i(tests);
    rep(testno, tests) {
        printf("Case #%d: ", testno+1);
        int n, d1,d2, m1, m2, h;
        cin >> n;
        cin >> d1 >> h >> m1;
        if (h > 1) {
            d2 = d1; 
            m2 = m1 + 1;
        } else {
            cin >> d2 >> h >> m2;
        }
        if (d1 > d2) {
            int tmp = d2; d2 = d1; d1 = tmp;
            tmp = m2; m2=m1; m1 = tmp;
        }
        int crossed = 0;
        while(d1 <= 360) {
            d2 += m2;
            d1 += m1;
            if (d1 >= d2){ crossed = 1;break;}
        }
        cout << crossed << endl;

    }
    return 0;
}
