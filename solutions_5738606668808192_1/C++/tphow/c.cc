#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
vector<int> v_;
int sz, t, n, j;

void dfs(){
	if(v_.size() == sz && v.size() == j)
		return;
	if(v_.size() == sz){
		v.push_back(v_);
		return;
	}
	for(int i = 0; i < 2; i++){
		v_.push_back(i);
		dfs();
		v_.pop_back();
	}
}

int main(){
	cin >> t >> n >> j;
	cout << "Case #1:\n";
	sz = (n - 4) / 2;
	dfs();
	for(int i = 0; i < j; i++){
		unsigned int c = 3;
		for(int k = 0; k < sz; k++){
			if(v[i][k])
				c += 3 << (2 * (k + 1));
		}
		c += 3 << (n - 2);
		v_.clear();
		while(c){
			v_.push_back(c % 2);
			c /= 2;
		}
		for(int i = n-1; i >= 0; i--)
			cout << v_[i];
		for(int i = 3; i < 12; i++)	
			cout << " " << i;
		cout << endl;
	}

	return 0;
}