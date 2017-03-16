#include <cstdio>
#include <iostream>
using namespace std;

const double EP = 1e-6;
const int N = 100;
FILE * fin, * fout;

struct Point {
	int x, y;
	Point(int X=0, int Y=0){
		x = X; y = Y;
	}
};

int my_abs(const int & n){
	if (n < 0) return -n;
	return n;
}

int compute(const int & n){
	return (2*n+1) * (n+1);
}

int comp_pos(Point pos, int count){
	int n = (my_abs(pos.x) + pos.y) / 2, amt;
	if ((amt = compute(n)) <= count) return -1;
	if (amt > count && pos.x == 0) return 1;
	if ((amt = compute(n-1)) >= count) return 1;
	//if (amt + 2*n + pos.y+1 <= count) return -1;
	return 0;
}

void find_prob(Point pos, int count){
	int n = (my_abs(pos.x) + pos.y) / 2;
	int m = 2*n;
	count -= compute(n-1);
	double prob[N][N] = {0.0};
	prob[0][0] = 1.0;
	for (int x = 0; x <= m; ++x){
		for (int y = 0; y <= m && x+y <= count; ++y){
			if (x == m && y == m) continue;
			if (x == m)
				prob[x][y+1] += prob[x][y];
			else
				prob[x][y+1] += prob[x][y] / 2.0;
			if (y == m)
				prob[x+1][y] += prob[x][y];
			else
				prob[x+1][y] += prob[x][y] / 2.0;
		}
	}

	/*cout << n << " " << count << endl;
	for (int x = 0; x <= m; ++x){
		for (int y = 0; y <= m; ++y) cout << prob[x][y] << " ";
		cout << endl;
	}*/
	double total = 0.0;
	for (int x = pos.y+1; x <= m; ++x)
		total += prob[x][count-x];
	if (-EP <= total && total <= EP)
		cout << "0.0" << endl;
	else if (-EP <= total-1.0 && total-1.0 <= EP)
		cout << "1.0" << endl;
	else cout << total << endl;
}

int main(){
	freopen_s(&fin, "diamonds.in", "r", stdin);
	freopen_s(&fout, "diamonds.out", "w", stdout);
	int run, count, res; Point pos;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> count >> pos.x >> pos.y;
		cout << "Case #" << a << ": ";
		if ((res = comp_pos(pos, count)) < 0)
			cout << "1.0" << endl;
		else if (res > 0)
			cout << "0.0" << endl;
		else find_prob(pos, count);
	}
	return 0;
}
