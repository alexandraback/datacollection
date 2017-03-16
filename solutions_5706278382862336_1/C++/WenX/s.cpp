#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long gcd(long long a, long long b){
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main(){
	int cc, tt;
	scanf("%d", &tt);
	for (int cc = 1; cc <= tt; cc++){
		char buf[1024];
		long long a, b;
		scanf("%s", buf);

		for (int i = 0; i < strlen(buf); i++){
			if (buf[i] == '/')
				buf[i] = ' ';
		}
		sscanf(buf, "%lld%lld", &a,&b);

		long long gcds = gcd(a, b);
		b /= gcds;
		a /= gcds;
		int r = 0;
		long long r2 = 1;
		for (r = 0; r <= 40;){
			if (r2 == b)
				break;
			r2 *= 2;
			r++;
		}
		int ans = 1;
		while (a*2<r2){
			ans++;
			a *= 2;
		}

		if (r > 40){
			cout << "Case #" << cc << ": impossible" << endl;
		}
		else{
			cout << "Case #" << cc << ": " << ans << endl;
		}
	}
}