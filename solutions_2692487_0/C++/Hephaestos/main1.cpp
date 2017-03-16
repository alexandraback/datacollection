#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;


int main(void) {
	int T;
	cin>>T;
	for (int t=0;t<T;++t)  {
		int A,N;
		cin>>A>>N;
		deque<int> motes;
		for (int j=0;j<N;++j){
			int m;
			cin>>m;
			motes.push_back(m);
		}
		sort(motes.begin(),motes.end());
		vector<int> x(motes.size()+1,0);
		int result = 500;
		if (A==1) {
			result = N;
		}else {
			for (int j=0;j<N;++j) {	
				int y=0;
				while(A<=motes[j]) {
					A+=A-1;
					++y;
				}
				A+=motes[j];
				x[j+1] = x[j]+y;
			}
			for (int j=0;j<=N;++j) {
				result = min(result,x[j]+N-j);
			}
		}
		cout<<"Case #"<< t+1<<": "<<result<<'\n';
	}
	return 0;
}

