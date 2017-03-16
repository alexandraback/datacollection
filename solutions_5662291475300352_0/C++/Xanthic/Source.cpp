#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<functional>
#include<climits>
#define eps 1e-9
const int mod = 281683;
using namespace std;

int t, n, h, d[2], m[2];
double s[2];
int main() {
  freopen("C-small-1-attempt2.in", "r", stdin);
  freopen("C-small-attempt1Result.txt", "w", stdout);
  scanf("%d", &t);
  for (int test = 1; test <= t; ++test) {
    scanf("%d", &n);
    int ret = 0;
    if (n == 1) {
	cin >> d[0] >> h >> m[0];
	d[1] = d[0];
	m[1] = m[0] + 1;
    }
    else {
	cin >> d[0] >> h >> m[0];
	cin >> d[1] >> h >> m[1];
    }
    s[0] = 360.0 / m[0];
    s[1] = 360.0 / m[1];
    int passesLast = 0;
    if (((360 - d[0])*1.0)/s[0] > ((360 - d[1])*1.0)/s[1]) {
	passesLast = 1;
    }
    double lastTime = (360.0 - d[passesLast])/(s[passesLast] * 1.0);
    double firstDist = s[passesLast ^ 1] * 1.0 * lastTime;
    if (firstDist - 1.0*d[passesLast ^ 1] >= 360) {
	ret = 1;
    }
    else ret = 0;
    printf("Case #%d: %d\n", test, ret);
  }
  return 0;
}