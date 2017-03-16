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
	using Integer = __int128; //long long;
	
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
	constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
	constexpr long long my_pow_mod(long long x, long long k, long long M, long long z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
	constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

	inline int k_bit(long long x, int k){return (x>>k)&1;} //0-indexed

	mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());
}

template<class T> string join(const vector<T>& v, const string& sep){
	stringstream ss;
	for(int i=0; i<v.size(); i++){
		if(i>0) ss << sep;
		ss << v[i];
	}
	return ss.str();
}

constexpr long long mod = 9_ten + 7;

void solver(int test_number){
	long long k,c,s;
	cin >> k,c,s;

	vector<Integer> p(c+1,1);
	for(int i=1; i<p.size(); i++){
		p[i] = p[i-1] * k;
	}

	set<int> rem;
	for(int i=0; i<k; i++) rem.insert(i);

	vector<Integer> ans;
	while(rem.size()){
		vector<int> path = {*rem.begin()};
		while(path.back()<k-1 && path.size()<c){
			path.push_back(path.back()+1);
		}
		Integer at = 0;
		for(int i=0; i<path.size(); i++){
			assert( rem.count( path[i] ) );
			at += p[c-1-i] * path[i];
			rem.erase( path[i] );
		}
		ans.push_back(at+1);
	}


	printf("Case #%d: ", test_number);
	if(ans.size() <= s){
		println(join(ans, " "));

		for(int i=0; i<ans.size(); i++){
			assert(1<=ans[i]);
			assert(ans[i]<=my_pow(k,c));
		}
	}
	else println("IMPOSSIBLE");

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