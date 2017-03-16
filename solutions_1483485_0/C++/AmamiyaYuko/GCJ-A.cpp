#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

//kAc
#define ALL(x) x.begin(), x.end()
#define foreach(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)a.size()
#define VEC vector
#define STR string
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }
using namespace std;
const char * convert = "yhesocvxduiglbkrztnwjpfmaq";
int n;
char buf[10001];
int main()
{
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
	scanf("%d", &n); scanf(" ");
	for (int i = 1; i <= n; i++){
		printf("Case #%d: ", i);
		gets(buf);
		for (char *S = buf; *S; S++){
			if (!isalpha(*S)) putchar(' ');
			else putchar(convert[*S - 'a']);
		}
		puts("");
	}
}
