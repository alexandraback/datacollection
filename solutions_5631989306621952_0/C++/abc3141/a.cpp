#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int T;
string S;
string ans="";
bool F(string s1,string s2){
	for(int i=0;i<(int)s1.length();i++){
		if((s1[i]-'a')<(s2[i]-'a'))return true;
		else if((s1[i]-'a')>(s2[i]-'a'))return false;
	}
	return true;
}
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		ans="";
		cin >> S;
		for(int i=0;i<(int)S.length();i++){
			if(i==0){
				ans+=S[0];
				continue;
			}
			string ans1,ans2;
			ans1=ans+S[i];
			ans2=S[i]+ans;
			if(F(ans1,ans2))ans=ans2;
			else ans=ans1;
		}
		cout << "Case #" << cas+1 << ": " << ans << "\n";
	}
	return 0;
}
