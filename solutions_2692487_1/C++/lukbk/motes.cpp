#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int c=1; c<=T; c++) {
		int A, N;
		cin >> A >> N;
		int t;
		vector<int> M;
		
		for(int i=0; i<N; i++) {
			cin >> t;
			M.push_back(t);
		}
		sort(M.begin(), M.end());
		int ops=0;
		set<int> minOps;
		{
			int i=0;
			while(i<N) {
				if(M[i] < A)  {
					A += M[i];
					i++;
				} else {
					A += A-1;
					minOps.insert(ops + (N-i));
					ops++;
					if(A==1) {
						ops = N;
						break;
					}
				}
			}
		}
		if(!minOps.empty() && *minOps.begin() < ops)
			ops = *minOps.begin();
		cout << "Case #" << c <<": "<<ops<<endl;
	}
}

		
		
