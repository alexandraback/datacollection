#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;

void tst()
{
	long long A, N;
	cin >> A;
	cin >> N;

	int a[100];
	int b[100];

	for (int i=0; i<N; i++) {
		cin >> a[i];
		b[i] =0;
	}

	if (A == 1) {
		cout << N;
		return;
	}

	std::vector<int> a_v (a, a+N);
	std::sort (a_v.begin(), a_v.end());

	int size = A;
	int add_num = 0;

	for (int i=0; i<N; i++) {
		if (a_v[i] < size) {
			size += a_v[i];
			b[i] = add_num;
		} else {
			size = size*2-1;
			add_num++;
			i--;
		}
	}

	int min = N;
	for (int i=0; i<N; i++) {
		if (b[i]+N-i-1 < min) {
			min = b[i]+N-i-1;
		}
	}

	cout << min;

	return;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		cout << "Case #" << i+1 << ": ";
		tst();
		cout << endl;
	}
}



