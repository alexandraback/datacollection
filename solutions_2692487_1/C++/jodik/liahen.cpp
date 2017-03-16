#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> knihy;

long long najmen(long long *aktual, long long ake){
	long long kolko=0;
	while(*aktual<=ake){
		(*aktual)+=(*aktual)-1;
		kolko++;
	}
	(*aktual)+=ake;
	return kolko;
}

int main(){
	long long n;
	scanf("%lld",&n);
	long long cas=0;
	while(n--){
		cas++;
		long long a,m;
		scanf("%lld%lld",&a,&m);
		vector<long long> cisla;
		long long kolko=0;
		long long najm=10000000;
		
		while(m--){
			long long b;
			scanf("%lld",&b);
			cisla.push_back(b);
		}
		if(a==1) najm=cisla.size();
		else{
			sort(cisla.begin(),cisla.end());
			for(long long i=0; i<cisla.size(); i++){
				long long dokonca=cisla.size()-i;
				najm=min(kolko+dokonca,najm);
				kolko+=najmen(&a,cisla[i]);
			}
			najm=min(kolko,najm);
		}
		printf("Case #%lld: %lld\n",cas,najm);
	}
		return 0;
}

