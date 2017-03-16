#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int main ()
{
	int T;
	string G="",S="",str;

	ifstream cin;
	ofstream cout;

	cin.open("A-small-attempt0.in");
	cout.open("speaking.out");

	cin>>T;
	cin>>ws;
	for (int t=1; t<=T; t++)
	{
		getline(cin,str);
		istringstream lineiss(str);

		while (!lineiss.eof())
		{
			lineiss>>G;
			
			for (int i=0; i<G.size(); i++)
			{
				if (G[i]=='y')	G[i]='a';
				else if (G[i]=='n')	G[i]='b';
				else if (G[i]=='f')	G[i]='c';
				else if (G[i]=='i')	G[i]='d';
				else if (G[i]=='c')	G[i]='e';
				else if (G[i]=='w')	G[i]='f';
				else if (G[i]=='l')	G[i]='g';
				else if (G[i]=='b')	G[i]='h';
				else if (G[i]=='k')	G[i]='i';
				else if (G[i]=='u')	G[i]='j';
				else if (G[i]=='o')	G[i]='k';
				else if (G[i]=='m')	G[i]='l';
				else if (G[i]=='x')	G[i]='m';
				else if (G[i]=='s')	G[i]='n';
				else if (G[i]=='e')	G[i]='o';
				else if (G[i]=='v')	G[i]='p';
				else if (G[i]=='z')	G[i]='q';
				else if (G[i]=='p')	G[i]='r';
				else if (G[i]=='d')	G[i]='s';
				else if (G[i]=='r')	G[i]='t';
				else if (G[i]=='j')	G[i]='u';
				else if (G[i]=='g')	G[i]='v';
				else if (G[i]=='t')	G[i]='w';
				else if (G[i]=='h')	G[i]='x';
				else if (G[i]=='a')	G[i]='y';
				else if (G[i]=='q')	G[i]='z';
			}

			S=S+' '+G;
		}
		cout<<"Case #"<<t<<":"<<S<<endl;
		S="";
	}

	return 0;
}