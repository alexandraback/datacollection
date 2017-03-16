#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int tt;
	char s[105];
	cin>>tt;
	getchar();
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d: ",cs);
		gets(s);
		int len=strlen(s);
		//cerr<<"len = "<<len<<endl;
		int l=0,r=len-1,cnt=0;
		while (r>=0 && s[r]=='+') r--;
		while (l<=r){
			//cerr<<l<<" , "<<r<<endl;
			cnt++;
			if (s[l]=='-'){
				while (l<=r && s[l]=='-') l++;
				reverse(s+l,s+r+1);
			}
			else{
				while (l<=r && s[l]=='+') l++;
			}
		}
		printf("%d\n",cnt);
	}


	return 0;
}