#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

typedef long long int int64;



//jamA
int main(void)
{
	int nTestCase, repeat;
	int i;

//	int64 v1[800], v2[800];
	vector<int64> v1, v2;
	int64 r, t;
	int64 S, N, a, b, c;

	cin >> nTestCase;
	for(repeat = 1; repeat <= nTestCase; repeat++){
		cin >> r;
		cin >> t;

		// N個のリングを塗りつぶすために必要な容量は、
		// N(2r+2N-1) mL　である。
		// N(2r+2N-1) <= t　を満たす最大のNを求める。
		// 最初は、ある程度の誤差を見込んで初期値を求める

//		double t = sqrt(pow(r / 2.0, 2) + 

		N = 1;
		for(i = 0; i < 64; i++){
			S = N * (2 * r + 2 * N - 1);
			if(S >= t){
				break;
			}
			N *= 2;
//			cerr << "Case #" << repeat << ": searching...N=" << N << ", S=" << S << ", t=" << t << endl;
		}
		// ここで、S(N) >= tとなっているはず
		if(S == t){ // すでにぴったり答えが出たら、即終了
			cout << "Case #" << repeat << ": " << N << endl;
			continue;
		}

		// ２分割しながら、サーチ
		// a～bまでの間を徐々に狭める
		// aは含むが、bは含まない
		// b - a = 1　のときのaが答え。
		a = N / 2;
		b = N;
		while(1){
			if(b - a == 1){ // OK
				cout << "Case #" << repeat << ": " << a << endl;
				break;
			}
			c = (a + b) / 2; // 真ん中
			S = c * (2 * r + 2 * c - 1); // c回の円を描くときに必要な容量

//			cerr << "Case #" << repeat << ": searching...N=[" << a << ", " << b << "), S=" << S << ", t=" << t << endl;
			if(S == t){
				cout << "Case #" << repeat << ": " << c << endl;
				break;
			}
			if(S > t){ // 範囲更新
				b = c;
			}else{
				a = c;
			}
		}
	}

	return 0;
}

