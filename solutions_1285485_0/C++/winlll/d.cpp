#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("d.in");
	ofstream fout;
	fout.open("d.out");
	int tc,round,h,w,d,i,j,x,y,u,v,tot,s;
	int xx[50000],yy[50000];
	bool flag;
	string st;

	fin>>tc;
	for (round=0;round<tc;round++)
	{
		fin>>h>>w>>d;
		getline(fin,st);
		for (i=0;i<h;i++)
		{
			getline(fin,st);
			for (j=0;j<w;j++)
				if (st[j]=='X')
				{
					x=i;y=j;
				}
		}
		d=d*2;
		h=(h-2)*2;
		w=(w-2)*2;
		x=x*2-1;
		y=y*2-1;
		tot=0;
		for (i=-d;i<d;i++)
			for (j=-d;j<d;j++)
			{
				if (i==0 && j==0) continue;
				if (i%2==0)
					u=h*i;
				else
					u=h*i+(h-x-x);
				if (j%2==0)
					v=w*j;
				else
					v=w*j+(w-y-y);
				if (u*u+v*v<=d*d)
				{
					flag=true;
					for (s=0;s<tot;s++)
						if (xx[s]*v==yy[s]*u)
						{
							if ((xx[s]*u>0 || xx[s]==0 && u==0) && (yy[s]*v>0 || yy[s]==0 && v==0))
								flag=false;
						}
					if (flag)
					{
						xx[s]=u;
						yy[s]=v;
						tot++;
					}
				}
			}
		fout<<"Case #"<<round+1<<": "<<tot<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}