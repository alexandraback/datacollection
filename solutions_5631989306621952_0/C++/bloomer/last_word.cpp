#include <iostream>
#include <unordered_set>
#include <unordered_map>


using namespace std;


int main(){

	int tc;
	cin>>tc;
	string s;
	string res;
	for(int i = 1; i <= tc; i++){
		cin>>s;
		res = "";
		res += s[0];
		char t = res[0];
		for(int j = 1; j < s.length(); j++){
			if(s[j] - '0' >= t - '0'){
				res = s[j] + res;
				t = s[j];
			}
			else{
				res += s[j];
			}
		}

		cout<<"Case #"<<to_string(i)<<": "<<res<<endl;

	}
	

}

