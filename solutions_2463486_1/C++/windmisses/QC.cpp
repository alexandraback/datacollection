#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10000001;
int sum[N];
int s[20];

bool palind(long long k) {
    int n = 0;
    while (k) {
        s[n++] = k % 10;
        k /= 10;
    }
    for (int i = 0; i < n; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

int calc(long long k) {    
    long long l = 0, r = N;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (mid * mid > k) r = mid;
        else l = mid + 1;
    }
    
	//printf("%d ", l);
    return sum[l - 1];
}

int main() {
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= 10000000; i++) {
        long long k = i;
        if (palind(k) && palind(k * k)) {
			sum[i] = 1;
			//printf("%d\n", i);
		}
        sum[i] += sum[i - 1];
    }            
    
	int T;
	scanf("%d", &T);
	
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d: ", ca);

        long long A, B;
        scanf("%lld %lld", &A, &B);
        
        printf("%d\n", calc(B) - calc(A - 1));
	}
	
	return 0;
}
