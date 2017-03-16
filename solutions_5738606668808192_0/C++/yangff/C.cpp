#include <cstdio>
#include <random>

const int N = 16;
const int J = 50;

long long fastmul[11][32];

long long excute(int base, unsigned val){
	if (base == 2)
		return val;
	long long result = 0;
	for (int i = 0; i < N; i++)
		if ((val >> i)&1)
			result += fastmul[base][i];
	return result;
}

std::random_device rd;
std::uniform_int_distribution<unsigned int> dist(0, 1UL<<31);

unsigned int random(){
	return dist(rd);
}
long long mult_mod(long long a, long long b, long long c) {
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while (b) {
        if (b & 1) {
            ret += tmp;
            if (ret >= c) {
                ret -= c;
            }
        }
        tmp <<= 1;
        if (tmp >= c) {
            tmp -= c;
        }
        b >>= 1;
    }
    return ret;
}

long long fastpow(long long a, long long n, long long mod) {
    long long ret = 1;
    long long tmp = a % mod;
    while (n) {
        if (n & 1) {
            ret = mult_mod(ret, tmp, mod);
        }
        n >>= 1;
        tmp = mult_mod(tmp, tmp, mod);
    }
    return ret;
}

bool check(long long a, long long n, long long x, long long t) {
    long long ret = fastpow(a, x, n);
    long long last = ret;
    for (int i = 1; i <= t; ++i) {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1) {
            return 1;
        }
        last = ret;
    }
    if (ret != 1) {
        return 1;
    }
    return 0;
}
bool Miller_Robin(long long n) {
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if ((n & 1) == 0) {
        return 0;
    }
    long long x = n - 1;
    long long t = 0;
    while ((x & 1) == 0) {
        ++t;
        x >>= 1;
    }
    for (int i = 0; i < 12; ++i) {
        long long a = random() % (n - 1) + 1;
        if (check(a, n, x, t)) {
            return 0;
        }
    }
    return 1;
}

long long gcd(long long a,long long b)  
{  
    if (a==0) return 1;  
    if (a<0) return gcd(-a,b);  
    while (b)  
    {  
        long long t=a%b; a=b; b=t;  
    }  
    return a;  
}  
long long Pollard_rho(long long x,long long c)  
{  
    long long i=1,x0=random()%x,y=x0,k=2;  
    while (1)  
    {  
        i++;  
        x0=(mult_mod(x0,x0,x)+c)%x;  
        long long d=gcd(y-x0,x);  
        if (d!=1 && d!=x)  
            return d;  
        if (y==x0) return x;  
        if (i==k)  
        {  
            y=x0;  
            k+=k;  
        }  
    }  
}  

void putbin(unsigned int x){
	for (int i = N - 1; i >= 0; i--)
		printf("%d", (x >> i)&1);
}

int main() {
	freopen("C.out", "w", stdout);
	printf("Case #1:\n");
	for (int i = 2; i <= 10; i++) {
		fastmul[i][0] = 1;
		for (int j = 1; j < 32; j++)
			fastmul[i][j] = fastmul[i][j - 1] * i;
	}

	std::uniform_int_distribution<unsigned int> dist_s(0, 1UL<<(N - 1));

	int cnt = 0;
	while (cnt != J) {
		unsigned int num = dist_s(rd);
		num |= 1UL << (N - 1); num |= 1;
		bool ok = true;
		for (int i = 2; i <= 10; i++) {
			long long x = excute(i, num);
			if (Miller_Robin(x)) {
				//fprintf(stderr, "%s %d %lld %d\n", "failed", num ,x, i);
				ok = false;
				break;
			}
		}
		if (ok) {
			putbin(num);
			for (int i = 2; i <= 10; i++){
				long long x = excute(i, num);
				long long outcome = 1;
				while (outcome == 1){
					long long p = x;  
		    		while (p >= x) p = Pollard_rho(p, random() % (x-1) +1);
		    		outcome = p;
		    	}
		    	printf(" %lld", outcome);
		    }
		    puts("");
		    cnt++;
		}
	}
}