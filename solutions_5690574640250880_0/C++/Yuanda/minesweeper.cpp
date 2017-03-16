#include <iostream>
#include <string>

using namespace std;

int solve(int R, int C, int M, char m[50][50]);
void init(char m[50][50]);
void print(int result, int r, int R, int C, char m[50][50]);

int main()
{
    int n;
    int R;
    int C;
    int M;
    char m[50][50];
    int result;
    
    cin >> n;
    
    for(int r=0;r<n;r++)
    {
    	cin >> R >> C >> M;

    	init(m);
        result = solve(R,C,M,m);
        print(result, r+1, R, C, m);
    }
    return 0;
}

int solve(int R, int C, int M, char m[50][50])
{
	int result = 0;
	int remain = R*C-M;

	if(R==1 && M<C)
	{
		result = 1;
		for (int i = 0; i < C; ++i)
		{
			if(i<M) m[0][i] = '*';
			else if(i==C-1) m[0][i] = 'c';
			else m[0][i] = '.';
		}
	}
	else if(C==1 && M<R)
	{
		result = 1;
		for (int i = 0; i < R; ++i)
		{
			if(i<M) m[i][0] = '*';
			else if(i==R-1) m[i][0] = 'c';
			else m[i][0] = '.';
		}
	}
	else if(remain==1)
	{
		result = 1;
		m[0][0] = 'c';
	}
	else if((R==2 || C==2) && (remain%2)) result=0;
	else if(remain>=4 && remain!=5 && remain!=7)
	{
		result = 1;
		if(remain%2)
		{
			remain -= 9;
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if(i==0 && j==0) m[i][j]='c';
					else if(i<3 && j<3) m[i][j]='.';
					else if(i==0 && remain>0)
					{
						m[i][j]='.';
						m[i+1][j]='.';
						remain -= 2;
					}
					else if(remain==1 && j==0)
					{
						m[i][j]='.';
						m[i][j+1]='.';
						m[i-1][C-1]='*';
						remain--;
					}
					else if(remain>0 && m[i][j]!='.')
					{
						m[i][j]='.';
						remain--;
					}
					else if(m[i][j]!='.') m[i][j]='*';
				}
			}
		}
		else
		{
			remain -= 4;
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if(i==0 && j==0) m[i][j]='c';
					else if(i<2 && j<2) m[i][j]='.';
					else if(i==0 && remain>0)
					{
						m[i][j]='.';
						m[i+1][j]='.';
						remain -= 2;
					}
					else if(remain==1 && j==0)
					{
						m[i][j]='.';
						m[i][j+1]='.';
						m[i-1][C-1]='*';
						remain--;
					}
					else if(remain>0 && m[i][j]!='.')
					{
						m[i][j]='.';
						remain--;
					}
					else if(m[i][j]!='.') m[i][j]='*';
				}
			}
		}
	}

    return result;
}

void init(char m[50][50])
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			m[i][j]='*';
		}
	}
}

void print(int result, int r, int R, int C, char m[50][50])
{
     cout << "Case #" << r << ":\n";
     if (result==0)
     {
     	cout << "Impossible\n";
     } else
     {
     	for (int i = 0; i < R; ++i)
     	{
     		for (int j = 0; j < C; ++j)
     		{
     			cout << m[i][j];
     		}
     		cout << endl;
     	}
     }
}
