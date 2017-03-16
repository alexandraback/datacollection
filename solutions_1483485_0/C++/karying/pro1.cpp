#include <iostream>
#include <fstream>
#define  MAXLEN 150
using namespace std;

int main()
{
	char map[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v','x' , 'd', 'u', 'i', 'g', 'l', 'b','k', 'r', 'z' ,'t', 'n', 'w','j', 'p', 'f' , 'm' , 'a', 'q'};
	char data[MAXLEN];
	int i,j,n;
	ifstream input("A-small-attempt0.in");
	ofstream output("ans.out");
	while (input>>n)
	{
		input.getline(data , MAXLEN,'\n');
		for(i=1;i<=n;i++)
		{
			input.getline(data , MAXLEN , '\n');
			output<<"Case #"<<i<<": ";
			for(j=0;data[j]!=0;j++)
			{
				if(data[j]!=' ')
					output<<map[data[j]-'a'];
				else
					output<<" ";
			}
			output<<endl;
		}
	}
	return 1;
}
