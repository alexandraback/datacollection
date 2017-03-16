#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long lint;

int main() {
	ifstream cin("B-small-attempt0.in");
	ofstream cout("123.out");
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		map<lint,lint> m;
		lint count;
		cin>>count;
		for(lint j=0;j<(count*2-1)*count;j++){
			lint a;
			cin>>a;
			m[a]++;
		}
		vector<lint> answer;
		answer.reserve(count);
		for(auto &b:m)
			if(b.second%2!=0)
				answer.push_back(b.first);
		sort(answer.begin(),answer.end());
		cout<<"Case #"<<(i+1)<<": ";
		for(auto &b:answer)
			cout<<b<<" ";
		cout<<endl;
	}
	cin.close();
	cout.close();
	return 0;
}
