#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

int length(int N) {
	int length = 0;
	while (N > 0) {
		length++;
		N /= 10;
	}
	return length;
}

int des(int n) {
	int des = 1;
	if (n > 0)
		for (int i = 1; i <= n; i++) {
			des *= 10;
		}
	return des;
}

int invert(int num) {
	int res = 0;
	while (num > 0)
	{
		res = res * 10 + (num % 10);
		num = num / 10;
	}
	return res;
}

long int f(long int N) {
	long int result = 0, num, d;
	
	if (N < 20)
		return N;
	if (N % 10 == 0) {
		cout << " " << N - 1 << endl;
		return f(N - 1) + 1;
	}

	switch (length(N)) {
	case 1:
		num = 0;
		break;
	case 2:
		num = 10;
		break;
	case 3:
		num = f(99) + 1;
		break;
	case 4:
		num =  f(999) + 1;
		break;
	case 5:
		num = f(9999) + 1;
		break;
	case 6:
		num = f(99999) + 1;
		break;
	case 7:
		num = f(999999) + 1;
		break;
	}
	result += num;

	if (N / des(length(N) - 1) == 1) {
		result -= 1;
	}
	
	d = des(length(N) / 2);
	num = N / d;
	result += N % d;
	result += invert(num);
	
	
	cout << N << " " << result << endl;
	return result;
}

int main()
{
	ifstream in("A-small-attempt0.in");
	ofstream out("out.out");
	/*unsigned long*/ int T, R, C, W, x, z, y, result;

	if (in.is_open()){
		in >> T;
		for (int i = 1; i <= T; i++){
			in >> R;
			in >> C;
			in >> W;
			x = C / W;
			z = C % W;
			y = 0;
			if (z > 0) y++;
			result = W + x - 1 + y;

			out << "Case #" << i << ": " << result << endl;
		}
		in.close();
	}
	out.close();
	return 0;
}