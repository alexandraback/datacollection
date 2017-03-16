#include <iostream>
#include <cmath>
using namespace std;

unsigned long long s[50];
bool is_pal(long long num) {
    unsigned long long pal = 0;
    unsigned long long o = num;
    while (o) {
	pal = pal * 10 + o % 10;
	o /= 10;
    }
    return pal == num;
}

int main() {
    int cnt = 0;
    for (unsigned long long n=1; ; ++n) {
	unsigned long long val = n*n;
	if (log10(val) > 15) {
	    break;
	}
	if (is_pal(n) && is_pal(val)) {
	   s[cnt++] = val;	
	}
    }

    int n;
    cin >> n;
    for (int test=1; test<=n; ++test) {
	unsigned long long a, b;
	cin >> a >> b;
	
	int result = 0;
	for (int i=0; i<cnt; ++i) {
	    if (a<= s[i] && s[i] <= b) result++;
	}
	cout << "Case #" << test << ": " << result << endl;
    }
    return 0;
}
