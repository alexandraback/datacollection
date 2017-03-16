#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	ifstream fin;
	fin.open("A-small.in");
	ofstream fout;
	fout.open("Aans.txt");
	int T;
	fin>>T;
	fin.get();
	char c[200];
	int map[26]={25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17};
	for (int i=1;i<=T;i++)
	{
		fout<<"Case #"<<i<<": ";
		fin.getline(c,200);
		for (int j=0;j<strlen(c);j++)
		{
			if (c[j]==' ')
			{
				fout<<' ';
			}
			else
			{
				fout<<(char)(map[c[j]-'a']-1+'a');
			}
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}