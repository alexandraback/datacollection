#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int n, best;
bool sett = false;
string c, j, temp = "0123456789";
string ansC, ansJ;

LL val(string pp){
	LL base = 1LL, vall = 0;
	for(int i = pp.size()-1;i>=0;i--){
		vall += (base * (LL)(pp[i] - '0'));
		base = base * 10LL;
	}
	return vall;
}

void solve2(int idx, string s1, string s2){
	if(idx == s2.size()){
		if(sett == false){
			ansC = s1;ansJ = s2;
			best = abs(val(s1) - val(s2));
			sett = true;
		}else{
			LL vv1 = val(s1), vv2 = val(s2);
			if(abs(vv1 - vv2) < best){
				ansC = s1, ansJ = s2;
				best = abs(val(s1) - val(s2));
			}else if(abs(vv1 - vv2) == best){
				if(val(s1) < val(ansC)){
					ansC = s1, ansJ = s2;
					best = abs(val(s1) - val(s2));
				}else if(val(s1) == val(ansC)){
					if(val(s2) < val(ansJ)){
						ansC = s1, ansJ = s2;
						best = abs(val(s1) - val(s2));
					}
				}
			}
		}
		return;
	}
	string cc = s2;
	if(cc[idx] == '?'){
		for(int i = 0;i < 10;i++){
			cc[idx] = temp[i];
			solve2(idx+1, s1, cc);
			cc[idx] = '?';
		}
	}else{
		solve2(idx+1, s1, s2);
	}
}

void solve(int idx, string s1){
	if(idx == s1.size()){
		solve2(0, s1, j);
		return;
	}
	string cc = s1;
	if(cc[idx] == '?'){
		for(int i = 0;i < 10;i++){
			cc[idx] = temp[i];
			solve(idx+1, cc);
			cc[idx] = '?';
		}
	}else{
		solve(idx+1, s1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cout << "Case #" << casee << ": " ;
		cin >> c >> j;
		sett = false;
		solve(0, c);
		cout << ansC << " " << ansJ << endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

