#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

unsigned long long dfs(int bit, const int& K, const int& A, int Amask, bool Aall, const int& B, int Bmask, bool Ball, int lowestbit) {
	if(bit == -1) return Aall && Ball;
	if(bit == lowestbit) {
		unsigned long long Acount = 0, Bcount = 0;
		if(Aall) {
			Acount = 1 << (lowestbit+1);
		} else {
			Acount = (A ^ Amask);
		}
		if(Ball) {
			Bcount = 1 << (lowestbit+1);
		} else {
			Bcount = (B ^ Bmask);
		}
		return Acount * Bcount;
	}
	unsigned long long result = 0;
	if(((K>>bit)&1) == 1) {
		if(Aall && Ball) {
			result = dfs(bit-1,K,A,Amask + (1<<bit),true,B,Bmask+(1<<bit),true,lowestbit);
		} else if(Aall) {
			if(((B>>bit)&1)==0) {
				result = 0;
			} else {
				result = dfs(bit-1,K,A,Amask + (1<<bit),true,B,Bmask+(1<<bit),false,lowestbit);
			}
		} else if(Ball) {
			if(((A>>bit)&1)==0) {
				result = 0;
			} else {
				result = dfs(bit-1,K,A,Amask + (1<<bit),false,B,Bmask+(1<<bit),true,lowestbit);
			}
		} else {
			if(((B>>bit)&1)==0 || ((A>>bit)&1)==0) {
				result = 0;
			} else {
				result = dfs(bit-1,K,A,Amask + (1<<bit),false,B,Bmask+(1<<bit),false,lowestbit);
			}
		}
	} else {
		if(Aall && Ball) {
			result = dfs(bit-1,K,A,Amask + (1<<bit),true,B,Bmask,true,lowestbit);
			result += dfs(bit-1,K,A,Amask,true,B,Bmask + (1<<bit),true,lowestbit);
			result += dfs(bit-1,K,A,Amask,true,B,Bmask,true,lowestbit);
		} else if(Aall) {
			if(((B>>bit)&1)==0) {
				result = dfs(bit-1,K,A,Amask + (1<<bit),true,B,Bmask,false,lowestbit);
				result += dfs(bit-1,K,A,Amask,true,B,Bmask,false,lowestbit);
			} else {
				result = dfs(bit-1,K,A,Amask + (1<<bit),true,B,Bmask,true,lowestbit);
				result += dfs(bit-1,K,A,Amask,true,B,Bmask+(1<<bit),false,lowestbit);
				result += dfs(bit-1,K,A,Amask,true,B,Bmask,true,lowestbit);
			}
		} else if(Ball) {
			if(((A>>bit)&1)==0) {
				result = dfs(bit-1,K,A,Amask,false,B,Bmask+(1<<bit),true,lowestbit);
				result += dfs(bit-1,K,A,Amask,false,B,Bmask,true,lowestbit);
			} else {
				result = dfs(bit-1,K,A,Amask,true,B,Bmask + (1<<bit),true,lowestbit);
				result += dfs(bit-1,K,A,Amask+(1<<bit),false,B,Bmask,true,lowestbit);
				result += dfs(bit-1,K,A,Amask,true,B,Bmask,true,lowestbit);
			}
		} else {
			if(((A>>bit)&1)==0 && ((B>>bit)&1)==0) {
				result = dfs(bit-1,K,A,Amask,false,B,Bmask,false,lowestbit);
			} else if(((A>>bit)&1)==0) {
				result = dfs(bit-1,K,A,Amask,false,B,Bmask,true,lowestbit);
				result += dfs(bit-1,K,A,Amask,false,B,Bmask+(1<<bit),false,lowestbit);
			} else if(((B>>bit)&1)==0) {
				result = dfs(bit-1,K,A,Amask,true,B,Bmask,false,lowestbit);
				result += dfs(bit-1,K,A,Amask+(1<<bit),false,B,Bmask,false,lowestbit);
			} else {
				result = dfs(bit-1,K,A,Amask,true,B,Bmask,true,lowestbit);
				result += dfs(bit-1,K,A,Amask,true,B,Bmask+(1<<bit),false,lowestbit);
				result += dfs(bit-1,K,A,Amask+(1<<bit),false,B,Bmask,true,lowestbit);
			}
		}
	}
	return result;
}

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int A,B,K;
		cin >> A >> B >> K;
		unsigned long long sum = 0;
		for(int i=0;i<31;i++) {
			if(((K>>i)&1) == 0) continue;
			K -= (1<<i);
			sum += dfs(31,K,A,0,false,B,0,false,i-1);
		}
		cout << "Case #" << c << ": " << sum << endl;
	}
}