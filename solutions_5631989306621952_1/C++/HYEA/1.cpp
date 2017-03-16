#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

void tmain()
{
	string a;
	string board="";
	cin >> a;
	for(char x: a)
	{
		if(x+board < board+x)
			board = board + x;
		else
			board = x + board;
	}
	cout << board << endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
}
