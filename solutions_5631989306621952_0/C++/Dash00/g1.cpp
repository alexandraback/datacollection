#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t,cas=1;
	cin >> t;
	while(t--) {
		string str,ans;
		cin >> str;
		for(int i = 0 ; i < str.size(); i ++) {
			if(ans.size() == 0 || ans[0] > str[i])
				ans += str[i];
			else
				ans = str[i] + ans;
		}
		printf("Case #%d: ",cas++);
		cout << ans << endl;
	}
	return 0;
}

