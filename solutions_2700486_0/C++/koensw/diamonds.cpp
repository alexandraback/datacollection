#include <iostream>
#include <iomanip>

int T;
long long sum[1001];
long long amo[1001];
long long rev[3000001];

int N, X, Y;

int dp[2000];

int main(){
	std::cin >> T;
	
	for(int i=0; i<1001; ++i){
		int j = 2*i;
		amo[i] = 2*j+1;
		sum[i] = sum[i-1]+amo[i];
		for(int k=sum[i-1]+1;k<=sum[i]; ++k){
			rev[k] = j;
		}
	}
	
	
	std::cout << std::fixed << std::setprecision(7);
	for(int p=0; p<T; ++p){
		for(int i=0; i<2000; ++i){
			dp[i] = 0;
		}
	
		std::cin >> N >> X >> Y;
		
		//std::cout << rev[N] <<  " == " << X+Y << std::endl;
		if(rev[N] < X+Y) std::cout << "Case #" << (p+1) << ": " << 0.0 << std::endl;
		else if(X+Y < rev[N]) std::cout << "Case #" << (p+1) << ": " << 1.0 << std::endl;
		else{
			int tfl = 1;
			int flw = N;
			tfl = amo[rev[N]/2]; 
			if(N != 1) flw = N-sum[(rev[N]-1)/2];
		
			if(X == 0) {
				if(flw == tfl) std::cout << "Case #" << (p+1) << ": " << 1.0 << std::endl;
				else std::cout << "Case #" << (p+1) << ": " << 0.0 << std::endl;
				continue;
			}
			int mx = (tfl-1)/2;
			
			int tot = 0;
			for(int i=0; i<=mx && i<=flw; ++i){
				if(flw-i>mx) continue;
				//std::cout << " -> " << i << " " << flw-i << std::endl;
				for(int j=0; j<=i; ++j){
					if(i == flw-i) dp[j]+=2;
					else ++dp[j];
				}	
				if(i == flw-i) tot+=2;
				else ++tot;
			}
			int chk = rev[N]-X+1;
			
			//std::cout << "UND " << flw << " " << tfl << " " << mx << " " << chk << std::endl;
			std::cout << "Case #" << (p+1) << ": " << 1.0*dp[chk]/tot << std::endl;
		}
	}
}
