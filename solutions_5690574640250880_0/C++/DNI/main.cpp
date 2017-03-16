#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;



int n, m, k;

char matr[1000][1000];
char matr2[1000][1000];

bool chack_m[1000][1000];


void Chack2(int x, int y, char matr[1000][1000] )
{
	if(!chack_m[x][y])
	{
		chack_m[x][y] = true;
		bool bCanRec = true;
		for(int i = -1; i <= 1; i++)
		{
			for(int j = -1; j <= 1; j++)
			{
				int xx = x + i;
				int yy = y + j;
				if(xx >= 0 && xx < n && yy >=0 && yy < m)
				{
					if(matr[xx][yy] == '*')
					{
						bCanRec = false;
						break;
					}
				}
			}
		}

		if(bCanRec)
		{
			for(int i = -1; i <= 1; i++)
			{
				for(int j = -1; j <= 1; j++)
				{
					int xx = x + i;
					int yy = y + j;
					if(xx >= 0 && xx < n && yy >=0 && yy < m)
					{
						Chack2(xx, yy, matr);
					}
				}
			}
		}
	}
}

bool Chack(int x, int y, char matr[1000][1000])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			chack_m[i][j] = false;
		}
	}
	Chack2(x, y, matr);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(chack_m[i][j] == false && matr[i][j] != '*')
				return false;
		}
	}
	return true;
}


bool TryP(int x, int y, int k)
{
	if(x == n-1 && y == m)
	{
		if(k == 0)
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(matr[i][j] == '.' && Chack(i, j, matr))
					{
						matr[i][j] = 'c';
						//cout << endl <<i << " " << j << endl;
						return true;
					}
		}
		return false;
	}
	else
	{
		if(y == m)
		{
			y = 0;
			x = x+1;
		}

		matr[x][y] = '.';
		if(k > 0)
		{
			matr[x][y] = '*';
			if(TryP(x, y+1, k-1))
				return true;
			matr[x][y] = '.';
		}
		return TryP(x, y+1, k);
	}
	return false;
}



bool TryOld()
{
	bool b  = true;
	int k = ::k;
	matr2[0][0] = '.';
	matr2[1][1] = '.';

	for(int z = m+n; z >= 0; z--)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(i + j == z && !(i == 1 && j == 1) && !(i == 0 && j == 0) /*&& !(i == 1 && j == 0) && !(i == 0 && j == 1)*/)
				{
					if(k > 0)
					{
						matr2[i][j] = '*';
						k--;
					}
					else
					{
						matr2[i][j] = '.';
					}
				}

	if(k > 0)
	{
		k--;
		matr2[1][1]='*';
	}


	if(k == 0)
	{
		b = Chack(0, 0, matr2);
		
		//bool bMastAll = false;
		//for(int i = 0; i < 2 && i < n; i++)
		//	for(int j = 0; j < 2 && j < m; j++)
		//		if(!(i == 0 && j == 0) && matr2[i][j] == '*')
		//			bMastAll = true;
		//if(bMastAll)
		//	for(int i = 0; i < 2 && i < n; i++)
		//		for(int j = 0; j < 2 && j < m; j++)
		//			if(!(i == 0 && j == 0) && matr2[i][j] != '*')
		//				b = false;

	}

	else
		b = false;
	matr2[0][0] = 'c';
	return b;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{


		cin >> n >> m >> k;
		//bool b = TryOld();
		bool b =  TryP(0, 0, k);
	/*	bool bOld = TryOld();
		
		if(b != bOld)
		{
			cout << "error" << endl;
			if(false)
			{
				printf("Case old #%d:\nImpossible\n", tt+1);
			}
			else
			{
				printf("Case old #%d:\n", tt+1);
				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < m; j++)
					{
						cout << matr2[i][j] << " ";
					}
					cout << endl;
				}
			}
		}*/

		if(!b)
		{
			printf("Case #%d:\nImpossible\n", tt+1);
			
		}
		else
		{
			int r1 = 0;
			int r2 = 0;
			int r3 = 0;
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(matr[i][j] == '*')
						r1++;
					else if(matr[i][j] == '.')
						r2++;
					else if(matr[i][j] == 'c')
						r3++;
					else
						cout << "WTF?" << endl;
				}
			}
			if(r1 != k)
				cout << "WTF?" << endl;
			if(r2 != n*m-1-k)
				cout << "WTF?" << endl;
			if(r3 != 1)
				cout << "WTF?" << endl;

			printf("Case #%d:\n", tt+1);
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					cout << matr[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}

