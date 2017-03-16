#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define PI 3.14159265358979323846
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int z=1;z<=T;z++){
		int A,N;
		cin >> A >> N;

		int mote[N];
		for(int i=0;i<N;i++)
			cin >> mote[i];

		int best = N;

		sort(mote,mote+N);

		int cur = 0;
		int moves = 0;

		if(A==1){
			moves = best;
			goto end;
		}
		while(cur<N){
			if(mote[cur]<A){
				A += mote[cur];
				cur++;
			} else {
				best = min(best,moves+N-cur);
				while(A <= mote[cur]){
					A += A-1;
					moves++;
				}
			}
		}end:
		cout<<"Case #"<<z<<": "<<min(best,moves)<<endl;
	}
}