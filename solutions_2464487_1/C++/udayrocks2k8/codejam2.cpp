#include <iostream>
using namespace std;

typedef long long int i64;
i64 r, t;
int highest_set(i64 n) {
    int p = 0;
    while (n) {
        n /= 2;
        p++;
    }
    return p;
}

bool compare(i64 n)
{
    i64 p = (2 * r  -1);
    int a = highest_set(p);
    int b = highest_set(n);
    i64 c, d;
    if (a + b <= 64) {
        c = p * n;
    } else {
        return true;
    }
    if (2 * b <= 63) {
        d = 2 * n * n;
    } else {
        return true;
    }
    i64 e = (c + d);
    if (e < 0) {
        return true;
    }
    return e > t;
}
int binary_search(i64 low,i64 high)
{
	i64 mid;
    while(low<high)
	{
		mid=(low+high)>>1;
        if(compare(mid))
			high=mid;
		else
			low=mid+1;
    }
	return low;
}

void getResult() {
    cin >> r >> t;
    cout << binary_search(0, t) - 1 << endl;
}



int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}