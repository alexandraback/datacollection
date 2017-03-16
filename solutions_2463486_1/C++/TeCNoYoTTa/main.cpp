#include <iostream>
using namespace std;

int T;
long long acc[10000050];

bool isPal(long long num) {
	string str = "";
	while(num) {
		str += (num%10)+'0';
		num /= 10;
	}
	for(int i=0;i<str.size()/2;i++) {
		if(str[i] != str[str.size()-1-i])
			return false;
	}
	return true;
}
 

int main() {
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	acc[0] = 0;
	for(long long x=1;x<10000050;x++) {
		acc[x] = acc[x-1];
		if (isPal(x) && isPal(x*x)) {
			++acc[x];
		}
	}
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		long long A,B,a,b;
		cin >> A >> B;
		printf("Case #%d: ",c);
		a = ceil(sqrtl(A));
		b = sqrtl(B);
		cout << (acc[b] - acc[a-1]) << endl;
	}
	return 0;
}