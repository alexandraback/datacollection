#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct MyPoint
{
	int x;
	int y;
};

bool assume(char **c_map,int r,int c,int m_left,int x,int y,int total)
{
	char record=c_map[x][y];
	c_map[x][y]='.';
	if (record=='*')
	{
		m_left--;
	}
	vector<MyPoint> pts;
	for (int i=x-1;i<=x+1;i++)
	{
		for (int j=y-1;j<=y+1;j++)
		{
			if (i>=0 && j>=0 && i<r && j<c && c_map[i][j]=='*')
			{
				c_map[i][j]='n';
				MyPoint temp;
				temp.x=i;temp.y=j;
				pts.push_back(temp);
				m_left--;
			}
		}
	}
	if (m_left<total)
	{
		for (int i=0;i<pts.size();i++)
		{
			c_map[pts[i].x][pts[i].y]='*';
		}
		c_map[x][y]=record;
		return false;
	}
	else if(m_left==total)
	{
		return true;
	}
	else
	{
		bool ok=false;
		for (int i=x-1;i<=x+1;i++)
		{
			for (int j=y-1;j<=y+1;j++)
			{
				if (i>=0 && j>=0 && i<r && j<c && c_map[i][j]=='n')
				{
					ok=assume(c_map,r,c,m_left,i,j,total);
					if (ok==true)
					{
						break;
					}
				}
			}
			if (ok==true)
			{
				break;
			}
		}
		if (ok==false)
		{
			for (int i=0;i<pts.size();i++)
			{
				c_map[pts[i].x][pts[i].y]='*';
			}
			c_map[x][y]=record;
		}
		return ok;
	}
}

bool click(char **c_map,int r,int c,int total,int i,int j)
{
	if (total==r*c-1)
	{
		c_map[i][j]='n';
		return true;
	}
	return assume(c_map,r,c,r*c,i,j,total);
}

int main()
{
	int num_data;
	ifstream infile("C-small-attempt3.in");
	ofstream outfile("3result.txt");
	infile>>num_data;
	for (int i=0;i<num_data;i++)
	{
		int r,c,m;
		infile>>r>>c>>m;
		char **c_map=new char *[r];
		for (int j=0;j<r;j++)
		{
			c_map[j]=new char[c];
			for (int k=0;k<c;k++)
			{
				c_map[j][k]='*';
			}
		}
		bool ok=false;
		for (int j=0;j<r;j++)
		{
			for (int k=0;k<=c/2;k++)
			{
				if (click(c_map,r,c,m,j,k)==true)
				{
					ok=true;
					c_map[j][k]='c';
					break;
				}
			}
			if (ok==true)
			{
				break;
			}
		}
		outfile<<"Case #"<<i+1<<":"<<endl;
		if (ok==true)
		{
			for (int j=0;j<r;j++)
			{
				for (int k=0;k<c;k++)
				{
					if (c_map[j][k]=='n')
					{
						outfile<<'.';
					}
					else outfile<<c_map[j][k];
				}
				outfile<<endl;
			}
		}
		else
			outfile<<"Impossible"<<endl;
		for (int j=0;j<r;j++)
		{
			delete []c_map[j];
		}
		delete []c_map;
	}
	outfile.close();
	infile.close();
	return 0;
}