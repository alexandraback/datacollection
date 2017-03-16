#include <iostream>

#define MOD 1000000007

long long factmod(long long num, long long mod){
	long long fact = 1;
	for(long long i=1; i<=num; ++i){
		fact*=i;
		fact%=mod;
	}
	return fact;
}

/*long long expmod(long long base, long long exp, long long mod ){
  if (exp == 0) return 1;
  if (exp % 2 == 0){
    return std::pow(expmod( base, (exp / 2), mod), 2) % mod;
  }
  else {
    return (base * expmod( base, (exp - 1), mod)) % mod;
  }
}*/

std::string sl[150];
long long used[30];
long long bet_cnt[30];
long long same_cnt[30];
long long lft_dep[30];
long long rgt_dep[30];
long long from_to[30];

long long T, N;
int main(){
	std::cin >> T;
	for(long long p=0; p<T; ++p){
		for(long long i=0; i<30; ++i){
			bet_cnt[i] = 0;
			same_cnt[i] = 0;
			lft_dep[i] = 0;
			rgt_dep[i] = 0;
			from_to[i] = -1;
			used[i] = false;
		}
		
		std::cin >> N;
		for(long long i=0; i<N; ++i){
			std::cin >> sl[i];
		}
	
		bool stop = false;
		for(long long i=0; i<N; ++i){
			long long j = 1; long long k = sl[i].size()-1;
			while(j < sl[i].size()-1 && sl[i][j] == sl[i][j-1]) ++j;
			while(k >= 0 && sl[i][k-1] == sl[i][k]) --k;
			
			if(j <= k && sl[i][0] == sl[i][sl[i].size()-1]){
				//std::cout << "STOP: between equal!" << std::endl;
				stop = true;
				break;
			}
			//std::cout << sl[i] << " " << " " << j << " " << k << sl[i][j] << " " << sl[i][k] << std::endl;
			
			for(; j<k; ++j){
				if(bet_cnt[sl[i][j]-'a'] || lft_dep[sl[i][j]-'a'] || rgt_dep[sl[i][j]-'a']){
					//std::cout << "STOP: between!" << std::endl;
					stop = true;
					break;
				}
				++bet_cnt[sl[i][j]-'a'];
				while(j<k && sl[i][j+1]==sl[i][j]) ++j;
			}
			
			if(sl[i][0] == sl[i][sl[i].size()-1]){				
				++same_cnt[sl[i][0]-'a'];
			}else{
				if(bet_cnt[sl[i][0]-'a'] || bet_cnt[sl[i][sl[i].size()-1]-'a']) {
					//std::cout << "STOP: between!" << std::endl;
					stop = true;
					break;
				}
			
				if(lft_dep[sl[i][0]-'a'] || rgt_dep[sl[i][sl[i].size()-1]-'a']) {
					//std::cout << "STOP: more connectors!" << std::endl;
					stop = true;
					break;
				}
				++lft_dep[sl[i][0]-'a'];
				++rgt_dep[sl[i][sl[i].size()-1]-'a'];
				from_to[sl[i][0]-'a'] = sl[i][sl[i].size()-1]-'a';
			}
		}
		if(stop){
			std::cout << "Case #" << (p+1) << ": " << 0 << std::endl;
			continue;
		}
		
		long long same = 1;
		long long total = 1;
		for(long long i=0; i<30; ++i){
			same *= factmod(same_cnt[i], MOD) % MOD;
		}
		total *= same;
		total %= MOD;
		
		for(long long i=0; i<30; ++i){
			if(used[i]) continue;
		
			if(lft_dep[i]){
				int f = from_to[i];
				used[i] = true;
				used[f] = true;
				while(f!=-1){
					f = from_to[f];
					if(used[f]) {
						std::cout << "Case #" << (p+1) << ": " << 0 << std::endl;
						stop = true;
						break;
					}
					used[f] = true;
				}
				if(stop) break;
			}
		}
		
		long long cnt = 0;
		for(long long i=0; i<30; ++i){
			/*if(same_cnt[i] && lft_dep[i] && rgt_dep[i]){
				std::cout << "Case #" << (p+1) << ": " << 0 << std::endl;
				stop = true;
				break;
			}*/
			if(same_cnt[i] && lft_dep[i] == 0 && rgt_dep[i] == 0) ++cnt;
			if(lft_dep[i] == 1 && rgt_dep[i] == 0) ++cnt;
		}	
		if(stop) continue;
		
		//std::cout << same << " " << cnt << std::endl;
		
		total *= factmod(cnt, MOD);
		
		std::cout << "Case #" << (p+1) << ": " << total % MOD << std::endl;
	}
}