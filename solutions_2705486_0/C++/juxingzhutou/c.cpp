#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;

char str[1000];
int main()
{
	int T,abc;
	set<string> dic;
	FILE * in;
	in = fopen("C:/Users/lvhh/Desktop/test.txt","r");	
		FILE * out;
	out = fopen("C:/Users/lvhh/Desktop/outputC.out","w");
	while(fscanf(in,"%s\n",str)!=-1)
	{
		string a(str);
		dic.insert(a);
	}
	
	int i;
	string t;
	scanf("%d",&T);
	for(abc=1;abc<=T;++abc)
	{
		int count=0;
		cin>>t;
		int j;
		string a;
		for(i=0,j=t.length()-1;i<=j;)
		{			
			a = t.substr(i,j-i+1);
			if(dic.find(a)==dic.end()) {--j;}
			else if(i==j)
			{
				++count;
				i++;
				j=t.length()-1;
			}
			else{
				i=j+1;
				j=t.length()-1;
			}
		}
		fprintf(out,"Case #%d: %d\n",abc,count);
	}
	return 0;
}
