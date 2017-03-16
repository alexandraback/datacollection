#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ST first
#define ND second
#define MP(a,b) make_pair(a,b)
#define FOR(i,m,n) for(long long i=(long long)(m);i<(long long)(n);++i)
#define REP(i,n) for(long long i=0;i<(long long)(n);++i)
#define DREP(i,n) for(int i=(long long)(n)-1;i>=0;--i)
#define SGN(x) (x<0?-1:(x>0?1:0))
#define ABS(x) (x<0?-x:x)

using namespace std;

int multable[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4}, 
	{0, 2,-1, 4,-3}, 
	{0, 3,-4,-1, 2}, 
	{0, 4, 3,-2,-1}, 
};
long long mul(long long a, long long b) {
	return SGN(a)*SGN(b)*multable[ ABS(a) ][ ABS(b) ];
}
long long mul(vector<long long> v) {
	long long res = 1;
	REP(i, v.size()) 
		res = mul(res, v[i]);
	return res;
}
long long pow(vector<long long> v, long long n) {
	if (n<=0) return 1;
	long long res = 1, x = mul(v);
	REP(i, n%4)
		res = mul(res, x);
	return res;
}

char print(int a) {
	if (a>0) printf("%c", (a==1?'1':char(a+'g'))); 
	else printf("-%c", (a==-1?'1':char(-a+'g'))); 
	return '\0';
}

long long find(vector<long long> v, long long p, long long beg = 0) {
	long long res = 1;
	REP (i, v.size()*5) {
		res = mul(res, v[(i+beg) % v.size()]);
		if (res == p) return i+beg;
	}
	return -10;
}

void test(int t) {//cout << endl;cout << endl;cout << endl;
	cout << "Case #" << t+1 << ": ";
	long long X, L; cin >> X >> L;
	vector<long long> v;
	char c = getchar(); 
	REP (i, X) {
		c = getchar();
		v.push_back((long long)(c-'g'));
	}
	//cout << endl;
	//cout << X << " " << L << endl;
	//REP (i, X) print(v[i]); cout << endl;
	
	long long x;	//cout << endl;
	x = find(v, 2)+1;
	//cout << x << ": " << x/X << " " << x%X << endl;
		if (x<0) {cout << "NO" << endl; return;} 		
	x = find(v, 3, x)+1;
	//cout << x << ": " << x/X << " " << x%X << endl;	
		if (x<0) {cout << "NO" << endl; return;} 

	x = find(v, 4, x)+1;
	//cout << x << ": " << x/X << " " << x%X << endl;	
		
	if (x<0 || x>X*L) {cout << "NO" << endl; return;} 	
	
	long long res; 
	if (x%X==0){
		res= pow(v, L - x/X);
		//print(res); cout<<endl;
	}
	else {
		res = pow(v, L - x/X -1);
		//print(res); cout<<endl;
	
		for (x%=X; x<X; ++x) 
			res = mul(res, v[x]);

		//print(res); cout<<endl;
	}	
	
	if (res == 1) cout << "YES" << endl;
	else cout << "NO"  << endl;

}


int main() {
	/*string s = "kkj";

	vector<int> v;
	REP (i, s.size()) v.push_back(int(s[i]-'g'));
	int res = pow(v, 1731);
	print(res) ;cout<< endl;
	/*vector<int> v = {3,2,3,2,3,2,3,2,3,2};
	
	int x = find(v, 2)+1;
	cout << x << ": " << x/v.size() << " " << x%v.size() << endl;
	if (x<0) {cout << "NO" << endl; return 0;} 
	
	x = find(v, 3, x)+1;
	cout << x << ": " << x/v.size() << " " << x%v.size() << endl;	
	if (x<0) {cout << "NO" << endl; return 0;} 
	
	x = find(v, 4, x)+1;
	cout << x << ": " << x/v.size() << " " << x%v.size() << endl;	
	if (x<0) {cout << "NO" << endl; return 0;} 
	*/
	
	
	
	int T; cin >> T;
	REP (i, T) 
		test(i);
	//*/
	/*
	cout << mul({3,2,3,2,3,2}) << endl;	
	cout << print(pow({3,2},3)) << endl;
	cout << endl;
	
	vector<int> v = {3,2};
	REP(i, 5) {
		cout << "===" << endl;
		int x = pow(v,i);	
		
		cout << print(x) << endl;
		if (x==2) {printf("n:%d m:%d\n", i, 0);return 0;} 
		REP(j, v.size()-1) {
			x = mul(x, v[j]);
			cout << print(x) << endl;
			if (x==2) {printf("n:%d m:%d\n", i, j+1);return 0;}
		}
	}
		
	cout << endl;//*/
	return 0;
}

















