#include <iostream>
#include <cstdio>

using namespace std;

bool isParindrome(long long t){
	int a[100];
	int size = 0;
	while(t) { a[size++] = t%10; t/=10; }
	for(int i=0;i<size-i-1;i++)
		if(a[i]!=a[size-i-1]) return false;
	return true;
}

int main(){
	int T; cin >> T;
	long long A, B;
	for(int test=1;test<=T;test++){
		cin >> A >> B;
		printf("Case #%d: ", test);
		long long res = 0;
		for(long long i=1;i*i<=B;i++){
			if(i*i < A) continue;
			if(isParindrome(i) && isParindrome(i*i)) res++;
		}
		cout << res << endl;
	}
}