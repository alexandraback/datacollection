#include <bits/stdc++.h>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("segmentupdate.in", "r", stdin);
//	 freopen("segmentupdate.out", "w", stdout);
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

const int N = 3e3 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;

int fir, sec;

int get_dec(string s){
	int res = 0;
	for (int i = 0; i < (int)s.length(); ++i)
		res = res*10 + (s[i] - '0');
	return res;
}

string s1, s2;

int ansd, ansf, anss;

void upd(){
	int tans = abs(sec - fir);
	if (tans < ansd || (tans == ansd && (fir < ansf || (fir == ansf && sec < anss)))){
		ansd = tans;
		ansf = fir;
		anss = sec;
	}
}

void go2(string s){
	int f = -1;
	for (int i = s.length() - 1; i >= 0; --i){
		if (s[i] == '?'){
			f = i;
		}
	}
	if (f == -1){
		//dbg2("second: ", s);
		sec = get_dec(s);
		upd();
		return;
	}
	for (int i = '0'; i <= '9'; ++i){
		s[f] = i;
		go2(s);
		s[f] = '?';
	}
}

void go(string s){
	int f = -1;
	for (int i = s.length() - 1; i >= 0; --i){
		if (s[i] == '?'){
			f = i;
		}
	}
	if (f == -1){
		//dbg2("first: ", s);
		fir = get_dec(s);
		go2(s2);
		return;
	}
	for (int i = '0'; i <= '9'; ++i){
		s[f] = i;
		go(s);
		s[f] = '?';
	}
}

string getstr(int a, int len){
	string res;
	while (a){
		res = char(a % 10 +'0') + res;
		a /= 10;
	}
	res = string(len - res.length(), '0') + res;
	return res;
}


void task(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> s1 >> s2;
		ansd = INF;
		go(s1);
		string ans1 = getstr(ansf, s1.length());
		string ans2 = getstr(anss, s1.length());
		printf("Case #%d: %s %s\n", i + 1, ans1.c_str(), ans2.c_str());
	}


}

