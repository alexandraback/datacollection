#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "B-large.in", "r", stdin);
	freopen_s(&fout, "cookie.out", "w", stdout);
	int run; double cost, rate, goal, time, cur_r, cur_t, temp;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> cost >> rate >> goal;
		time = goal + 1.0; cur_r = 2.0; cur_t = 0.0;
		while ((temp = cur_t + goal / cur_r) < time){
			time = temp;
			cur_t += cost / cur_r;
			cur_r += rate;
		}
		cout << "Case #" << a << ": " << setprecision(7) << fixed << time << endl;
	}
	return 0;
}
