#include<iostream>
#include<cstring>

using namespace std;

bool tab[53][53];
int tab2[53][53];
int r,c,m;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
		cin >> r >> c >> m;
		memset(tab,0,sizeof(tab));
		memset(tab2,0,sizeof(tab2));
		bool C = false;
		for (int k = 0; k < (1<<(r*c)); k++)
		{
			C = false;
			int p = 0;
			if (__builtin_popcount(k) != m) continue;
			for (int i = 0; i < r*c; i++)
			{
				if (k&(1<<i)) tab[i/c+1][i%c+1] = 1;
				else tab[i/c+1][i%c+1] = 0;
			}
			
			for (int i = 1; i <= r; i++)
			{
				for (int j = 1; j <= c; j++)
				{
					//cout << tab[i][j];
					if (tab[i][j] == 0) p++;
				}
				//cout << "\n";
			}
			//cout << "\n";
			if (p == 1)
			{
				cout << "Case #" << l << ":\n";
				for (int i = 0; i < r*c; i++)
				{
					if (k&(1<<i)) cout << '*';
					else if (tab2[i/c+1][i%c+1] == 0 and !C) cout << 'c', C = true;
					else cout << '.';
					if (i%c == c-1) cout << "\n";
				}
				break;
			}
			
			for (int i = 1; i <= r; i++)
			{
				for (int j = 1; j <= c; j++)
				{
					tab2[i][j] = 0;
					if (tab[i][j]) {tab2[i][j] = -1; continue;}
					for (int x = -1; x <=1; x++)
					{
						for (int y = -1; y <=1; y++)
						{
							tab2[i][j] += tab[i+x][j+y];
						}
					}
				}
			}
			
			
			
			for (int i = 0; i <= c+1; i++) tab2[0][i] = tab2[r+1][i] = 1;
			for (int i = 0; i <= r+1; i++) tab2[i][0] = tab2[i][c+1] = 1;
			/*
			for (int i = 1; i <= r; i++)
			{
				for (int j = 1; j <= c; j++)
				{
					cout << tab2[i][j];
				}
				cout << "\n";
			}
			cout << "\n";
			*/
			int z = 0;
			for (int i = 1; i <= r; i++) 
			{
				for (int j = 1; j <= c; j++)
				{
					if (tab[i][j]) continue;
					if (tab2[i][j] == 0) z++;
				}
			}
			bool B = true;
			bool b = false;
			for (int i = 1; i <= r; i++) 
			{
				for (int j = 1; j <= c; j++)
				{
					if (tab[i][j]) continue;
					b = false;
					for (int x = -1; x <=1; x++)
					{
						for (int y = -1; y <=1; y++)
						{
							if (z > 1) if (x == 0 and y == 0) continue;
							b |= (tab2[i+x][j+y] == 0);
						}
					}
					B &= b;
				}
			}
			C = false;
			if (B)
			{
				cout << "Case #" << l << ":\n";
				for (int i = 0; i < r*c; i++)
				{
					if (k&(1<<i)) cout << '*';
					else if (tab2[i/c+1][i%c+1] == 0 and !C) cout << 'c', C = true;
					else cout << '.';
					if (i%c == c-1) cout << "\n";
				}
				break;
			}
		}
		if (!C) cout << "Case #" << l << ":\nImpossible\n";
	}


    //system("pause");
    return 0;
}
