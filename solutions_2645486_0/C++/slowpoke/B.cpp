#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

static void doComp(){
	long long E,R,N;

	cin >> E >> R >> N;

	vector<long long> v(N);
	for(int i=0; i<N; ++i){
		cin >> v[i];
	}
	long long ans = 0, curE = E;
	for(int i=0; i<N; ++i){
		int j = i+1;
		while(j<N && v[j]<=v[i]){
			++j;
		}
		if(j==N){
			ans += curE*v[i];
			curE = 0;
		}else{
			long long rec = min(E, min(E,R)*(j-i));
			long long useUntil = E-rec;
			if(curE > useUntil){
				ans += (curE-useUntil)*v[i];
				curE = useUntil;
			}
		}

		curE += R;
		curE = min(E, curE);
	}

	cout << ans << endl;

}

int main(){
	int C;
	cin >> C;
	for(int c=1; c<=C; ++c){
		cout << "Case #" << c << ": ";
		doComp();
	}

}
