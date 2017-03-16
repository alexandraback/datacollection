#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10+ch-'0';
}
double C, F, X;
void run(int Ca) {
	printf("Case #%d: ", Ca);
	scanf("%lf%lf%lf", &C, &F, &X);
	double rate = 2, t = 0, ans = X / 2.0;
	for (int i=1; t<=ans; ++i) {
		t += C / rate;
		rate += F;
		ans = min(ans, t + X / rate);
	}
	printf("%.7lf\n", ans);
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) run(i);
	return 0;
}
