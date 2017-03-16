// CodeJam.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<set>
#include<iomanip>
#include<cstdio>
#include<vector>

using namespace std;

enum E_MINE_RESULT
{
 MINE_WORK, MINE_IMPOSSBLE, MINE_FOUND
};

E_MINE_RESULT check_mine(int safe, int non_M)
{
	if(non_M == safe)
	{
		return MINE_FOUND;
	}
	else if(non_M > safe)
	{
		return MINE_IMPOSSBLE;
	}
	return MINE_WORK;
}

int main()
{
	int cases = 0;
	cin >> cases;

	for(int n = 1 ; n<=cases ; ++n)
	{
		cout << "Case #" << n << ":" << endl;

		int R = 0;
		int C = 0;
		int M = 0;
		
		cin >> R >> C >> M;
		int safe = R*C - M;

		int **map = new int*[R];
		for(int r=0; r<R; ++r)
		{
			map[r] = new int[C];
			for(int c=0; c<C; ++c)
			{
				map[r][c] = 1;
			}
		}

		int non_M = 1;
		map[0][0] = 0;

		if(check_mine(safe, non_M)==MINE_WORK && R>=2 && C>=2)
		{
			map[0][1] = map[1][0] = map[1][1] = 0;
			non_M += 3;
		}

		int work_r = (R>=2?1:0);
		int work_c = (C>=2?1:0);

		for(;;)
		{
			if(check_mine(safe, non_M)!=MINE_WORK)
				break;

			if(map[0][work_c]!=0)
			{
				map[0][work_c] = 0;
				++non_M;
			}


			for(int i=1; (i<work_r) || (R==2 && i==1); ++i)
			{
				if(map[i][work_c]!=0)
				{
					map[i][work_c] = 0;
					++non_M;
				}
				
				if(check_mine(safe, non_M)!=MINE_WORK)
				{
					if(check_mine(safe, non_M)==MINE_IMPOSSBLE && i==1 && safe == non_M-1)
					{
						int wr = work_r;
						int wc = work_c;
						if(wr==wc)
						{
							--wr;
							--wc;
						}
						else if(wr<wc)
						{
							--wc;
						}
						else if(wr>wc)
						{
							--wr;
						}

						if(wr>=2 && wc>=2)
						{
							map[wr][wc] = 1;
							--non_M;
						}
					}
					break;
				}
			}
			

			if(check_mine(safe, non_M)!=MINE_WORK)
				break;

			if(map[work_r][0]!=0)
			{
				map[work_r][0] = 0;
				++non_M;
			}

			for(int i=1; (i<work_c) || (C==2 && i==1); ++i)
			{
				if(map[work_r][i]!=0)
				{
					map[work_r][i] = 0;
					++non_M;
				}
				if(check_mine(safe, non_M)!=MINE_WORK)
				{
					if(check_mine(safe, non_M)==MINE_IMPOSSBLE && i==1 && safe == non_M-1)
					{
						int wr = work_r - 1;
						int wc = work_c;

						if(wr>=2 && wc>=2)
						{
							map[wr][wc] = 1;
							--non_M;
						}
					}
					break;
				}
			}

			if(check_mine(safe, non_M)!=MINE_WORK)
				break;

			if(map[work_r][work_c]!=0)
			{
				map[work_r][work_c] = 0;
				++non_M;
			}

			if(check_mine(safe, non_M)!=MINE_WORK)
				break;

			work_r = min(work_r+1, R-1);
			work_c = min(work_c+1, C-1);
		}

		if(check_mine(safe, non_M)==MINE_IMPOSSBLE)
			cout << "Impossible" << endl;
		else
		{
			for(int r=0; r<R; ++r)
			{
				for(int c=0; c<C ; ++c)
				{
					if(r==0 && c==0)
						cout << 'c';
					else if(map[r][c]==1)
						cout << '*';
					else if(map[r][c]==0)
						cout << '.';
				}
				cout << endl;
			}
		}

		for(int r=0; r<R; ++r)
		{
			delete [] map[r];
		}
		delete [] map;
	}
	
	return 0;
}
