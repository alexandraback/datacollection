#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

ifstream cin("B-large.in");
ofstream cout("B.txt");

int main(){
	int T;
	double c, f, x, n, ans;
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> c >> f >> x;
		n = ceil(x / c - 2 / f - 1);
		if (n <= 0)
			ans = x / 2;
		else {
			ans = 0;
			for (int j = 0; j < n; j++)
				ans += c / (2 + j * f);
			ans = ans + x / (2 + n * f);
		}
		cout << "Case #" << i << ": " << fixed << setprecision(7) << ans << endl;
	}
}