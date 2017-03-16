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

int intlen(int x)
{
	if(x<10)return 1;
	int i;
	for(i=1;i<7;i++)
	{
		x/=10;
		if(x==0)break;
	}
	return i;
}

int main(int argc, char *argv[])
{
//readin file
	string file;
	if(argc!=2){cerr<<"0,1 or 2!"<<endl;exit(1);}
	switch(atoi(argv[1]))
	{
		case 0: file="test"; break;
		case 1: file="C-small"; break;
		case 2: file="C-large"; break;
		default: cerr<<"choose the correct file, 0(test),1(small),2(large)"<<endl;exit(1); break;
	}
	string ifilename=file+".in"; string ofilename=file+".out";
	ifstream input(ifilename.c_str());ofstream output(ofilename.c_str());

//read in number of events
	int T;
	input>>T;
	int A,B;

//main loop start
	for(int t=0;t<T;t++)
	{
		int y=0;
		input>>A>>B;
		for(int n=A;n<B;n++)
		{
			if(n<10)continue;
			int l=intlen(n);
			int f=1;
			int F=1;
			for(int i=1;i<=l;i++)F*=10;
			set<int> ss;
			for(int i=1;i<l;i++)
			{
				f*=10;
				int x=n/f;
				int b=n%f;
				int m = x+b*F/f;
//				cout<<m<<endl;
				if(m<=B && m>n)
				{
					if(ss.find(m)==ss.end())
					{
						y++;
						ss.insert(m);
					}
				}
			}
		}

		output<<"Case #"<<t+1<<": "<<y<<endl;
		cout<<"case : "<<t+1<<": "<<y<<endl;
	}

	input.close();
	output.close();
	return 0;
}
