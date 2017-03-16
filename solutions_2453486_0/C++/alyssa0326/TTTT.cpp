#include<cstdio>
#include<cstring>
using namespace std;
int matrix[4][4];
int col[4];
int row[4];
int diag1,diag2;
void run()
{
	char str[5];
	bool not_all = false;
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	memset(matrix,0,sizeof(matrix));
	diag2 = diag1 = 0;
	for (int i = 0 ;i < 4 ; i++)
	{
		gets(str);
		for (int j = 0 ;j < 4 ; j++)
		{
			if(str[j] == 'X')
				matrix[i][j] = -1;
			else if (str[j] == 'O')
				matrix[i][j]= 1;
			else if (str[j] =='T') 
				matrix[i][j] = 0;
			else
			{
				matrix[i][j] = 1000;
				not_all = true;
			}
			col[j] += matrix[i][j];
			row[i] += matrix[i][j];
			if (i==j)
				diag1 += matrix[i][j];
			if (i+j==3)
				diag2 += matrix[i][j];
		}
	}
	/*
	for (int i = 0 ;i < 4; i++,putchar('\n'))
		for (int j = 0 ;j < 4 ; j++)
			printf("%d ",matrix[i][j]);
			*/
	gets(str);
	bool xWin = false;
	bool oWin = false;
	for (int i = 0 ;i < 4;i ++)
	{
		if (row[i]==-3 || row[i] == -4 || col[i] == -4 || col[i] == -3)
			xWin = true;
		if (row[i]==3 || row[i] == 4 || col[i]==3 || col[i] == 4)
			oWin = true;
	}
	if (diag1==-3 ||diag1 == -4 ||  diag2==-3 || diag2 == -4)
		xWin = true;
	if (diag1 ==3 ||diag1 == 4 || diag2 == 4 || diag2 ==3)
		oWin = true;

	if (xWin)
	{
		printf("X won");
		return;
	}
	if (oWin)
	{
		printf("O won");
		return ;
	}
	if (not_all)
	{
		printf("Game has not completed");
		return;
	}
	printf("Draw");
}
int main()
{
	int N;
	scanf("%d\n",&N);
	for (int Case = 1 ; Case <= N ; Case++)
	{
		printf("Case #%d: ",Case);
		run();
		putchar('\n');
	}
	return 0;
}
