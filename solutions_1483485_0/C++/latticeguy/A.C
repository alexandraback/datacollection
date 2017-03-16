#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<set>
using namespace std;

typedef unsigned long long uint64;
typedef long long int64;

char A[26];
bool B[26];
int main(int argc, char *argv[])
{
	for(int i=0;i<26;i++)B[i]=false;
	string sin("ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv");
	string sout("ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup");
	A['y'-'a']='a';B['y'-'a']=true;
	A['e'-'a']='o';B['e'-'a']=true;
	A['q'-'a']='z';B['q'-'a']=true;

	for(int i=0;i<sin.size();i++)
	{
		char c=sin[i];
		char cc=sout[i];
		A[c-'a']=cc;B[c-'a']=true;
	}
	A['z'-'a']='q'; B['z'-'a']=true;
	/*
	for(int i=0;i<26;i++)
	{
		char x='a'+i;
		cout<<x<<':'<<A[i]<<endl;
		if(!B[i])cout<<i<<endl;
	}
	*/
//readin file
	string file;
	if(argc!=2){cerr<<"0,1 or 2!"<<endl;exit(1);}
	switch(atoi(argv[1]))
	{
		case 0: file="test"; break;
		case 1: file="A-small"; break;
		case 2: file="A-large"; break;
		default: cerr<<"choose the correct file, 0(test),1(small),2(large)"<<endl;exit(1); break;
	}
	string ifilename=file+".in"; string ofilename=file+".out";
	ifstream input(ifilename.c_str());ofstream output(ofilename.c_str());

//read in number of events
	int T;
	input>>T;

		string s,re;
		getline(input,s);
//main loop start
	for(int t=0;t<T;t++)
	{
		getline(input,s);
		re=s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')continue;
			re[i] = A[s[i]-'a'];
		}
		output<<"Case #"<<t+1<<": "<<re<<endl;
	}

	input.close();
	output.close();
	return 0;
}
