#include <iostream>
using namespace std;

long long find(long long start, long long end, long long r, long long t) {
	long long i;
       	while (start < end) {
		i = (start + end) / 2;
		long data = (i - r + 1) *(i + r) / 2;
		if (data > t)
			end = i;
		else if (data == t)
			break;
		else if (data+i+1 > t) 
			break;
		else 
			start = i;	
	}
	if ((i - r) % 2 != 0)
		return (i - r)/2 +1;
	else
		return (i - 1 -r) /2 +1;
}
int main()
{
	int T;
	long long r, t;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> r >> t;
		cout << "Case #" << i <<": " << find(1, 2*t, r , t) << endl;
	} 
}
