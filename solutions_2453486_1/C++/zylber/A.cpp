#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int tc;
	cin >> tc;
	
	for(int nt=1; nt<=tc; nt++)
	{
		string tab[4];
		for(int i=0; i<4; i++)
			cin >> tab[i];
		
		int status=0;
			
		for(int i=0; i<4; i++)
				for(int j=0; j<4; j++)
					if(tab[i][j]=='.')
						status=1;
		
		for(int i=0; i<4; i++)
		{
			int wonx=1, wony=1;
			for(int j=0; j<4; j++)
			{
				if(tab[i][j]=='.')
				{
					wonx=0;
					wony=0;
				}
				
				if(tab[i][j]=='X')
				{
					wony=0;
				}
				
				if(tab[i][j]=='O')
				{
					wonx=0;
				}
			}
			if(wonx)
				status=2;
			if(wony)
				status=3;
		}
		
		for(int j=0; j<4; j++)
		{
			int wonx=1, wony=1;
			for(int i=0; i<4; i++)
			{
				if(tab[i][j]=='.')
				{
					wonx=0;
					wony=0;
				}
				
				if(tab[i][j]=='X')
				{
					wony=0;
				}
				
				if(tab[i][j]=='O')
				{
					wonx=0;
				}
			}
			if(wonx)
				status=2;
			if(wony)
				status=3;
		}
			int wonx=1, wony=1;
			for(int i=0; i<4; i++)
			{
				if(tab[i][i]=='.')
				{
					wonx=0;
					wony=0;
				}
				
				if(tab[i][i]=='X')
				{
					wony=0;
				}
				
				if(tab[i][i]=='O')
				{
					wonx=0;
				}
			}
			if(wonx)
				status=2;
			if(wony)
				status=3;
				
			wonx=1, wony=1;
			for(int i=0; i<4; i++)
			{
				if(tab[i][3-i]=='.')
				{
					wonx=0;
					wony=0;
				}
				
				if(tab[i][3-i]=='X')
				{
					wony=0;
				}
				
				if(tab[i][3-i]=='O')
				{
					wonx=0;
				}
			}
			if(wonx)
				status=2;
			if(wony)
				status=3;
		
		cout << "Case #" << nt << ": ";
		
		if(status==0)
			cout << "Draw";
		if(status==1)
			cout << "Game has not completed";
		if(status==2)
			cout << "X won";
		if(status==3)
			cout << "O won";
		
		cout << endl;
	}
}
