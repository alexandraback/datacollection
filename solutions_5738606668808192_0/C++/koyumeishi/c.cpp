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
	using Integer = __int128;

	string to_s(Integer x){
		if(x == 0) return "0";
		string ret;
		while(x!=0){
			ret += x%10 + '0';
			x /= 10;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

	ostream& operator << (ostream& os, const Integer& x){ return os << to_s(x); }


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

	inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

	mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());
}

constexpr long long mod = 9_ten + 7;


template<class T> string join(const vector<T>& v, const string& sep){
	stringstream ss;
	for(int i=0; i<v.size(); i++){
		if(i>0) ss << sep;
		ss << v[i];
	}
	return ss.str();
}

int divisor(Integer x){
	if(x%2 == 0 && x!=2) return 2;
	for(int k=3; k<=100 && k<x; k+=2){
		if(x%k == 0 && x!=k) return k;
	}
	return -1;
}

Integer get_value(string x, int base){
	Integer tmp = 0;
	Integer k = 1;
	for(int i=x.size()-1; i>=0; i--){
		if(x[i] == '1'){
			tmp += k;
		}
		k *= base;
	}
	return tmp;
}

int bit_count(Integer x){
	int ret = 0;
	while(x){
		ret++;
		x -= x&-x;
	}
	return ret;
}

void solver(int test_number){
	int n,j;
	cin >> n,j;

	string s(n,'0');
	s[0] = '1';
	s.back() = '1';

	printf("Case #%d:\n", test_number);

	set<string> used;
	int calc_count = 0;
	while(used.size() < j){
		calc_count++;

		Integer x = (uniform_int_distribution<long long>(0,(1<<(n-2))-1)(mt)<<1) | 1 | (1LL<<(n-1));
		int bits = bit_count(x);

		if(bits%3 != 0) continue;
		if(bits%2 != 0) continue;

		string t(n,'0');
		for(int i=0; i<n; i++){
			t[n-1-i] = '0' + k_bit(x,i);
		}
		if(used.count(t)) continue;

		bool ok = true;
		vector<int> d;
		for(int base=2; base<=8; base++){
			Integer val = get_value(t, base);
			int tmp = divisor(val);

			if(tmp == -1){
				ok = false;
				break;
			}else{
				d.push_back(tmp);
			}
		}

		if(ok){
			d.push_back(2);
			d.push_back(3);
			used.insert(t);
			println(t,join(d," "));

			bool check = ok;
			for(int i=2; i<=10; i++){
				assert( get_value(t, i) % d[i-2] == 0 );
				assert( get_value(t, i) !=  d[i-2] );
				assert( d[i-2] != 1 );
			}
		}
	}
}

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		solver(i+1);
	}
	return 0;
}