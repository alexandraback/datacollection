#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
ifstream in("2.in");
ofstream out("2.out");

double f[20000][20000];
int min1(int x, int y){
	if (x<y) return x;
	return y;
}
int max1(int x, int y){
	if (x>y) return x;
	return y;
}
int abs(int x){
	if (x <0 ) return -x;
	return x;
}
int main(){
	int testsum;
	in >> testsum;
	for (int iTest = 1; iTest <= testsum; iTest++){
		out << "Case #" << iTest << ": ";
		int n, x, y;
		in >> n >> x >> y;

		int k = 0;
		while ((2*k+1)*(2*k+2)/2 <= n) k++;
		k--;
		cout << iTest << ' ' <<n<<x<<y<< k << endl;
		int remain = n - (2*k+1)*(2*k+2)/2;
		cout << remain << endl;
//		cout << endl;
//		cout << remain << endl;
		if (abs(x)+y <= k*2) out << 1.0;
		else if (abs(x)+y > k*2+2) out << 0.0;
		else{
			f[0][0] = 1.0;
			f[0][1] = 0.5;
			f[1][0] = 0.5;

			int maxnow = k*2+2;
			cout <<maxnow << endl;
//			cout <<"max" <<maxnow <<y << endl;
			for (int i = 1; i <= maxnow; i++) {
				f[0][i] = f[0][i-1] * 0.5;
				f[i][0] = f[i-1][0] * 0.5;
			}
			for (int i = 1; i <= maxnow; i++)
				for (int j = 1; j <= maxnow; j++){
					double rate1 = 0.5;
					double rate2 = 0.5;
					if (i == maxnow) rate1 = 1;
					if (j == maxnow) rate2 = 1;
					f[i][j] = f[i-1][j]*rate2 + f[i][j-1]*rate1;
//					out << i << ' '<< j << ' ' << f[i][j] << endl;
				}
			double ans = 0;
			for (int i = max1(remain-maxnow,y+1); i <= min1(maxnow, remain); i++) {
//				out << i << ' ';
				ans += f[remain - i][i];
			}
			out << ans;//setprecision

		}

		out << endl;
	}
}

