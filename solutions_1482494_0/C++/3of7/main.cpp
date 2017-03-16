#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <sstream>
#include <map>
#include <limits>

using namespace std;

int T,N;

int main() {
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		int ans = 0;
		int complete[1000];
		vector< vector<int> > need;
		memset(complete, 0, sizeof(complete));
		cin>>N;
		need.clear();
		need.resize(N, vector<int>(2));
		for(int n=0; n<N; n++) {
			cin>>need[n][1]>>need[n][0];
		}
		sort(need.begin(), need.end());
		reverse(need.begin(), need.end());
		bool flag = true;
		int total = 0;
		while(flag == true) {
			flag = false;
			for(int i=0; i<N; i++) {
				if(complete[i] == 0) {
					if(total >= need[i][0]) {
						total += 2;
						complete[i] = 2;
						flag = true;
						ans++;
						break;
					}
				}
			}
			if(flag) continue;
			for(int i=0; i<N; i++) {
				if(complete[i] == 1) {
					if(total >= need[i][0]) {
						total += 1;
						complete[i] = 2;
						flag = true;
						ans++;
						break;
					}
				}
			}
			if(flag) continue;
			for(int i=0; i<N; i++) {
				if(complete[i] == 0) {
					if(total >= need[i][1]) {
						total += 1;
						complete[i] = 1;
						flag = true;
						ans++;
						break;
					}
				}
			}
		}
		/*for(int i=0; i<N; i++) {
			cout<<complete[i]<<endl;
		}*/
		cout<<"Case #"<<t<<": ";
		flag = true;
		for(int i=0; i<N; i++) {
			if(complete[i] != 2) {
				cout<<"Too Bad"<<endl;
				flag = false;
				break;
			}
		}
		if(flag) {
			cout<<ans<<endl;
		}
	}

	return 0;
}