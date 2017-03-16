#include <stdio.h>
#include <string.h>
#include <math.h>

long long int gcd(long long int a ,long long int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
long long int power(long long int b)
{
    long long int num = 1;
    while (b--) {
        num *= 10;
    }
    return num;
}
int main()
{
    long long int t;
    scanf("%lld", &t);
    int case1 = 0;
    while (t--) {
        ++case1;
        long long int i;
        char str[50];
        scanf("%s", str);
        //printf("%s", str);
        long long int len = strlen(str);
        for (i = 0; i < len; ++i) {
            if (str[i] == '/') {
                break;
            }
        }
        long long int len1 = i;
        long long int len2 = len - (len1 + 1);
        //printf("%lld %lld\n", len1, len2);
        long long int j = 0;

       // printf("%lld\n", power(0));

        long long int num1 = 0;
        for (i = len1 - 1; i >= 0; --i) {
            //printf("%d %lld\n", str[i] - 48, power(j));
            num1 += (str[i] - 48) * power(j);
            ++j;
        }

        j = 0;

       long long int num2 = 0;
        for (i = len - 1; i > len1; --i) {
            num2 += (str[i] - 48) * power(j);
            ++j;
        }
        //printf("%lld\n%lld\n", num1, num2);
		long long int g = gcd(num1, num2);
		num1 /= g;
		num2 /= g;
        double logx;
        logx = log(num2) / log(2);
       // printf("\n%f\n%f\n", logx, ceil(logx));
        int cnt = 0;
        if (ceil(logx) == logx) {
            double logx1;
            logx1 = (double)num1 / (double)num2;
            //printf("%f\n", logx1);
            while (logx1 < 1) {
                logx1 *= 2.0;
                ++cnt;
            }
            if (cnt <= 40) {
                printf("Case #%d: %d\n", case1, cnt);
            } else {
                printf("Case #%d: impossible\n", case1);
            }
        } else {
            printf("Case #%d: impossible\n", case1);
        }
    }
    return 0;
}
