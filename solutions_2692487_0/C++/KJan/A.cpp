#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int T;
int A, N;
vector<int> motes;
vector<int> adds;

bool check() {
	
}

void calcAdds() {
	int curA = A;
	for (int i = 0; i< motes.size(); i++) {
			int add = 0;
			while (curA <= motes[i]) {
				if(curA-1 == 0) {
					add = 9999999;
					break;
				}
				add++;
				curA+=curA-1;
			}
			curA+=motes[i];
			adds.push_back(add);
			//cout << i << endl;
	}
	/*for (int i = 0; i< adds.size(); i++) {
		cout << adds[i] << endl;
	}*/
}


int main() {
	
	cin >> T;
	
	for (int t = 1; t<=T; t++) {
		//cout << "Case" << t << endl;
		//int ans = 0;
		cin >> A >> N;
		motes.clear();
		adds.clear();
		for (int n = 0; n<N; n++) {
			int temp;
			cin >> temp;
			motes.push_back(temp);
		}
		
		sort(motes.begin(), motes.end());
		calcAdds();
		/*
		cout << A << endl;
		
		for (int i = 0; i< motes.size(); i++) {
			cout << motes[i] << "  " << adds[i] << endl;
		}
		/*
		for (int i = 0; i< motes.size(); i++) {
			if (adds[i]>motes.size()-i) {
				ans+=motes.size()-i;
				break;
			} else {
				ans+=adds[i];
			}
			
		}
		*/
		int min = N;
		int a = 0;
		for (int i = 0; i< motes.size(); i++) {
			a+=adds[i];
			if(a+motes.size()-i-1 < min) min = a+motes.size()-i-1;
			//cout << i << " " << min <<" " << a+motes.size()-i-1 << endl;
		}
		
		cout << "Case #" << t << ": " << min << endl;
		
	}
	
	
return 0;
}
