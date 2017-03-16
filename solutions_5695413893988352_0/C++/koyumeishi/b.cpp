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
	using Integer = long long; //__int128;
	template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
	template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
	template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(int i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
	template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

	template<class H> void print(const H& head){ cout << head; }
	template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
	template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

	template<class H> void eprint(const H& head){ cerr << head; }
	template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; eprint(tail...); }
	template<class ... T> void eprintln(const T& ... values){ eprint(values...); cerr << endl; }

	string operator "" _s (const char* str, size_t size){ return move(string(str)); }
	constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
	constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
	constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

	inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

	mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

	template<class T> string join(const vector<T>& v, const string& sep){
		stringstream ss; for(int i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str();
	}
}

constexpr long long mod = 9_ten + 7;

long long s_to_i(string& s){
	stringstream ss;
	ss << s;
	long long ret;
	ss >> ret;
	return ret;
}

void solve(){
	string C,J;
	cin >> C,J;
	int n = C.size();

	long long d = 1LL<<58;

	string c = C, j = J;
	string a = C, b = J;
	function<void(int)> dfs = [&](int depth){
		if(depth==2*n){
			long long X = s_to_i(a);
			long long Y = s_to_i(b);

			long long val = abs(X-Y);
			if( val < d ){
				d = val;
				c = a; j = b;
			}else if(val==d){
				if(a<c){
					c = a; j = b;
				}else if(a==c && b<j){
					c = a; j = b;
				}
			}
			return;
		}
		if(depth<n){
			if(C[depth] == '?'){
				for(int i=0; i<10; i++){
					a[depth] = i + '0';
					dfs(depth+1);
				}
			}else{
				dfs(depth+1);
			}
		}else{
			if(J[depth-n] == '?'){
				for(int i=0; i<10; i++){
					b[depth-n] = i + '0';
					dfs(depth+1);
				}
			}else{
				dfs(depth+1);
			}
		}
	};

	dfs(0);
	print(c,j);
}

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		print("Case #");
		print(i+1);
		print(": ");
		solve();
		puts("");
	}
	return 0;
}
