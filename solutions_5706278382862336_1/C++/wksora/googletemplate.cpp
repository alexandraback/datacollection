/*
*  Google Code Jam
*
*  Created on: 2014Äê4ÔÂ12ÈÕ
*      Author: Bevoid
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX(a,b)(a>b?a:b)

using namespace std;

int aa[1011];
long long a, b;
long long ans;

long long gcd(long long a,long long b)
{
    return (b>0)?gcd(b,a%b):a;
}

int main() {
	freopen("D:/Downloads/A-small-attempt1.in", "r", stdin);
	freopen("d:/out3.txt", "w", stdout);
	int T;
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		while (cases++ < T) {
			scanf("%lld/%lld", &a, &b);
			int count = 0;

			long long aa = gcd(a , b);
			a = a / aa;
			b = b / aa;

			long long tmp = b;
			while (tmp > a && tmp % 2 == 0) {
				tmp /= 2;
				count ++;
			}

			while (tmp > 1 && tmp % 2 == 0) {
				tmp /= 2;
			}

			if (tmp == 1) {
				printf("Case #%d: %d\n", cases, count);
			} else {
				printf("Case #%d: impossible\n", cases);
			}
			
			
		}
		//system("pause");
	}
	return 0;

}
