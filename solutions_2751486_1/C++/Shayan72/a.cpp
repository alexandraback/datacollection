#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

bool b(char c){
	if(c == 'i' || c == 'u' || c == 'a' || c == 'o' || c == 'e'){
		return false;
	}
	return true;
}

int main()
{
	int T,n;
	cin >> T;
	string str;
	for( int o = 1; o <= T; o++ )
	{
		cin >> str >> n;
		int ans = 0, cnt = 0, last = -1;
		for(int i = 0; i < str.size(); i++){
			if(b(str[i])){
				cnt++;
			}
			else{
				cnt = 0;
			}
			if(cnt >=n){
				last = i - n + 1;
			}
			if(last != -1){
				ans += last + 1;
			}
		}
		
		cout << "Case #" << o << ": " << ans << endl;
	}
	
	
	return 0;
}
