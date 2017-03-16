#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
bool compare (int i, int j){
	return (i < j);
}

using namespace std;
int main(){
	int T;
	cin >> T;
	
	vector <int> list;
	int x[2501];
	int n;
	int temp;
	for(int t = 1;t <= T;t ++){
		n;
		cin >> n;
		memset (x, 0, 10004);
		list.clear();
		for(int i = 0; i < n * (2 * n - 1);i ++){
			cin >> temp;
			x[temp] ++; 
		}
		for(int i = 0;i < 2501;i ++){
			if(x[i] % 2 == 1){
				list.push_back(i);
				if(list.size() == n) break;
			}
		}
		sort(list.begin(),list.end(),compare);
		cout << "Case #" << t << ": ";
		int l = list.size();
		for(int i = 0;i < l;i ++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
