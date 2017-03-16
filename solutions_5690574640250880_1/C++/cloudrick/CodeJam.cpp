// CodeJam.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<set>
#include<iomanip>
#include<cstdio>
#include<vector>

using namespace std;

void A();
void B();
void C();
void D();

int main()
{
	//A();
	//B();
	C();
	//D();
	return 0;
}

void A()
{
	int cases = 0;
	set<int> myset;
	set<int> myset_e;

	cin >> cases;

	for(int n = 1 ; n<=cases ; ++n)
	{
		cout << "Case #" << n << ": ";

		int line = 0;
		int num[16] = {0};
		cin >> line;
		for(int i=0; i<16; ++i){ cin >> num[i];}

		myset.insert( num[(line-1)*4]);
		myset.insert( num[(line-1)*4+1]);
		myset.insert( num[(line-1)*4+2]);
		myset.insert( num[(line-1)*4+3]);

		cin >> line;
		for(int i=0; i<16; ++i){ cin >> num[i];}
		
		for(int i=0; i<4 ; ++i)
		{
			if(myset.find(num[(line-1)*4+i])!=myset.end())
			{
				myset_e.insert(num[(line-1)*4+i]);
			}
		}
		
		if(myset_e.size() == 1)
		{
			cout << *(myset_e.begin()) << endl;
		}
		else if(myset_e.size() == 0)
		{
			cout << "Volunteer cheated!" << endl;
		}
		else
		{
			cout << "Bad magician!" << endl;
		}
		myset.clear();
		myset_e.clear();
	}
}

void B()
{
	int cases = 0;

	cin >> cases;
	for(int n = 1 ; n<=cases ; ++n)
	{
		double c = 0.0L;
		double f = 0.0L;
		double x = 0.0L;
		double sec = 0.0L;
		double out = 2.0;

		cin >> c >> f >> x;
		while( (c/out+x/(out+f)) < x/out )
		{
			sec += c/out;
			out += f;          
		}
		sec += x/out;

		printf("Case #%d: %.7lf\n", n, sec);
		//cout << "Case #" << n << ": " << setprecision(7) << sec << endl;
	}
}


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

void C()
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

		//if(R>=2 && C>=2 && M>R*C-4)
		//{
		//	cout << "Impossible" << endl;
		//	continue;
		//}

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

		/*for(int r=0; r<R; ++r)
		{
			for(int c=0; c<C ; ++c)
			{
				if(map[r][c]==1)
					cout << '*';
				else if(map[r][c]==0)
					cout << '.';
			}
			cout << endl;
		}
*/
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
}

void D()
{
	/*
	int cases = 0;
	cin >> cases;

	for(int n = 1 ; n<=cases ; ++n)
	{
		//cout << "Case #" << n << ": ";

		int num_woods = 0;
		cin >> num_woods;

		vector<double> Naomi;
		vector<double> Ken;

		Naomi.resize(num_woods, 0);
		for(int i=0; i<num_woods; ++i)
		{
			cin >> Naomi[i];

			int j=i;
			for( j=i ; j>0 && Naomi[j-1] > Naomi[j]; --j)
			{
				swap(Naomi[j-1], Naomi[j]);
			}
		}

		Ken.resize(num_woods, 0);
		for(int i=0; i<num_woods; ++i)
		{
			cin >> Ken[i];

			int j=i;
			for( j=i ; j>0 && Ken[j-1] > Ken[j]; --j)
			{
				swap(Ken[j-1], Ken[j]);
			}
		}

		vector<double> Calc(Ken);
		
		int non_deceitful_ken_win = num_woods;

		for(int i=0; i<num_woods ; ++i)
		{
			bool is_ken_win = false;
			for(int j=0; j<num_woods; ++j)
			{
				if(Calc[j] > Naomi[i])
				{
					Calc[j] = -1;
					is_ken_win = true;
					break;
				}
			}

			if(!is_ken_win)
			{
				--non_deceitful_ken_win;
				for(int j=0; j<num_woods; ++j)
				{
					if(Calc[j]>=0.0)
					{
						Calc[j] = -1;
						break;
					}
				}
			}
		}

		int deceitful_ken_win = num_woods;
		
		int i_l = 0;
		int i_r = num_woods - 1 ;
		int j_l = 0;
		int j_r = num_woods - 1 ;

		while(true)
		{
			if(Naomi[i_l] < )
		}
		cout << "Case #" << n << ": " << 0 << " " << num_woods-non_deceitful_ken_win << endl;

	}
	*/
}