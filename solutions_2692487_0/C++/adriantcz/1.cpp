#include<iostream>
#include<algorithm>
#include<vector>
#define VECINT std::vector<int>
#define INF 100000000

int CALC(int A, const VECINT & D);

int main(){
	int T;
	std::cin >> T;
	
	
	for(int i=0; i < T;++i){
		int A,n;
		std::cin >> A >> n;
		VECINT D(n);
		for(int j=0; j<n; ++j)
			std::cin >> D[j];
		
		std::sort(D.begin(),D.end());
		
		std::cout << "Case #" << (i+1) << ": " << CALC(A,D) << std::endl;
	}
	
	return 0;
}

int CALC(int A, const VECINT & D){
	int R = D.size();
	for(int p=1;p<=D.size();++p){
		int a = A;
		int k=0;
		int r=D.size()-p;
		
		while(k<p&&r<R){
			while(k<p&&a>D[k])
				a+=D[k++];
				
			if(k<p){
				++r;
				a=2*a-1;
			}
		}
		
		R=std::min(R,r);
	}
	
	return R;
}
