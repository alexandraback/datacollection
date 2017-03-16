#include "bits/stdc++.h"
using namespace std;
int t;
string str;
int ans;
int n;
int tc = 0;
int main(){
	cin >> t;
	while(t--){
		cin >> str;
		n = str.size();
		str = " " + str;
		ans = 0;
		printf("Case #%d: " , ++tc);
		for(int i = n ; i >= 1 ; --i){
			if(str[i] == '-'){
				int l = 1;
				int r = i;
				while(l < r){
					swap(str[l++] , str[r--]);
				}
				for(int j = 1 ; j <= i ; ++j){
					if(str[j] == '+'){
						str[j] = '-';
					}
					else{
						str[j] = '+';
					}
				}
				++ans;
				if(str[i] == '-'){
					++ans;
					for(int j = i ; j >= 1 ; --j){
						if(str[j] == '-'){
							str[j] = '+';
						}
						else{
							break;
						}
					}
				}
			}
		}
		printf("%d\n" , ans);
	}
}