#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
using namespace std;

namespace {
	template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
	template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
	template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(int i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
	template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}
	template<class T> ostream& operator >> (ostream& os, const T& val){ return os << " " << val;}

	template<class H> void print(const H& head){ cout << head; }
	template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
	template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

	template<class H> void eprint(const H& head){ cerr << head; }
	template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; print(tail...); }
	template<class ... T> void eprintln(const T& ... values){ print(values...); cerr << endl; }

	string operator "" _s (const char* str, size_t size){ return move(string(str)); }
	constexpr long long my_pow(long long x, long long k, long long z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
	constexpr long long my_pow_mod(long long x, long long k, long long M, long long z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
	constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

	inline int k_bit(long long x, int k){return (x>>k)&1;} //0-indexed

	mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());
}

constexpr long long mod = 9_ten + 7;

using integer = long long;

char buff[1000];

void test(){
	long long mx = 0;
	for(int k=1; k<=6_ten; k++){
		integer x = k;
		int n = k;
		set<int> s;
		while(s.size() < 10){
			sprintf(buff,"%lld", x);
			for(char c: string(buff)) s.insert(c-'0');
			x += n;
		}
		mx = max(mx, x-n);

		if(k%10000 == 0){
			eprintln(k,mx);
		}
	}
	cerr << mx << endl;
}

void solver(int test_number){
	int n;
	cin >> n;

	if(n == 0){
		printf("Case #%d: INSOMNIA\n", test_number);
		return;
	}

	integer x = n;
	set<int> s;
	while(s.size() < 10){
		sprintf(buff,"%lld", x);
		for(char c: string(buff)) s.insert(c-'0');
		x += n;
	}


	printf("Case #%d: %lld\n", test_number, x-n);
}

int main(){
	//test();
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		solver(i+1);
	}
	
	return 0;
}
