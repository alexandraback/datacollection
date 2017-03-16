#include<iostream>
#include<fstream> 
#include <iomanip>
using namespace std;

int main()
{
	ifstream f1;
	ofstream f2;
	f1.open("E:\\code jam\\q3\\C-large.in");
	f2.open("E:\\code jam\\q3\\1.out");
	int n;
	f1>>n;
	int r,c,m,t,tempr,tempc;
	int i,j,p,q;
	int map[60][60];
	for (i=1;i<=n;i++)
	{
		f1>>r>>c>>m;
		if (r==1)
		{
			f2<<"Case #"<<i<<":"<<endl;
			for(j=0;j<m;j++) f2<<"*";
			for(j=m;j<c-1;j++) f2<<".";
			f2<<"c"<<endl;
			continue;
		}
		if (c==1)
		{
			f2<<"Case #"<<i<<":"<<endl;
			for(j=0;j<m;j++) f2<<"*"<<endl;
			for(j=m;j<r-1;j++) f2<<"."<<endl;
			f2<<"c"<<endl;
			continue;
		}
		if (r==2)
		{
			f2<<"Case #"<<i<<":"<<endl;
			if ((r*c-m)==1) 
			{
				for (j=0;j<c-1;j++) f2<<"*";
				f2<<"c"<<endl;
				for (j=0;j<c;j++) f2<<"*";
				f2<<endl;
			}
			else if ((r*c-m)%2==1) f2<<"Impossible"<<endl;
			if ((r*c-m)==2) f2<<"Impossible"<<endl;
			else if (m%2==0)
			{
				for (j=0;j<m/2;j++) f2<<"*";
				for (j=m/2;j<c-1;j++) f2<<".";
				f2<<"c"<<endl;
				for (j=0;j<m/2;j++) f2<<"*";
				for (j=m/2;j<c;j++) f2<<".";
				f2<<endl;
			}
			continue;
		} 
		if (c==2)
		{
			f2<<"Case #"<<i<<":"<<endl;
			if ((r*c-m)==1) 
			{
				for (j=0;j<r-1;j++) f2<<"**"<<endl;
				f2<<"*c"<<endl;
			}
			else if ((r*c-m)%2==1) f2<<"Impossible"<<endl;
			if ((r*c-m)==2) f2<<"Impossible"<<endl;
			else if ((r*c-m)%2==0)
			{
				for (j=0;j<m/2;j++) f2<<"**"<<endl;
				for (j=m/2;j<r-1;j++) f2<<".."<<endl;
				f2<<".c"<<endl;
			}
			continue;
		} 
		if ((r*c-m)==1) 
		{
			f2<<"Case #"<<i<<":"<<endl;
			for (p=0;p<r;p++)
			{
				for (q=0;q<c-1;q++)
				{
					f2<<"*";
				}
				if (p!=r-1)f2<<"*"<<endl;
				else f2<<"c"<<endl;
			}
			continue;
		}
		if ((r*c-m)==2 || (r*c-m)==3 || (r*c-m)==5 || (r*c-m)==7)
		{
			f2<<"Case #"<<i<<":"<<endl;
			f2<<"Impossible"<<endl;
			continue;
		}
		t=r*c-m;
		f2<<"Case #"<<i<<":"<<endl;
		for (p=0;p<r;p++)
			for (q=0;q<c;q++)
				map[p][q]=0;
		tempr=0;tempc=0;
		while (m>0)
		{
			if(tempr<r-3)
			{
				if ( (tempc==c-2) && (m==1) )
				{
					map[tempr+1][0]=1;
					break;
				}
				if (tempc<c) 
				{
					map[tempr][tempc]=1;
					tempc++;
					m--;
				}
				else
				{
					tempr++;
					tempc=0;
					if (tempr>=r-3) continue;
					map[tempr][tempc]=1;
					tempc++;
					m--;
				}
			}
			else
			{
				if (m>=3)
				{
					map[r-3][tempc]=1;
					map[r-2][tempc]=1;
					map[r-1][tempc]=1;
					tempc++;
					m=m-3;
				}
				if (m==2)
				{
					map[r-3][tempc]=1;
					map[r-3][tempc+1]=1;
					m=m-2;
				}
				if (m==1)
				{
					map[r-3][tempc]=1;
					m=m-1;
				}
			}
		}
		map[r-1][c-1]=2;
		for (p=0;p<r;p++)
		{
			for(q=0;q<c;q++)
			{
				if (map[p][q]==0) f2<<".";
				if (map[p][q]==1) f2<<"*";
				if (map[p][q]==2) f2<<"c";
			}
			f2<<endl;
		}
	}
}
