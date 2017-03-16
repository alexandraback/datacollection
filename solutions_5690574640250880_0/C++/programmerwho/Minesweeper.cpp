#include<fstream>
using namespace std;
int main()
{
	int case_number;
	ifstream ifs("C-small-attempt5.in");
	ofstream ofs("out.txt");
	int r;
	int c;
	int mines;
	int rest;
	int remain;
	int flag;
	int line;
	char table[100][100];
	ifs>>case_number;
	for(int cases = 1; cases <= case_number; cases ++)
	{
		ofs<<"Case #"<<cases<<": "<<endl;
		ifs>>r>>c>>mines;
		flag = 0;
		rest = r*c-mines;
		for(int i = 0; i!= r; i++)
		{
			for(int j = 0;j!=c;j++)
			{
				table[i][j] = '*';
			}
		}
		for(int size =2; size<=r; size++)
		{
			remain = rest % size;
			line = rest / size;
			if(line > c ||(line == c && remain != 0))
				continue;
			if( (remain >= 2 || remain == 0)&& line >= 2 )
			{
				flag = 1;
				for(int i = 0; i!= size; i++)
				{
					for(int j = 0; j != line; j++)
					{
						table[i][j] = '.';
					}
				}
				for(int i = 0 ;i!=remain;i++)
				{
					table[i][line] = '.';
				}
				table[0][0]='c';
				break;
			}
			if(remain == 1 && size>=3 && line >= 3 && line<c)
			{
				flag = 1;
				for(int i = 0; i!= size; i++)
				{
					for(int j = 0; j != line-1; j++)
					{
						table[i][j] = '.';
					}
				}
				for(int i = 0 ;i!=size-1; i++)
				{
					table[i][line-1]='.';
				}
				table[0][line]='.';
				table[1][line]='.';
				table[0][0]='c';
				break;
			}
		}
		if(flag == 1)
		{
			for(int i =0; i!=r; i++)
			{
				for(int j = 0;j!=c;j++)
				{
					ofs<<table[i][j];
				}
				ofs<<endl;
			}
			continue;
		}
		for(int size =2; size <= c; size++)
		{
			remain = rest % size;
			line = rest / size;
			if(line > r||(line ==r && remain != 0))
				continue;
			if( (remain >= 2 || remain == 0)&& line >= 2 )
			{
				flag = 1;
				for(int i = 0; i!= size; i++)
				{
					for(int j = 0; j != line; j++)
					{
						table[j][i] = '.';
					}
				}
				for(int i = 0 ;i!=remain;i++)
				{
					table[line][i] = '.';
				}
				table[0][0]='c';
				break;
			}
			if(remain == 1 && size>=3 && line >= 3 && line<c)
			{
				flag = 1;
				for(int i = 0; i!= size; i++)
				{
					for(int j = 0; j != line-1; j++)
					{
						table[j][i] = '.';
					}
				}
				for(int i = 0 ;i!=size-1; i++)
				{
					table[line-1][i]='.';
				}
				table[line][0]='.';
				table[line][1]='.';
				table[0][0]='c';
				break;
			}
		}

		if(r == 1)
		{
			flag=1;
			for(int i = 0;i!=rest;i++)
			{
				table[0][i] = '.';
			}
			table[0][0]='c';
		}
		if(c == 1)
		{
			flag=1;
			for(int i = 0;i!=rest;i++)
			{
				table[i][0] = '.';
			}
			table[0][0]='c';
		}
		if(rest == 1)
		{
			table[0][0] = 'c';
			flag =1;
		}
		if(flag == 1)
		{
			for(int i =0; i!=r; i++)
			{
				for(int j = 0;j!=c;j++)
				{
					ofs<<table[i][j];
				}
				ofs<<endl;
			}
		}
		else
			ofs<<"Impossible"<<endl;
	}
}