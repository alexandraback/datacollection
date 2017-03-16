#include<bits/stdc++.h>
using namespace std;

int c, d, v;
vector<int> arr;
int value[1000];

void coin(int pos, int val){	
	value[val] = 1;
	if(pos==(int)arr.size()) return;

	coin(pos + 1, val);
	coin(pos + 1, val + arr[pos]);
	return;
}


int main(){
	
	ifstream cin;
	cin.open("csmall.in");
	ofstream cout;
	cout.open("clarge.o");
	
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		arr.clear();
		memset(value, 0, sizeof value);
		cin >> c >> d >> v;
		for(int i = 0; i < d; i++){
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		coin(0,0);
		//for(int i = 1; i <= v; i++) cout << value[i] << " ";
		int numRequired = 0;
		for(int i = 1; i <= v; i++){
			if(value[i]==0){
				arr.push_back(i);
				numRequired++;
				coin(0,0);
			}
		}
		cout << "Case #" << a << ": " << numRequired << "\n";
	}

}
