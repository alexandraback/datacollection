#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

typedef long double num;

int main()
{
	int t;
	cin >> t;
	for(int tc=1;tc<=t;++tc)
	{
		cout << "Case #" << tc << ": ";
		int r,c,m;
		cin >> r >> c >> m;
		int o=r*c-m;
		
		if(o==1)
		{
			for(int i=0;i<r;++i)
			{
				for(int j=0;j<c;++j)
				{
					if(i==0 && j==0) cout << endl << 'c';
					else cout << '*';
				}
				cout << endl;
			}
		}
		else if(c==1)
		{
			cout << endl << "c" << endl;
			for(int i=1;i<o;++i)
				cout << "." << endl;
			for(int i=0;i<m;++i)
				cout << "*" << endl;
		}
		else if(r==1)
		{
			cout << endl << "c";
			for(int i=1;i<o;++i)
				cout << ".";
			for(int i=0;i<m;++i)
				cout << "*";
			cout << endl;
		}
		
		else if(c==2)
		{
			if(o==2 || m%2==1)
				cout << "Impossible" << endl;
			else
			{
				cout << endl << "c." << endl;
				for(int i=2;i<o;i+=2)
					cout << ".." << endl;
				for(int i=0;i<m;i+=2)
					cout << "**" << endl;
			}
		}
		else if(r==2)
		{
			if(o==2 || m%2==1)
				cout << "Impossible" << endl;
			else
			{
				cout << endl << "c";
				for(int i=2;i<o;i+=2)
					cout << ".";
				for(int i=0;i<m;i+=2)
					cout << "*";
				cout << endl << ".";
				for(int i=2;i<o;i+=2)
					cout << ".";
				for(int i=0;i<m;i+=2)
					cout << "*";
				cout << endl;
			}
		}
		
		else
		{
			if(o<4 || o==5 || o==7)
				cout << "Impossible" << endl;
			else
			{
				int cur=4;
				vector<vector<bool> > mat(r,vector<bool> (c,false));
				mat[0][0]=true;mat[0][1]=true;mat[1][0]=true;mat[1][1]=true;
				if(o>4)
				{
					cur=6;
					mat[0][2]=true;mat[1][2]=true;
					for(int i=2;i<r && o-cur>1;++i)
					{
						cur+=2;
						mat[i][0]=true;
						mat[i][1]=true;
					}
					for(int i=3;i<c && o-cur>1;++i)
					{
						cur+=2;
						mat[0][i]=true;
						mat[1][i]=true;
					}
					for(int i=2;i<r && o-cur>0;++i)
						for(int j=2;j<c && o-cur>0;++j)
						{
							cur++;
							mat[i][j]=true;
						}
				}
				
				for(int i=0;i<r;++i)
				{
					for(int j=0;j<c;++j)
					{
						if(i==0 && j==0) cout << endl << 'c';
						else if(mat[i][j]) cout << '.';
						else cout << '*';
					}
					cout << endl;
				}
			}
		}
	}
}
