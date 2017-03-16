#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

#define LLU long long unsigned int
#define MAX 1000001

int T, N;
string s;


int aukat[MAX];
int val[MAX];

void init() {
	for(int i=0;i<=s.length();i++) {
		aukat[i] = 0;
		val[i] = 0;
	}
}

bool isVov(char c) {
	switch(c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
		break;
	};
	return false;
}

LLU solve() {
	for(int i=1;i<=s.length();i++)
		aukat[i] = isVov(s[i-1])? 0 : aukat[i-1]+1;
	for(int i=1;i<=s.length();i++)
		val[i] = (aukat[i] < N)? val[i-1] : (i-N+1);
	LLU net = 0;
	for(int i=1;i<=s.length();i++)
		net += (LLU) (val[i]);
	return net;
}

int main() {
	freopen("a.in", "r", stdin);
    freopen("op.out", "w", stdout);
	scanf("%d", &T);
	int count=1;
	while(T--) {
		cin>>s>>N;
		init();
		printf("Case #%d: %llu\n", count++, solve());
	}
	return 0;
}