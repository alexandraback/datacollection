#include <iostream>
#include <fstream>
using namespace std;
int oo(int a, int b, int n)
{
	if (n <= a*b/2)return 0;
	int re = n - a*b / 2;
	if (re <= 2)return re * 2;
	re -= 2;
	int ans = 4;
	if (re <= a + b - 4)
	{
		ans += re * 3;
		return ans;
	}
	ans += (a + b - 4) * 3;
	re -= (a + b - 4);
	ans += re * 4;
	return ans;
}
int jj(int a, int b, int n)
{
	if (n <= (a*b+1) / 2)return 0;
	int re = n - (a*b+1) / 2;
	if (re <= (a / 2 + b / 2) * 2)return re * 3;
	int ans = (a / 2 + b / 2) * 6;
	re -= (a / 2 + b / 2) * 2;
	ans += re * 4;
	return ans;
}
int jj2(int a, int b, int n)
{
	if (n <= a*b / 2)return 0;
	int re = n - a*b / 2;
	if (re <= 4)return re * 2;
	int ans = 8;
	re -= 4;
	if (re <= ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 2)
	{
		ans += re * 3;
		return re;
	}
	ans += ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 6;
	re -= ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 2;
	ans += re * 4;
	return ans;
}
int zuixiao1(int a, int b, int n)
{
	if (b % 2 == 0)
	{
		if (n <= b / 2)return 0;
		if (n == b / 2 + 1)return 1;
		return 1 + (n - b / 2 - 1) * 2;
	}
	if (n <= (b+1) / 2)return 0;
	return (n - (b+1) / 2) * 2;
}
int re(int a, int b, int n)
{
	if (a == 1)return zuixiao1(a, b, n);
	if (b == 1)return zuixiao1(1,a, n);
	if (a % 2 == 0 || b % 2 == 0)
		return oo(a, b, n);
	int a1 = jj(a, b, n);
	int a2 = jj2(a, b, n);
	if (a1 < a2)return a1;
	return a2;
}
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.in");
	ofstream fout;
	fout.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	int T, a, n, ans;
	fin >> T;
	int p[10];
	double t[10];
	int cnt;
	for (int k = 0; k<T; k++) {
		fin >> n;
		cnt = 0;
		if (n == 1) {
			fin >> p[0] >> a >> t[0];
			if (a == 2) {
				t[1] = t[0] + 1;
				n = 2;
			}
		}
		else
			for (int i = 0; i<n; i++) {
			fin >> p[i] >> a >> t[i];
			}
		if (n>1)
			if (p[0] > p[1]) {
			int temp = p[0]; p[0] = p[1]; p[1] = temp;
			temp = t[0]; t[0] = t[1]; t[1] = temp;
			}
		if (n == 1) ans = 0; else {
			double t0 = (double)((double)(360 - p[0]) / 360.0)*(double)t[0];
			double t1 = (double)((double)(360 - p[1]) / 360.0)*(double)t[1];
			if (t1<t0) {
				if (t1 + t[1]>t0) ans = 0;  else ans = 1;
			}
			if (t0<t1) {
				if (t0 + t[0]>t1) ans = 0; else ans = 1;
			}
			if (t0 == t1) ans = 0;
		}
		fout << "Case #" << k + 1 << ": " << ans << endl;

	}
	fin.close();
	fout.close();
	return 0;

}