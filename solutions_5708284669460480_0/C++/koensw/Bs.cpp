#include <iostream>
#include <iomanip>
#include <cstdlib>

int K, L, S;
char chr[10];
std::string w;
double all = 0;
long long cnt = 0;
long long max = 0;

char wrd[10];
void gen(int k){
	if(k == S){
		wrd[S] = 0;
		long long t = 0;
		//std::cout << wrd << std::endl;
		for(int i=0; i<=S-L; ++i){
			int j = 0;
			for(; j<L; ++j){
				if(wrd[i+j] != w[j]) break;
			}
			//std::cout << j << std::endl;
			if(j == L) ++t;
		}
		all += t;
		max = std::max(max, t);
		++cnt;
		return;
	}

	for(int i=0; i<K; ++i){
		wrd[k] = chr[i];
		gen(k+1);
	}
}

void solve(int n){
	all = 0;
	cnt = 0;
	max = 0;

	std::cin >> K >> L >> S;
	std::string s;
	std::cin >> s;
	std::cin >> w;
	for(int i=0; i<K; ++i){
		chr[i] = s[i];
	}
	
	//std::cout << s << " " << w << std::endl;
	
	gen(0);
	
	//std::cout << all << " " << cnt << " " << max << std::endl;
	
	double exp = all/cnt;
	std::cout << std::fixed << std::setprecision(7) << "Case #" << n << ": " << max-exp << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int i=0; i<T; ++i) solve(i+1);
}