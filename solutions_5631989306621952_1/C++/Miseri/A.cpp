#include <bits/stdc++.h>

using namespace std;
// Constants and macros
#define INF 		(int)1e9
#define EPS 		1e-9
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define forall(i,a,b) 	for(int i=a;i<b;i++)
#define pb 		push_back
#define mp		make_pair
#define MAX(a,b)	( (a)>(b) ? (a):(b))
#define MIN(a,b)	( (a)<(b) ? (a):(b))
#define s(a)		scanf("%d", &a)
#define ss(a,b)		scanf("%d %d", &a,&b)
#define sss(a,b,c)	scanf("%d %d %d", &a,&b,&c)
#define sl(a)		scanf("%I64d", &a)

int T;

void best(string s){
	char b[6555]= {0};
	int len = s.length();
	int beg = 2222, end = 2223;
	b[beg] = s[0];
	forall(i,1,len){
		if (s[i] >= b[beg]) b[--beg] = s[i];
		else b[end++] = s[i];
	}
	forall(i,beg,end){
		//if (b[i]!=0)
		cout << b[i];
	}
}

int main(){
	s(T);
	forall(i,0,T){
		string s;
		cin >> s;
		printf("Case #%d: ", i+1);
		best(s);
		cout << endl;
	}
}
