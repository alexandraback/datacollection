#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "input.txt"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

int solve(vector<pair<double, int> > &a, int id) {
    int score = 0;
    int stone = 0;
    rp(i, a.size()) {
        if (a[i].second != id) {
            ++stone;
        } else {
            if (stone >0){
                ++score;
                --stone;
            }
        }
    }
    return score;

}

int solve2(vector<pair<double, int> > &a, int id) {
    int score = 0;
    rp(i, a.size()) {
        if (a[i].second == id) {
            ++score;
        } else {
            if (score >0){
                --score;
            }
        }
    }
    return score;

}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int n;
        vector<pair<double, int> > a;
        cin >>n;
        rp(i, n){ double t; cin >> t; a.pb(make_pair<double, int>(t, 0));}
        rp(i, n){ double t; cin >> t; a.pb(make_pair<double, int>(t, 1));}
        sort(all(a));
		printf("Case #%d: %d %d\n",tst, solve(a, 0), solve2(a, 0));
	}
	
	return 0;
}