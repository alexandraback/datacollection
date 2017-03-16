#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
#include<stdio.h>

using namespace std;

map<char, char> mapping;

void init()
{
	vector<string> samplesin(4);
	vector<string> samplesout(4);
	samplesin[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	samplesin[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	samplesin[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	samplesin[3]="y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd";
	
	samplesout[0]="our language is impossible to understand";
	samplesout[1]="there are twenty six factorial possibilities";
	samplesout[2]="so it is okay if you want to just give up";
	samplesout[3]="a b c d e f g h i j k l m n o p q r s t u v y w x y z now i know my abcs";

	for(int i=0;i<samplesin.size();i++)
	{
		for(int j=0;j<samplesin[i].size();j++)
		{
			char t=samplesin[i][j];
			mapping[ samplesin[i][j] ] = samplesout[i][j];
		}
	}



}

void transfer(string &line)
{
	for(int i=0;i<line.size();i++)
	{
		line[i]=mapping[line[i]];
	}
}

int main()
{
	freopen("C:\\Users\\theaa\\Downloads\\A-small-attempt3.in","r",stdin);
	freopen("C:\\Users\\theaa\\Downloads\\A-small-attempt3.out","w",stdout);
	init();
	int t;
	cin>>t;
	
	string line;
	getline(cin, line);
	for(int caseno=1; caseno<=t; caseno++)
	{
		getline(cin, line);
		transfer(line);
		cout<<"Case #"<<caseno<<": "<<line<<endl;
	}


	return 0;
}