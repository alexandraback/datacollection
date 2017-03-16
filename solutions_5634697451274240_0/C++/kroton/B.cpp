#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		string S;
		cin >> S;
		int ans = 0, flip = 0;
		for(int i=S.size()-1;i>=0;i--){
			if(((S[i] == '-') ^ flip) == 1){
				++ans;
				flip ^= 1;
			}
		}
		cout << "Case #" << t << ": " << ans;
		if(t != T){
			cout << endl;
		}
	}
	return 0;
}
