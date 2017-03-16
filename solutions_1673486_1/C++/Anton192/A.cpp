#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 999999999
#define EPS .000000001
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long LL;
typedef unsigned long long ULL;
typedef pair < int, int > II;
typedef pair < ULL, ULL > ULLULL;
typedef vector < int > VI;
typedef vector < double > VD;
typedef vector < II > VII;

VD t, t2;

int main(){
    freopen("input_large.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n = 0;
    cin >> n;
    for(int sh = 0; sh < n; ++sh){
        int a, b;
        cin >> a >> b;
        t.resize(a);
        t2.resize(a);
        for(int j = 0; j < a; ++j)cin >> t[j];
        t2[0] = t[0];
        for(int j = 1; j < a; ++j)t2[j] = t2[j-1] * t[j];
        //for(int i = 0; i < a; ++i)cout << t2[i] << " "; cout << endl;
        double MN = INF;
        for(int j = 0; j <= a; ++j){
            MN = min(MN, (j ? t2[j-1] : 1) * (b - j + 1 + (a-j)) + (1 - (j ? t2[j-1] : 1)) * (b - j + 1 + (a-j) + b+1));
            //cout << (j ? t2[j-1] : 1) << " -- " << (b - j + 1 + (a-j)) << "\n";
        }//cout << endl;
        MN = min(MN, (double)(b+2));
        //cout << MN << endl;
        printf("Case #%d: %.10f\n", sh+1, MN);
    }
    return 0;
}
