#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
bool isMatch(char* s, char* d) {
	char* sp = s;
	char* dp = d;
	while (*sp){
		if (*dp != '?'){
			if (*dp != *sp){
				return false;
			}
		}
		sp++;
		dp++;
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	for (int y = 1; y <= t; y++){
		int ans = 4000;
		cout << "Case #" << y << ": ";
		char A[256];
		char B[256];
		cin >> A >> B;
		char a[4];
		char b[4];
		char rrr[4];
		char sss[4];
		char fmt[64];
		sprintf(fmt, "%%%dd", strlen(A));
		for (int i = 0; i <= 999; i++){
			sprintf(a, fmt, i);
			char* cp = a;
			while (*cp){
				if (*cp == ' '){
					*cp = '0';
				}
				cp++;
			}
			if (isMatch(a, A) == false){
				continue;
			}
			for (int j = 0; j <= 999; j++){
				sprintf(b, fmt, j);
				char* cp = b;
				while (*cp){
					if (*cp == ' '){
						*cp = '0';
					}
					cp++;
				}
				if (isMatch(b, B) == false){
					continue;
				}
				int t=abs(atoi(a) - atoi(b));
				if (t < ans){
					ans = t;
					strcpy(rrr, a);
					strcpy(sss, b);
				}
			}
		}
		cout << rrr << ' ' << sss;
		cout << endl;
	}
}