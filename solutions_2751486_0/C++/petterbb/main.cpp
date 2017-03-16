#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
#define MAXN 1000000

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int cases = 1; cases <= t; cases++){
        cout << "Case #" << cases << ": ";
		string s, sub;
		int n;
		cin >> s >> n;
		long long res = 0;
		for(int i = 0; i < s.size(); i++){
			for(int j = i + n; j <= s.size(); j++){
				//cal;
				int cnt = 0;
				int st;
				for(st = i; st < j; st++){
					if(s[st] != 'a' && s[st] != 'e' && s[st]!='i' && s[st]!='o' && s[st]!='u'){
						cnt++;
						if(cnt == n)
							break;
					}
					else{
						cnt = 0;
						//if(j - st < n){
						//	break;
						//}
					}
				}
				if(cnt == n){
					res ++;
				}
				//end
			}
		}
		cout << res << endl;

	}
	//system("pause");
	return 0;
}
