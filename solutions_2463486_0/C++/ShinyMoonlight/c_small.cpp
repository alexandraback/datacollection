#include <iostream>
using namespace std;

long long s[10000];
bool is_pal(long long num) {
    long long pal = 0;
    long long o = num;
    while (o) {
	pal = pal * 10 + o % 10;
	o /= 10;
    }
    return pal == num;
}

int main() {
    int cnt = 0;
    for (int n=1; ; ++n) {
	long long val = n*n;
	if (val > 1000) {
	    break;
	}
	if (is_pal(n) && is_pal(val)) {
	   s[cnt++] = val;	
	}
    }

    int n;
    cin >> n;
    for (int test=1; test<=n; ++test) {
	int a, b;
	cin >> a >> b;
	
	int result = 0;
	for (int i=0; i<cnt; ++i) {
	    if (a<= s[i] && s[i] <= b) result++;
	}
	cout << "Case #" << test << ": " << result << endl;
    }
    return 0;
}
