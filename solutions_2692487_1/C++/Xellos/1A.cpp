// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int T,N;
	long long A;
	cin >> T;
	for(int t =0; t < T; t++) {
		cin >> A >> N;
		vector<long long> V(N);
		for(int i =0; i < N; i++) cin >> V[i];
		sort(V.begin(),V.end());
		int ans =N, akt =0;
		if(A > 1) for(int i =0; i < N; i++) { // absorb i
			while(A <= V[i]) {
				A +=A-1;
				akt++;}
			A +=V[i];
			ans =min(ans,N-1-i+akt);}
		cout << "Case #" << t+1 << ": " << ans << "\n";}
    return 0;}
        
// look at my code
// my code is amazing
