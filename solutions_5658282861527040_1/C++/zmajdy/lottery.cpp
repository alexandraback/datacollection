#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int64;

int64 A,B,C;
int64 T;

int64 mem[100][2][2][2];

inline int64 dp (int p,int a,int b,int c) {
//	cout << p << " "<<a << " "<<b << " "<<c<<endl;
	if (p == -1) {
		if (c == 1 and a == 1 and b == 1) return 1;
		return 0;
	}
	if (mem[p][a][b][c] != -1) 
		return mem[p][a][b][c];
	
	int64 ret = 0;
	// 1 1
	if (((A & (1<<p)) or a) and ((B & (1<<p))or b) and ((C & (1<<p)) or c)) 
		ret += dp(p-1,a,b,c);
	// 1 0
	if ((A & (1<<p)) or a)
		ret += dp(p-1,a ,(B&(1<<p)) ? 1 : b, (C&(1<<p)) ? 1 : c);
	// 0 1
	if ((B & (1<<p)) or b)
		ret += dp(p-1,(A&(1<<p)) ? 1 : a, b, (C&(1<<p)) ? 1 : c);
	//0 0 
	// cout << A << " "<<(1<<p)<<" , "<<(A&(1<<p))<<endl;
	ret += dp(p-1,((A&(1<<p)) ? 1 : a), ((B&(1<<p)) ? 1 : b), ((C&(1<<p)) ? 1 : c));
	
	//cout <<p << " "<<a << " "<<b << " "<<c << " : "<<ret <<endl;
	return mem[p][a][b][c] = ret;
}

int main () {
	cin >> T;
	for (int tc=1; tc<=T; tc++) {
		cin >> A >> B >> C;
		memset(mem,-1,sizeof(mem));
		printf ("Case #%d: %llu\n",tc,dp(30,0,0,0));
	}
}