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

int main(int argc, char *argv[])
{
//readin file
	string file;
	if(argc!=2){cerr<<"0,1 or 2!"<<endl;exit(1);}
	switch(atoi(argv[1]))
	{
		case 0: file="test"; break;
		case 1: file="B-small"; break;
		case 2: file="B-large"; break;
		default: cerr<<"choose the correct file, 0(test),1(small),2(large)"<<endl;exit(1); break;
	}
	string ifilename=file+".in"; string ofilename=file+".out";
	ifstream input(ifilename.c_str());ofstream output(ofilename.c_str());

//read in number of events
	int T;
	input>>T;
	int N,S,P;

//main loop start
	for(int t=0;t<T;t++)
	{
		int y=0;
		int a=0;
		input>>N>>S>>P;
		if(P==0)
		{
			for(int i=0;i<N;i++)
			{
				int x; input>>x;
			}
			y=N;
		}
		else{
			for(int i=0;i<N;i++)
			{
				int x;
				input>>x;
				if(x>=3*P-2)y++;
				if(x<3*P-2 && x>=((P==1)?1:(3*P-4)))a++;
			}
			y += min(a,S);
		}

		output<<"Case #"<<t+1<<": "<<y<<endl;
		cout<<"case : "<<t+1<<endl;
	}

	input.close();
	output.close();
	return 0;
}
