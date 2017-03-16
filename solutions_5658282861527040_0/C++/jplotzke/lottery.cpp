#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "B-small-attempt0.in", "r", stdin);
	freopen_s(&fout, "lottery.out", "w", stdout);
	int run, num1, num2, ans, cnt;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> num1 >> num2 >> ans; cnt = 0;
		for (int x = 0; x < num1; ++x)
			for (int y = 0; y < num2; ++y)
				if ((x & y) < ans) ++cnt;
		cout << "Case #" << a << ": " << cnt << endl;
	}
	return 0;
}
