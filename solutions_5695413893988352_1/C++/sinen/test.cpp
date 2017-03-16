//samain
#include <bits/stdc++.h>

using namespace std;
char a[2005],b[2005];
long long t,tt1,ansa1,ansb1,ans;
void cari(int xnow, long long a1, long long b1) {
//	cout << xnow <<" "<< a1<<" "<<b1<<endl;
	if (xnow == tt1) {
		if (abs(a1 - b1) < ans) {
			ans = abs(a1 - b1);
			ansa1 = a1;
			ansb1 = b1;
		}
		return;
	}
	if (a[xnow] == '?' && b[xnow] == '?') {
		if (a1 < b1) {
			cari(xnow + 1, a1*10 + 9, b1*10);	
		}else if (a1 == b1) {
			cari(xnow + 1, a1*10, b1*10);
			cari(xnow + 1, a1*10 + 1, b1*10);
			cari(xnow + 1, a1*10, b1*10 + 1);	
		}else {
			cari(xnow + 1, a1*10, b1*10 + 9);	
		}
	}else if (a[xnow] == '?') {
		int tmp = (b[xnow] - '0');
		if (a1 < b1) {
			cari(xnow + 1, a1*10 + 9, b1*10 + tmp);	
		}else if (a1 == b1) {
			cari(xnow + 1, a1*10 + max(0,tmp - 1), b1*10 + tmp);
			cari(xnow + 1, a1*10 + tmp, b1*10 + tmp);
			cari(xnow + 1, a1*10 + min(9, tmp + 1), b1*10 + tmp);	
		}else {
			cari(xnow + 1, a1*10 + 0, b1*10 + tmp);
		}
	}else if (b[xnow] == '?') {
		int tmp = (a[xnow] - '0');
		if (a1 > b1) {
			cari(xnow + 1, a1*10 + tmp, b1*10 + 9);	
		}else if (a1 < b1) {
			cari(xnow + 1, a1*10 + tmp, b1*10 + 0);	
		}else {
			cari(xnow + 1, a1*10 + tmp, b1*10 + max(0,tmp - 1));
			cari(xnow + 1, a1*10 + tmp, b1*10 + tmp);
			cari(xnow + 1, a1*10 + tmp, b1*10 + min(9, tmp + 1));
		}
	}else {
		int tmp = (a[xnow] - '0');
		int tmp2 = (b[xnow] - '0');
		cari(xnow + 1, a1*10 + tmp, b1*10 + tmp2);
	}
}

int main() {
	scanf("%lld", &t);
	for (int q = 1; q <= t; q++) {
		scanf("%s %s", a, b);
		tt1 = strlen(a);
		//cari terbesar b dari a
		//cari terkecil b dari a
		//kalo ada ?? bisa 00 10 01
		ans = 1000000000000000000;
		ansa1 = 0;
		ansb1 = 0;
		cari(0, 0, 0);
		printf("Case #%d: ", q);
		int tmp = ansa1;
		int cnt = 0, cnt2 = 0;
		while (tmp > 0) {
			tmp /= 10;
			cnt++;
		}
		if (tmp == 0) cnt = 1;
		int tmp2 = ansb1;
		if (tmp2 == 0) cnt2 = 1;
		while (tmp2 > 0) {
			tmp2 /= 10;
			cnt2++;
		}
		while (cnt > tt1) {
			printf("0");
			cnt++;
		}
		printf("%lld ",ansa1);
		while (cnt2 > tt1) {
			cnt2++;
			printf("0");
		}
		printf("%lld\n",ansb1);
	}
}