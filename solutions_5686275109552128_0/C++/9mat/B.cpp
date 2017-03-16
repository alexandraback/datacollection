#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define FORS(i,s,n) for(int i = (s), n_ = (n); i < n_; i++)
#define ITER(it,v) for(auto it = (v).begin(); it != (v).end(); ++it)

template <typename T> void updatemax (T& a, const T& b) {
	if(b>a) a=b;
}

template <typename T> void updatemin (T& a, const T& b) {
	if(b<a) a=b;
}

using namespace std;

int main(){
	int T, D, P;

	cin>>T;

	FOR(icase, T){
		cin>>D;

		vector<int> P(D);
		FOR(i,D) cin>>P[i];

		int maxP = P[0];
		FOR(i,D) updatemax(maxP,P[i]);
		
		int min = maxP;
		FORS(k,1,maxP){
			int interupt = 0;
			FOR(i,D) interupt += (P[i]+k-1)/k - 1;
			updatemin(min, interupt+k);
		}


		cout<<"Case #"<<icase+1<<": "<<min<<endl;

	}

	return 0;
}

