#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	char c[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	string str;
	int n;
	char tt;
	cin>>n;
	for(int i=1;i<=n;i++){
		getline(cin,str);
		while(str=="")
			getline(cin,str);
		int len=str.length();
		printf("Case #%d: ",i);
		for(int j=0;j<len;j++){
			if(str[j]==' ')
				printf(" ");
			else
				printf("%c",c[str[j]-'a']);
		}
		printf("\n");
	}
	return 0;
}
