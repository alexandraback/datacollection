#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char a[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char  c;
	int x,y,z;
	ifstream ifile;
	ifile.open("input3.txt");
	ofstream ofile;
	ofile.open("output3.txt");
	int t;
	int k=1;
	ifile>>t;
	ifile.get(c);
	while(t--)
	{
		ofile<<"Case #"<<k<<": ";
		ifile.get(c);
		while(c!='\n')
		{
			if(c>='a' && c<='z')
				c = a[c-'a'];
			ofile.put(c);
			ifile.get(c);
		}
		ofile.put('\n');
		k++;
	}
	ifile.close();
	ofile.close();
		
			
}
