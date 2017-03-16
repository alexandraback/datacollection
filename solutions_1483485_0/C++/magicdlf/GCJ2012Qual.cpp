// GCJ2012Qual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stdio.h"

using namespace std;

char mapping[]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	int T;
	cin>>T;
	char buf[2048];
	cin.getline(buf,2048);
	for(int tc=0;tc<T;tc++)
	{
		cin.getline(buf,2048);
		string str(buf);
		for(int i=0;i<str.size();i++)
		{
			if(str[i]==' ') continue;
			str[i]=mapping[str[i]-'a'];
		}
		cout<<"Case #"<<tc+1<<": "<<str<<endl;
	}
	return 0;
}