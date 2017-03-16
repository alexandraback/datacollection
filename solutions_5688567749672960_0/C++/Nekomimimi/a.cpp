#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;


	for (int i= 0; i< T;i++) {
		int n;
		cin >> n;

		map<long,int> dp;
		queue<pair<long,int> > que;

		que.push(make_pair(1,1));
		dp[1] = 1;
		while(1) {
			pair<long,int> current = que.front();
			que.pop();
			int num = current.first;
			int count = current.second;

			if (num==n) {
				cout << "Case #" << i +1 << ": " << count << endl;
				break;
			}
			count ++;
			int cand1 = num + 1;
			if (dp[cand1] == 0) {
				dp[cand1] = count;
				que.push(make_pair(cand1,count));			
			}


			string str = std::to_string(num);
			string tmp = "";

			for (int j=0;j<str.length();j++) {
				tmp = str[j] + tmp; 
			}
			int cand2  = atoi(tmp.c_str());
			if (dp[cand2]==0) {
				dp[cand2] =count;
				que.push(make_pair(cand2,count));				
			}
		}
	}
	return 0;
}