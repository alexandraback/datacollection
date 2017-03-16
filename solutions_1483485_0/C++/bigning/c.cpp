#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char d[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};



int main()
{
	ifstream fin("A-small-attempt3.in");
	ofstream fout("r.out");

	string s,r;
	int num=0;
	int n;
	fin>>n;
		getline(fin,s);
	for(int m=0;m<n;m++)
	{
	getline(fin,s);
		num++;
		r="";
		for(int k=0;k<s.size();k++)
		{
			if(s[k]==' ')
			{
				r=r+' ';
				continue;
			}
		
			r=r+d[s[k]-'a'];
		}

		if(m==n-1)
		{
			cout<<"Case #"<<m+1<<": "<<r;
		fout<<"Case #"<<m+1<<": "<<r;
		break;
		}

		cout<<"Case #"<<m+1<<": "<<r<<endl;
		fout<<"Case #"<<m+1<<": "<<r<<endl;
	}

	return 0;
}