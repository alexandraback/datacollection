#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cmath>
#include <cassert>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("bisector.in", "r", stdin);
//	 freopen("bisector.out", "w", stdout);
#endif
	task();
#ifdef LUNAWYLL
	//cout << "\n============\n" <<(double)clock()/CLOCKS_PER_SEC;
#endif
	return 0;
}

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; "<<\
#b << " = " << (b) << endl;
#define dbg3(a, b, c) cout << #a << " = " << (a) << "; "<<\
		#b << " = " << (b) << "; "<<\
#c << " = " << (c) << endl;
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#endif

typedef long long int llint;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ALL(v) ((v).begin()), ((v).end())

const int N = 2e5 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;

const double PI = acos(-1);


struct St{
	int j, p, s;
};

vector <St> a;
int J, P, S, k;

vector<vi>JP(J, vi(P));
vector<vi>JS(J, vi(S));
vector<vi>PS(P, vi(S));
vector<vector<vi>> JPS(J, vector<vi>(P, vi(S)));
vector<St> ans;

bool isok(int i){
//	dbg("isok");
	int j = a[i].j, p = a[i].p, s = a[i].s;
//	dbg3(j,p,s);
//	dbg3(JP[j][p], JS[j][s], PS[p][s]);
//	dbg(JPS[j][p][s]);
	if (JP[j][p] < k && JS[j][s] < k && PS[p][s] < k &&
			JPS[j][p][s] == 0){
		//dbg("ok");
		++JP[j][p];
		++JS[j][s];
		++PS[p][s];
		++JPS[j][p][s];
		return true;
	} else{
		return false;
	}
}

void ab(int i){
	int j = a[i].j, p = a[i].p, s = a[i].s;
	--JP[j][p];
	--JS[j][s];
	--PS[p][s];
	--JPS[j][p][s];
}

bool go(int beg, int carry){
	//dbg3("go", beg, carry);
	if (carry == 0){
		return true;
	}
	for (int i = beg; i < a.size(); ++i){
		if (isok(i)){
			if (go(i + 1, carry - 1)){
				ans.push_back({a[i].j + 1,a[i].p + 1,a[i].s + 1});
				return true;
			}
			ab(i);
		}

	}
	return false;
}


void task(){
	int t;
	cin >> t;

	for (int tnum = 1; tnum <= t; ++tnum){

		cin >> J >> P >> S>> k;
		a.clear();
		JP = vector<vi>(J, vi(P));
		JS = vector<vi>(J, vi(S));
		PS = vector<vi>(P, vi(S));
		JPS = vector<vector<vi>> (J, vector<vi>(P, vi(S)));
		int sz = 0;
		for (int j = 0; j < J; ++j)
			for (int p = 0; p < P; ++p)
				for (int s = 0; s < S; ++s, ++sz)
					a.push_back({j,p,s});

		for (int i = a.size(); i > 0; --i){
			//dbg(i);
			if (go(0, i)){
				printf("Case #%d: %d\n", tnum, ans.size());
				for (auto x: ans){
					cout << x.j << ' ' << x.p << ' ' << x.s << endl;
				}
				ans.clear();
				break;
			}
			ans.clear();
		}



	}

}
