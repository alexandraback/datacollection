#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mineconfig(int, int, int);

int g_r_count = 0;
int g_c_count = 0;


int main()
{
	ifstream fin("C-small-attempt5.in");
	ofstream fout("res.txt");
	if(!fin.is_open() || !fout.is_open())
		return 0;
	
	string s;
	getline(fin, s);
	int t = atoi(s.c_str());
	for(int k = 0; k < t; k++)
	{
		int r, c, m;
		g_r_count = 0;
		g_c_count = 0;
		fin >> r;
		fin >> c;
		fin >> m;
		int res = mineconfig(r, c, m);
		int remain = 0;
		switch(res)
		{
		case -1:
			fout << "Case #" << k+1 << ":\n" << "Impossible\n";
			break;
		case 0:
			fout << "Case #" << k+1 << ":\n";
			remain = m - (r * c - (r - g_r_count) * (c - g_c_count));
			for(int i = 0; i < r; i++)
			{
				if(i < r - g_r_count)
				{
					for(int j = 0; j < c; j++)
					{
						if(i == 0 && j == 0)
						{
							fout << "c";
							continue;
						}
						if(j < c - g_c_count - 1)
						{
							fout <<".";
							continue;
						}
						if(j == c - g_c_count - 1)
						{
							if(i < r - g_r_count - remain)
							{
								fout << ".";
							}
							else
							{
								fout << "*";
							}
						}
						else
						{
							fout << "*";
						}
					}
				}
				else
				{
					for(int j = 0; j < c; j++)
					{
						fout << "*";
					}
				}
				fout << endl;
			}
			break;
		case 1:
			fout << "Case #" << k+1 << ":\n";
			remain = m - (r * c - (r - g_r_count) * (c - g_c_count));
			for(int i = 0; i < r; i++)
			{
				if(i < r - g_r_count - 1)
				{
					for(int j = 0; j < c; j++)
					{
						if(i == 0 && j == 0)
						{
							fout << "c";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout <<".";
						}
						else
						{
							fout << "*";
						}
					}
					fout << endl;
					continue;
				}
				if(i == r - g_r_count - 1)
				{
					for(int j = 0; j < c; j++)
					{
						if(j < c - g_c_count - remain)
						{
							fout << ".";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout << "*";
						}
						else
						{
							fout << "*";
						}
					}
				}
				else
				{
					for(int j = 0; j < c; j++)
					{
						fout << "*";
					}
				}
				fout << endl;
			}
			break;
		case 2:
			fout << "Case #" << k+1 << ":\n";
			for(int i = 0; i < r; i++)
			{
				if(i < r - g_r_count)
				{
					for(int j = 0; j < c; j++)
					{
						if(i == 0 && j == 0)
						{
							fout << "c";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout <<".";
						}
						else
						{
							fout << "*";
						}
					}
				}
				else
				{
					for(int j = 0; j < c; j++)
					{
						fout << "*";
					}
				}
				fout << endl;
			}
			break;
		case 3:
			fout << "Case #" << k+1 << ":\n";
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
				{
					if(i == 0 && j  == 0)
					{
						fout << "c";
					}
					else
					{
						fout << "*";
					}
				}
				fout << endl;
			}
			break;
		case 4:
			fout << "Case #" << k+1 << ":\n";
			remain = m - (r * c - (r - g_r_count) * (c - g_c_count));
			for(int i = 0; i < r; i++)
			{
				if(i < r - g_r_count - 2)
				{
					for(int j = 0; j < c; j++)
					{
						if(i == 0 && j == 0)
						{
							fout << "c";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout <<".";
						}
						else
						{
							fout << "*";
						}
					}
					fout << endl;
					continue;
				}
				if(i == r - g_r_count - 2)
				{
					for(int j = 0; j < c; j++)
					{
						if(j < c - g_c_count - 1)
						{
							fout << ".";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout << "*";
						}
						else
						{
							fout << "*";
						}
					}
					remain -= 1;
				}
				else if(i == r - g_r_count - 1)
				{
					for(int j = 0; j < c; j++)
					{
						if(j < c - g_c_count - remain)
						{
							fout << ".";
							continue;
						}
						if(j < c - g_c_count)
						{
							fout << "*";
						}
						else
						{
							fout << "*";
						}
					}
				}
				else
				{
					for(int j = 0; j < c; j++)
					{
						fout << "*";
					}
				}
				fout << endl;
			}
			break;
		default:
			break;
		}
	}
}

int mineconfig(int r, int c, int m)
{	
	if(m == r * c)
		return -1;
	if(r * c == m + 1)
		return 3;				// 3: only one grid without mine
	if(r == 1)
	{
		g_c_count = m;
		return 2;
	}
	if(c == 1)
	{
		g_r_count = m;
		return 2;
	}
	while(m >= r || m >= c)
	{
		if(r >= c)
		{
			r -= 1;
			m -= c;
			g_r_count++;
		}
		else
		{
			c -= 1;
			m -= r;
			g_c_count++;
		}
	}
	if(m != 0)
	{
		bool flag1 = (r == 2 || c == 2)? true : false;
		if(flag1)
		{
			return -1;
		}
		if(r != c)
		{
			int pos = (r > c)? r : c;
			bool flag2 =  (pos - m >= 2) ? true : false;
			if(!flag2)
			{
				return -1;
			}
			return (c >= r)? 1 : 0; // 1: c > r   0: c < r
		}
		if(r == c)
		{
			if(r == 3 && m == 2)
				return -1;
			bool flag3 =  (c - m >= 2) ? true : false;
			if(flag3)
			{
				return 1;
			}
			else
			{
				return 4;  // 4: remain mines lay on two lines.
			}
		}
	}
	else
	{
		if(r >= 2 && c >= 2)
			return 2;			// 2: no remaining mine and remain area larger than 2 * 2 grid
		else
			return -1;   
	}
}