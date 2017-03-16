#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <list>
using namespace std;
 
#define C(_a, _v) memset(_a,_v,sizeof(_a))
#define ALL(_obj) (_obj).begin(),(_obj).end()
#define FORB(_i,_a,_b) for((_i)=(_a);(_i)<(_b);++(_i))
#define FOR(_i,_n) FORB(_i,0,_n)
#define FORS(_i,_obj) FOR(_i,(_obj).size())
 
typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<i64, i64> pii64;
typedef vector<pii> vpii;
 
template<typename T>inline bool remin(T&c,const T&n){if(n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remax(T&c,const T&n){if(c<n){c=n;return 1;}return 0;}
template<typename T>inline void addmod(T& c,const T&n,const T&m){c=(c+n)%m;}
 
int _in;int in(){scanf("%d",&_in);return _in;}

// stuff cutline

const int N = 205;

int judge[N], sum, n;

bool win(int who, double p) {
	int i, pussy = 0;
	double left = 1 - p, score = judge[who] + sum * p, consume;
	FOR (i, n) {
		if (i != who) {
			if (judge[i] < score) {
				consume = double(score - judge[i]) / double(sum);
				if (consume > left) return false;
				left -= consume;
			}
		}
	}
	return true;
}

int main() {
	freopen("C:\\Users\\anonymous\\Downloads\\A-small-attempt2.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	double left, right, middle;
	int t = in(), it, i, j;
	FOR (it, t) {
		n = in();
		sum = 0;
		FOR (i, n) sum += judge[i] = in();
		printf("Case #%d: ", it + 1);
		FOR (j, n) {
			{
				left = 0, right = 1;
				FOR (i, 100) {
					middle = (left + right) / 2.0;
					(win(j, middle) ? left : right) = middle;
				}
			}
			printf(" %.10lf", left * 100.0);
		}
		putchar('\n');
	}
	return 0;
}