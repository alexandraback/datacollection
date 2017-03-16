#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define LL __int64
#define MIN(a,b) (((a)<(b))?(a):(b))
LL S[1000];
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		int N;
		LL X=0;
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>S[i];
			X+=S[i];
		}
		vector<pair<LL, int> > v;
		for(int i=0;i<N;++i){
			v.push_back(make_pair(S[i], i));
		}
		sort(v.rbegin(), v.rend());
		vector<double> needed(N,0);
		int unsafe=0;
		LL XX=X;
		for(int k=0;k<N;++k){
			LL s=v[k].first;
			if(s*(N-1-k)<=XX-s+X){
				unsafe=k;
				break;
			}else{
				XX-=S[v[k].second];
			}
		}
		int n=N-unsafe;
		for(int i=unsafe;i<N;++i){
			if(XX==0){
				needed[v[i].second]=1.0/n;
			}else{
				double r=double(XX-n*S[v[i].second]+X)/double(n*X);
				needed[v[i].second]=r;
			}
			
		}
		printf("Case #%d:",c);
		for(int i=0;i<N;++i){
			printf(" %0.9lf", 100*needed[i]);
		}
		printf("\n");
	}

	return 0;
}

