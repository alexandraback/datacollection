#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int possible(int K, int C, int S){
    if(C==1) return K<=S;
    return possible((K+1)/2,C-1,S);
}

void doThings(int K, int C, int S, int numCase){
    cout << "Case #" << numCase << ":";
    
    if(!possible(K,C,S)) {cout << " IMPOSSIBLE" << endl; return;}
    
    int KdonePos = 0;
    
    while(KdonePos < K){
        long long int pos = 0;
        for(int i=0;i<C && KdonePos < K;i++){
            pos *= K;
            pos += KdonePos;
            KdonePos++;
        }
        
        cout << " " << (pos+1);
    }
    
    cout << endl;
}

int main() {
	int T;

	cin >> T;

	int sum = 0;
	for (int i = 0; i < T; i++) {
		int K, C, S;
		cin >> K >> C >> S;

		doThings(K,C,S, i+1);
	}

	return 0;
}