#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
long long ans;
int se[101];
bool rec[101];
//vector<string> v;
string s[101];

void dfs(int x, int d){
	if(x == d){
		bool fg[26] = {};
		string str;
		for(int i = 0; i < n; i++)
			str += s[se[i]];
		bool is = 1;
		fg[str[0] - 'a'] = 1;
		for(int i = 1; i < str.length(); i++){
			if(!fg[str[i] - 'a']){
				fg[str[i] - 'a'] = 1;
			}
			else{
				if(str[i] != str[i - 1]){
					is = 0;
					break;
				}
			}
		}
		if(is)
			ans++;
		ans %= 1000000007;
		return;
	}
	for(int i = 0; i < n; i++){
		if(!rec[i]){
			rec[i] = 1;
			se[x] = i;
			//ct++;
			dfs(x + 1, d);
			//ct--;
			rec[i] = 0;
		}
	}
}

int main(){
	int t, tc = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		//v.clear();
		for(int i = 0; i < n; i++){
			cin >> s[i];//, v.push_back(s[i]);
			char s2[101] = {};
			s2[0] = s[i][0];
			int x = 1;
			for(int j = 1; j < s[i].length(); j++){
				if(s[i][j] != s[i][j - 1])
					s2[x++] = s[i][j];
			}
			s[i] = string(s2);
			//cout << s2 << endl;
		}
		//sort(v.begin(), v.end());
		ans = 0;
		dfs(0, n);
/*		do{
			bool fg[26] = {};
			string str;
			for(int i = 0; i < n; i++)
				str += v[i];
			bool is = 1;
			fg[str[0] - 'a'] = 1;
			for(int i = 1; i < str.length(); i++){
				if(!fg[str[i] - 'a']){
					fg[str[i] - 'a'] = 1;
				}
				else{
					if(str[i] != str[i - 1]){
						is = 0;
						break;
					}
				}
			}
			if(is)
				ans++;
			ans %= 1000000007;
		}while(next_permutation(v.begin(), v.end()));*/
		printf("Case #%d: %lld\n", ++tc, ans % 1000000007);
	}
	return 0;
}
