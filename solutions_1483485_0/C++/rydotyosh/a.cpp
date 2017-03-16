
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

map<char, char> mapping;

int loadmapping()
{
	ifstream f("mapping");
	while(f)
	{
		char input,output;
		f>>input>>output;
		mapping[input]=output;
	}
}

string convert(string &s)
{
	string res=s;
	for(int i=0;i<s.size();++i)
	{
		map<char,char>::iterator f=mapping.find(s[i]);
		if(f==mapping.end())
			continue;
		res[i]=f->second;
	}
	return res;
}

int main()
{
	loadmapping();
	string s;
	getline(cin, s, '\n');
	int n=atoi(s.c_str());
	for(int i=0;i<n;++i)
	{
		string s;
		getline(cin, s, '\n');
		cout<<"Case #"<<i+1<<": "<<convert(s)<<endl;
	}
}


