#include <bits/stdc++.h>
using namespace std;

char s1[22], s2[22];
int n, ans, m1, m2;

void go(int pos) {
	if(pos==n) {
		int v1=0, v2=0;
		for(int i=n-1, p=1; i>=0; i--, p*=10) {
			v1+=(s1[i]-'0')*p;
			v2+=(s2[i]-'0')*p;
		}
		if(abs(v1-v2)<ans) ans=abs(v1-v2), m1=v1, m2=v2;
		else if(abs(v1-v2)==ans) {
			if(v1<m1) m1=v1, m2=v2;
			else if(v1==m1 && v2<m2) m2=v2; 
		}
		return;
	}
	if(s1[pos]=='?') {
		for(int i=0; i<10; i++) {
			if(s2[pos]=='?') {
				for(int j=0; j<10; j++) {
					s1[pos]='0'+i;
					s2[pos]='0'+j;
					go(pos+1);
					s1[pos]='?';
					s2[pos]='?';
				}
			}
			else {
				s1[pos]='0'+i;
				go(pos+1);
				s1[pos]='?';
			}
		}
	}
	else if(s2[pos]=='?') {
		for(int i=0; i<10; i++) {
			s2[pos]='0'+i;
			go(pos+1);
			s2[pos]='?';
		}
	}
	else go(pos+1);
}

int main() {
	int t, T=1;
	scanf("%d", &t);
	while(t--) {
		scanf("%s %s", s1, s2);
		ans=m1=m2=1e9;
		n=strlen(s1);
		go(0);
		printf("Case #%d: ", T++);
		int d1=0, aux1=m1;
		if(!aux1) d1=1;
		while(aux1) {
			aux1/=10;
			d1++;
		}
		int d2=0, aux2=m2;
		if(!aux2) d2=1;
		while(aux2) {
			aux2/=10;
			d2++;
		}
		for(int i=0; i<n-d1; i++) printf("0");
		printf("%d ", m1);
		for(int i=0; i<n-d2; i++) printf("0");
		printf("%d\n", m2);
	}
	return 0;
}
