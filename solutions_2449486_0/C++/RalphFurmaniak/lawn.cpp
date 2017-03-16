#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		int N,M;
		cin >> N >> M;
		int lawn[200][200];
		vector<int> max1(200,0);
		vector<int> max2(200,0);
		for(int n=0; n<N; n++) for(int m=0; m<M; m++) {
			cin >> lawn[n][m];
			max1[n] = max(max1[n],lawn[n][m]);
			max2[m] = max(max2[m],lawn[n][m]);
		}
		bool good=true;
		for(int n=0; n<N; n++) for(int m=0; m<M; m++) {
			if(lawn[n][m] < max1[n] && lawn[n][m] < max2[m]) good=false;
		}
		cout << "Case #" << ts << ": " << (good?"YES":"NO") << endl;
	}
}
