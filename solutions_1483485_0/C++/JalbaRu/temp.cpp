#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d\n",&T);
	string b="qwertyuiopasdfghjklzxcvbnm";
	string a="zfotwajdkrynscvxuigqmephbl";
	string c="zfotwajdkrynscvxuigqmephbl";
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(b[j]-'a'==i) c[i]=a[j];
	for(int t=0;t<T;t++){
		string s;
		getline(cin,s);
		for(int i=0;i<s.size();i++)
			if(s[i]!=' ') s[i]=c[s[i]-'a'];
		printf("Case #%d: %s\n",t+1,s.c_str());
	}
}