#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

const char gtoen[][2] = {
{'a', 'y'},
{'b', 'h'},
{'c', 'e'},
{'d', 's'},
{'e', 'o'},
{'f', 'c'},
{'g', 'v'},
{'h', 'x'},
{'i', 'd'},
{'j', 'u'},
{'k', 'i'},
{'l', 'g'},
{'m', 'l'},
{'n', 'b'},
{'o', 'k'},
{'p', 'r'},
{'q', 'z'},
{'r', 't'},
{'s', 'n'},
{'t', 'w'},
{'u', 'j'},
{'v', 'p'},
{'w', 'f'},
{'x', 'm'},
{'y', 'a'},
{'z', 'q'}};

int tc;
char ss[1000];

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d\n", &tc);
	REP(ic,tc){
		cout << "Case #" << ic+1 << ": ";
		gets (ss);
		for (int i = 0; ss[i]; ++i){
			if (ss[i]==' ') cout << ss[i];
			else cout << gtoen[ss[i]-'a'][1];
		}
		cout << endl;
	}
	return 0;
};