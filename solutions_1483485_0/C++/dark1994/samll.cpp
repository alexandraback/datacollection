#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<cmath>

#include<fstream>

using namespace std;
char a[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
map<char,char> mp;

string A(string s)
{
	int i;

	for(i=0;i<s.size();++i)
		if(s[i]!=' ')
			s[i]=mp[s[i]];
	
	return s;
}


void main()
{
	char t[1000];
	int i,j,num,row,col;
	vector<string> v,ret;
	ifstream fin("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\A\\A-small-attempt1.in");
	ofstream fout("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\A\\A-small.txt");

	for(i=0;i<26;++i)
		mp['a'+i]=a[i];
	
	fin>>num;
	fin.getline(t,1000);

	for(i=1;i<=num;++i)
	{
		fin.getline(t,1000);
		string s(t);

		fout<<"Case #"<<i<<": ";

		fout<<A(s)<<endl;
		
	}
}
