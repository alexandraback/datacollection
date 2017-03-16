#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int v[12];

void solve(int ind,int N,int E, int energy,int R,int gain,int& best){
	if(ind==N){
		best = max(best,gain);
		return;
	}

	for(int i=0;i<=energy;i++){
		solve(ind+1,N,E,min(E,energy-i+R),R,gain + i*v[ind],best);
	}
}

int main(){
	int T;
	cin >> T;
	for(int z=1;z<=T;z++){
		int E,R,N;
		cin >> E >> R >> N;

		for(int i=0;i<N;i++)
			cin >> v[i];

		int best = -1;

		solve(0,N,E,E,R,0,best);
		
		

		cout<<"Case #"<<z<<": "<<best<<endl;
	}
}