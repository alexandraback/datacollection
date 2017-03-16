
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (i = 0; i < (int)(n); ++i)
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define updMax(a, b) ((a) = max((a), (b)))
#define updMin(a, b) ((a) = min((a), (b)))

const int maxn = 2000 + 100;
const double eps = 1e-17;

double x[maxn], t[maxn];
double D, a;
int N, A;

double calcT(double s, double v0)
{
	double D = sqr(v0) + 2*s*a;
	return (-v0 + sqrt(D)) / a;
}

double carPosition(double t0)
{
	int i;
	forn(i, N-1) {
		if (t[i] - eps <= t0 && t[i + 1] + eps >= t0) {
			return x[i] + ((x[i + 1] - x[i]) / (t[i + 1] - t[i])) * abs(t0 - t[i]);
		}
	}
	return 1e100;
}

double nextCarPosition(double pos, double &vCar, int &start)
{
	int i;
	for(i = start; i < N-1; ++i) {
		if (x[i] - eps <= pos && pos <= x[i + 1] + eps) {
			vCar = (x[i + 1] - x[i]) / (t[i + 1] - t[i]);
			start = i + 1;
			return x[i + 1];
		}
	}
	vCar = 1e100;
	start = N;
	return 1e100;
}

void solve()
{
	double res = 0, v = 0, pos = 0, posCar = x[0], s, t0, vCar, lastPos;
	int start = 0;
	int i, j;
	while (1) {
		if (posCar >= D - eps) {
			t0 = calcT(D - pos, v);
			res += t0;
			break;
		}
		t0 = calcT(posCar - pos, v);
		v += a*t0;
		pos = posCar;
		if (abs(t0) < eps) {
			lastPos = posCar;
			posCar = nextCarPosition(posCar, vCar, start);
			posCar = min(posCar, D);
			//v = min(v, vCar);
			if (vCar > v + 1e-2) {
				double t1 = (vCar - v) / a;
				double dist1 = v*t1 + 0.5*a*sqr(t1);
				if (dist1 > posCar - lastPos) {
					t1 = calcT(posCar - lastPos, v);
					pos = posCar;
				} else {
					pos += dist1;
				}
				res += t1;
			}
			if (pos < posCar) {
				double dist1 = posCar - pos;
				res += dist1 / vCar;
				pos = posCar;
				v = vCar;
			}
		} else {
			res += t0;
			posCar = carPosition(res);
		}
	}
	cout << res << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << fixed << setprecision(12);

	ios::sync_with_stdio(false);
	int T, test, i;
	cin >> T;

	forn(test, T) {
		cout << "Case #" << test + 1 << ":\n";
		cin >> D >> N >> A;
		forn(i, N)
			cin >> t[i] >> x[i];
		forn(i, A) {
			cin >> a;
			if (test == 2) {
				int st = 1;
				++st;
			}
			solve();
		}
	}

	return 0;
}