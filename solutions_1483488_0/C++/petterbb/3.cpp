#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool flag[10000];

int numberOfDigits(int n){
	if(n == 0)
		return 1;

	int cnt = 0;
	while(n){
		n /= 10;
		cnt++;
	}
	return cnt;
}

int ipow(int a, int b){
	int ans = 1;
	while(b--){
		ans *= a;
	}
	return ans;
}


int main()
{
	//freopen("3.out", "w", stdout);
	int t;
	cin >> t;
	for(int cases = 1; cases <= t; cases++){
		int A, B;
		cin >> A >> B;

		int len = numberOfDigits(A);
		int power = ipow(10, len-1);
		int ans = 0;
		memset(flag, false, sizeof(flag));

		for(int n = A; n <= B; n++){
			flag[n] = true;
			int tmp =  (n % 10) * power + n / 10;

			int cnt = 1;
			while(!flag[tmp]){
				flag[tmp] = true;
				if(tmp >=A && tmp <= B)
					cnt++;
                tmp = (tmp % 10) * power + tmp / 10;
			    while(tmp < A || tmp > B)
                    tmp = (tmp % 10) * power + tmp / 10;
            }
			ans += cnt*(cnt-1)/2;
		}
		cout << "Case #" << cases << ": " << ans << endl;
	}
	return 0;
}
