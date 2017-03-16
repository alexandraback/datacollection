#include <iostream>
#include <fstream>
using namespace std;

long long n, ans;
int len;

long long p(int k) {
	int ans = 1;
	for (int i=0; i<k; i++)
		ans *= 10;
	return ans;
}

void work(int k) {
	int now1, now2;
	if (k==1) {
		ans += n;
	//	cout << "a" << ans << "n" << n;
		return;
	}
	if (n % 10 == 0) {
		n-=1;
		ans++;
		len = 0;
		long long tempp = n;
		while (1) {
			len++;
			tempp/=10;
			if (!tempp) break;
		}
	//	cout << ans << " ";
		if (len!=k) {
			work(k-1);
			return;
		}
	}
	long long temp = n, temp2;
	for (int i=0; i<k/2; i++) {
		now1 = temp % 10;
		if (!i) {
			n -= (now1-1);
			ans += (now1-1);
		} else {
			n -= (now1*p(i));
			ans += (now1*p(i));
		}
		temp /= 10;
	}
//	cout << ans << " ";
	temp = p(k-1);
	temp2 = 0;
	for (int i=0; i<k/2; i++) {
		temp += ((n/p(k-i-1))%10)*p(i);
		temp2 += ((n/p(k-i-1))%10)*p(i);
	}
	//cout << k << "a" << endl;
	if (k%2) {
		temp += ((n/p(k-k/2-1))%10)*p(k-k/2-1);
		temp2 += ((n/p(k-k/2-1))%10)*p(k-k/2-1);
	}
//	cout << temp << " ";
	if (temp != n) ans += 1;
	ans += (temp2+1);
//	cout << ans << " "; 
	n = p(k-1)-1;
//	cout << n << "n" << k << "k";
	work(k-1);
	 
}

int main() {
	ifstream fin("A-small-attempt1.in");
	ofstream fout("output.txt");
	int t;
	fin >> t;
	for (int k=0; k<t; k++) {
		fin >> n;
		ans = 0;
		len = 0;
		long long temp = n;
		while (1) {
			len++;
			temp/=10;
			if (!temp) break;
		}
	//	cout << "len" << len << endl;
		work(len);
		fout << "Case #" << k+1 << ": " << ans << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
