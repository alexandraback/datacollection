#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t, b, m, max;
	cin >> t;
	for(int i=0; i<t; ++i){
		cin >> b >> m;
		max = 1 << (b-2);
		if(m>max) cout << "Case #" << i+1 << ": IMPOSSIBLE\n";
		else{
			vector<string> matrix(b, "");
			for(int j=0; j<b; ++j){
				for(int k=0; k<=j; ++k) matrix[j]+="0";
				for(int k=j+1; k<b; ++k) matrix[j]+="1";
			}
			cout << "Case #" << i+1 << ": POSSIBLE\n";
			int sub=max-m, c=1;
			while(sub>0){
				int a=sub%2;
				if(a==1) matrix[c][b-1]='0';
				sub/=2;
				c++;
			}
			for(int j=0; j<b; ++j){
				cout << matrix[j] << endl;
			}
		}
	}	
	return 0;
}