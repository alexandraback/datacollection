#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int,int> pii;
int main(){
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; ++tc){
		string s;
		cin>>s;
		printf("Case #%d: ", tc);
		int len = s.length();
		string temp = "";
		temp+=s[0];
		for(int i=1;i < len;++i){
			if(s[i] >= temp[0]){
				temp = s[i] + temp;
			}
			else{
				temp = temp + s[i];
			}
		}
		puts(temp.c_str());
	}
	return 0;
}