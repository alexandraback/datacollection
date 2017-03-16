#include<bits/stdc++.h>
using namespace std;
int num_rev(int number) {
	int reverse = 0;
	for( ; number!= 0 ; ) {
      reverse = reverse * 10;
      reverse = reverse + number % 10;
      number = number / 10;
   }
   //cout << number << " " << reverse << endl;
   return reverse;
}

int A[1000016];
void pre() {
	A[1] = 1;
	for(int i = 1; i <= 1000006; i++) {
		int x = num_rev(i);
		A[i + 1] = min(A[i + 1], A[i] + 1);
		if(x > 1000000) continue;
		A[x] = min(A[x], A[i] + 1);
	}
}

int main() {
	int n, t;
	for(int i = 1; i <= 1000006; i++) A[i] = 10000060;
	pre();
	cin >> t;
	for(int kase = 1; kase <= t; kase++) {
		cin >> n;
		cout << "Case #" << kase << ": " << A[n] << endl;
	}

}