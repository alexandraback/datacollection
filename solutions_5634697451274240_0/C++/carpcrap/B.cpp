#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	for(int tt =1; tt<=T; tt++){
		int n,j;
		scanf("%d %d", &n, &j);
		printf("Case #%d:",tt);
		string s;
		cin >> s;
		int grpCnt =0;
		int cur = s.length()-1;
		if(s[cur] == '-') grpCnt++;
		for(;cur >0; cur--){
			if(s[cur] != s[cur-1]){
				grpCnt++;
			}
		}
		printf(" %d", grpCnt);
		//cout<<s<<'.'<<s.length()<<'.';
		printf("\n");
	}
	return 0;
}
