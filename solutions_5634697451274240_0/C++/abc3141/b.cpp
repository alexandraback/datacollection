#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int T;
string S;
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		cin >> S;
		S+='+';
		int cou=0;
		for(int i=0;i<(int)S.length()-1;i++){
			if(S[i]!=S[i+1])cou++;
		}
		printf("Case #%d: %d\n",cas+1,cou);
	}
}
