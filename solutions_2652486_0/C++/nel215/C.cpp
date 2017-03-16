#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

double random(){
	return (double)rand()/((double)RAND_MAX+1.0);
}

void cardSampling(int N,int M,vector<int> &card){
	REP(i,N)card[i] = 2+(int)(random()*(M-1));
}

bool check(const vector<int> &card,const vector<int> &product){
	vector<int> used(product.size(),0);
	for(int bit=0,n=card.size() ; bit<(1<<n) ; bit++){
		int p = 1;
		REP(i,n)if(bit>>i&1)p *= card[i];
		REP(j,product.size())if(p==product[j])used[j]=1;
	}
	return product.size()==count(ALL(used),1);
}

int main(){
	srand(215);
	int T;
	cin >> T;
	REP(tc,T){
		int R,N,M,K;
		cin >> R >> N >> M >> K;
		REP(r,R){
			vector<int> product(K);
			vector<int> sampleProduct(K);
			vector<int> sampleCard(N);
			vector<int> bestCard(N);
			REP(k,K)cin >> product[k];
			sort(ALL(product));
			int bestCorrect = -100;
			int ok = 0;
			cout << "Case #" << tc+1 << ":" << endl;
			REP(j,5000){
				cardSampling(N,M,sampleCard);
				if(ok==500)break;
				if(check(sampleCard,product)){
					ok+=1;
					int correct = 0;
					clock_t start = clock();
					REP(_,5000){
					//while((clock()-start)/CLOCKS_PER_SEC<0.5){
						REP(k,K){
							sampleProduct[k] = 1;
							REP(o,N)if(random()>=0.5)sampleProduct[k] *= sampleCard[o];
						}
						sort(ALL(sampleProduct));
						if(sampleProduct==product)correct += 1;
					}
					if(bestCorrect<correct){
						bestCard = sampleCard;
						bestCorrect = correct;
					}
				}
			}
			//cout << bestCorrect << endl;
			REP(i,N)cout << bestCard[i];
			cout << endl;
		}
	}
	return 0;
}
