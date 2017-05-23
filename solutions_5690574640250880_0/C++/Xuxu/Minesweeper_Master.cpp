#include<fstream>
using namespace std;

bool findAns(ofstream &fout,int x,int y,int r,int c,int count,int m)
{
	if (x<=r-2)
	{
		if (count + c - y+1 >= m)
		{
			if (c-y-m+count != 0)
			{
				for (int i=1;i<=r;++i)
				{
					for (int j=1;j<=c;++j)
						if (i<x || j<y ||(i == x && j < y+m-count))
							fout<<'*';
						else
						if (i < r || j < c)
							fout<<'.';
						else
							fout<<'c';
					fout<<endl;
				}
				return true;
			}
			else
			{
				if (r-x > 2 && c-y>1)
				{
					for (int i=1;i<=r;++i)
					{
						for (int j=1;j<=c;++j)
							if (i<x || j<y ||(i == x && j < c-1) || (i == x+1 && j == 1))
								fout<<'*';
							else
							if (i < r || j < c)
								fout<<'.';
							else
								fout<<'c';
						fout<<endl;
					}
					return true;
				}
			}
		}
		else
		{
			if (findAns(fout,x+1,y,r,c,count + c-y + 1,m))
				return true;
		}
	}
	if (y<=c-2)
	{
		if (count + r - x+1 >=m)
		{
			if (r-x-m+count != 0)
			{
				for (int i=1;i<=r;++i)
				{
					for (int j=1;j<=c;++j)
						if (i<x || j<y || (i < x+m-count && j == y))
							fout<<'*';
						else
						if (i<r || j<c)
							fout<<'.';
						else
							fout<<'c';
					fout<<endl;
				}
				return true;
			}
			else
			{
				if (c-y>2 && r-x>1)
				{
					for (int i=1;i<=r;++i)
					{
						for (int j=1;j<=c;++j)
							if (i<x || j<y || (i < r-1 && j == y) || (j == y+1 && i == 1))
								fout<<'*';
							else
							if (i<r || j<c)
								fout<<'.';
							else
								fout<<'c';
						fout<<endl;
					}
					return true;
				}
			}
		}
		else
		{
			if (findAns(fout,x,y+1,r,c,count + r-x + 1,m))
				return true;
		}
	}
	return false;
}

int main()
{
	ifstream fin("C-small-attempt4.in");
	ofstream fout("Minesweeper Master.out");
	int n;
	fin>>n;
	for (int k=0;k<n;++k)
	{
		int m,r,c;
		fin>>r>>c>>m;
		fout<<"Case #"<<k+1<<":"<<endl;
		if (m == r * c - 1)
		{
			for (int i=0;i<r;++i)
			{
				for (int j=0;j<c;++j)
					if (i != r-1 || j != c-1)
						fout<<'*';
					else
						fout<<'c';
				fout<<endl;
			}
		}
		else
		if (m == 0)
		{
			for (int i=0;i<r;++i)
			{
				for (int j=0;j<c;++j)
					if (i != r-1 || j != c-1)
						fout<<'.';
					else
						fout<<'c';
				fout<<endl;
			}
		}
		else
		if (!findAns(fout,1,1,r,c,0,m))
		{
			fout<<"Impossible"<<endl;
		}
	}
	return 0;
}