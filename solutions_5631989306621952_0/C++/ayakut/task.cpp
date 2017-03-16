#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 102000
#define pb push_back

using namespace std;
string str;
int main(){
	int Test,tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d: ", tt);
		cin >> str;
		string res;
		for(int i = 0 ; i < str.length();i++){
			
			if(res == "" || res[0] <= str[i]){
				res = str[i] + res;
			}
			else 
				res = res + str[i];
		}
		cout << res << endl;
	}
	return 0;
}