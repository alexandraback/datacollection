#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream in("a.in");
ofstream out("a.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
string g[5];
int check(char person)
{
	int i, j, cnt;
	fo(i, 0, 3)
	{
		cnt=0;
		fo(j, 0, 3)
			cnt+=(g[i][j]==person)|(g[i][j]=='T');
		if (cnt==4)
			return 1;
	}
	fo(i, 0, 3)
	{
		cnt=0;
		fo(j, 0, 3)
			cnt+=(g[j][i]==person)|(g[i][j]=='T');
		if (cnt==4)
			return 1;
	}
	cnt=0;
	fo(i, 0, 3)
		cnt+=(g[i][i]==person)|(g[i][i]=='T');
	if (cnt==4)
		return 1;
	cnt=0;
	fo(i, 0, 3)
		cnt+=(g[i][3-i]==person)|(g[i][3-i]=='T');
	if (cnt==4)
		return 1;
	return 0;
}
int main()
{
	int t, i, j, k;
	in>>t;
	fo(i, 1, t)
	{
		fo(j, 0, 3)
			in>>g[j];
		int complete=1;
		fo(j, 0, 3)
			fo(k, 0, 3)
			if (g[j][k]=='.')
				complete=0;
		out<<"Case #"<<i<<": ";
		if (check('X'))
			out<<"X won"<<endl;
		else
			if (check('O'))
				out<<"O won"<<endl;
			else
				if (complete)
					out<<"Draw"<<endl;
				else
				out<<"Game has not completed"<<endl;
	}
}