#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

long long T;
long long N;

struct Attack{
	long long w;
	long long e;
	long long s;
};

bool operator<(Attack a1, Attack a2){
	return a1.w < a2.w;
}

std::vector<std::pair<unsigned long long, Attack> > ats; 

#define MAX 10000

long long ht[MAX];
long long bt[MAX];

int main(){
	std::cin >> T;
	
	for(long long p=0; p<T; ++p){
		ats.clear();
		for(long long i=0; i<MAX; ++i) bt[i] = ht[i] = 0;
	
		std::cin >> N;
		for(long long i=0; i<N; ++i){
			Attack first;
			unsigned long long d;
			long long n;
			long long dd, dp, ds;
			std::cin >> d >> n >> first.w >> first.e >> first.s >> dd >> dp >> ds;
			first.w+=MAX/2;
			first.e+=MAX/2;
			for(long long i=0; i<n; ++i){
				if(first.s<0) first.s=0;
				ats.push_back(std::make_pair(d, first));
				d+=dd;
				first.w+=dp;
				first.e+=dp;
				first.s+=ds;
			}
		}
		std::sort(ats.begin(), ats.end());

		
		long long lst = 0;
		unsigned long long total = 0;

		for(long long i=0; i<ats.size(); ++i){
			Attack at = ats[i].second;

			//check if attack was succesfull
			bool b = false;
			for(long long j=at.w; j<=at.e; ++j){
				if(ht[j] < at.s){
					b = true;
					break;
				}
				if(j!=at.e && bt[j] < at.s){
					b = true;
					break;
				}
			}
						
			if(b){
				//std::cout << "attack at day " << ats[i].first << " was succesfull" << std::endl;
				++total;
			}else{
				//std::cout << "attack at day " << ats[i].first << " was unsuccesfull" << std::endl;
			}
			
			if(i<ats.size()-1 && ats[i].first<ats[i+1].first){
				//make wall higher
				for(long long k=lst; k<=i; ++k){
					Attack atc = ats[k].second;
					for(long long j=atc.w; j<=atc.e; ++j){
						ht[j] = std::max(ht[j], atc.s);
						if(j!=atc.e) bt[j] = std::max(bt[j], atc.s);
					}
				}
				lst = i+1;
			}
		}
		std::cout << "Case #" << (p+1) << ": " << total << std::endl;
	}
}