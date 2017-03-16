#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char bits[1000001];

int todec(int a, char *aa) {
	char buf[10];
	sprintf(buf, "%d", a);
	for (int i=0; i<strlen(buf); i++) {
		aa[i] = buf[i]-'0';
	}
	return strlen(buf);
}

bool lessThan(char *aa, int sha, char *bb, int shb, int n) {
	for (int i=0; i<n; i++) {
		int a = aa[(i+sha)%n];
		int b = bb[(i+shb)%n];
		if (a>b) return false;
		if (b>a) return true;
	}
	return false;
}

string str(char *aa, int n, int sh) {
	string s(n,' ');
	for (int i=sh; i<n+sh; i++) {
		s[i]= (char)(aa[i%n]+'0');
	}
	return s;
}

void inc(char *aa, int n) {
	char *p = aa+n-1;
	while ((*p+1)>9) {
		*p=0;
		p--;
	}
	(*p)++;
}

int value(char *aa, int n, int sh) {
	int x=0;
	for (int i=sh; i<n+sh; i++) {
		x = x*10 + aa[i%n];
	}
	return x;
}

int eq(char *aa, int sha, char *bb, int n) {
	for (int i=0; i<n; i++) {
		if (aa[(i+sha)%n]!=bb[i]) return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int A,B;
		cin >> A >> B;
//		cout<<"("<<A<<","<<B<<")"<<endl;

		memset(bits,0,sizeof(bits));

		char arra[10],arrb[10];
		int n = todec(A,arra);
		todec(B,arrb);
		int total=0;
		//cout<<"B="<<str(arrb,n,0)<<endl;
		while (lessThan(arra,0,arrb,0,n)) {
			//cout<<"a="<<str(arra,n,0)<<endl;
			vector<int> found;
			for (int sh=1; sh<n; sh++) {
				if (arra[sh]!=0 && lessThan(arra,0,arra,sh,n) && 
						(eq(arra,sh,arrb,n) || lessThan(arra,sh,arrb,0,n))) {
					int val = value(arra,n,sh);
					if (find(found.begin(),found.end(),val)==found.end()) {
						total++;
						found.push_back(val);
					} else {
						//cout<<"repeated "<<val<<endl;
					}
					//cout<<"orig="<<value(arra,n,0)<<" perm="<<val<<" works"<<endl;
				}
			}
			inc(arra,n);
		}

//		cout<<"a="<<str(arra,n,0)<<" b="<<str(arrb,n,0)<<" lt="<<lessThan(arra,arrb,n,0)<<endl;

		//if (t==2)break;
		cout << "Case #" << t << ": " << total << endl;
	}


}