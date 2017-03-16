#include<fstream>
#include<cstring>
using namespace std;
int T,n;
char s[110];
char lit[30];

inline void SetareAlfabet()
{
	lit[0]='y';
	lit[1]='h';
	lit[2]='e';
	lit[3]='s';
	lit[4]='o';
	lit[5]='c';
	lit[6]='v';
	lit[7]='x';
	lit[8]='d';
	lit[9]='u';
	lit[10]='i';
	lit[11]='g';
	lit[12]='l';
	lit[13]='b';
	lit[14]='k';
	lit[15]='r';
	lit[16]='z';
	lit[17]='t';
	lit[18]='n';
	lit[19]='w';
	lit[20]='j';
	lit[21]='p';
	lit[22]='f';
	lit[23]='m';
	lit[24]='a';
	lit[25]='q';
}

int main()
{
	int i,t;
	SetareAlfabet();
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin>>T;
	fin.getline(s,110);
	for(t=1;t<=T;t++)
	{
		fin.getline(s,110);
		n=strlen(s);
		fout<<"Case #"<<t<<": ";
		for(i=0;i<n;i++)
		{
			if(s[i]==' ')
				fout<<' ';
			else
				fout<<lit[s[i]-'a'];
		}
		fout<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
