#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <assert.h>
#include<string>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : a > b ? gcd(b, a%b) : gcd(a, b%a);
}
long long p(long long n) {
    if(n < 2) return 0;
    int c = 0;
    while(n > 1) n /= 2, c++;
    return c;
}
long long foo(long long n, long long m) {
       if(n > m) return -1;
       if(m == 1) return 0;
       long long res = 0;
       long long r = gcd(n, m);
       n = n / r;
       m = m / r;
       if((m & (m - 1)) != 0) {
           return -1;
       }
       res = p(m);
       if(res > 40) {
            return -1;
       }
       if(n > m/2) return 1;
       return foo(n, m/2) + 1;
}
int main()
{
    int t;
    char s;
    long long n, m;
	FILE *fp = fopen("in.txt", "r"), *ofp=fopen("out.txt", "w");
    fscanf(fp, "%d", &t);
    for(int k = 1;k <= t; k++) {
       fscanf(fp, "%lld%c%lld", &n, &s, &m);
       long long res = foo(n, m);
       if(res == -1)
            fprintf(ofp, "Case #%d: impossible\n", k);
        else fprintf(ofp, "Case #%d: %lld\n", k, res);
       
    }           
    fclose(fp);
    fclose(ofp); 
    system("pause");
    return 0;
}
