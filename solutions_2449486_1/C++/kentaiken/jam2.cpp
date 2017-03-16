#include<iostream>
#include<fstream>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");
int n,m;
int field[100][100];
int k;
int tests;

string isPossible()
{
	int i,j;
	int k;
	
	int hor,ver;
	
	for(i =0  ; i < n; ++i)
	{
		for(j =0 ; j < m; ++j)
		{
			ver = true;
			for(k =0 ; k < n; ++k)
			{
				if(field[i][j] < field[k][j])
				{
					ver = false;
					break;
				}
			}
			if(ver) continue;
			
			hor = true;
			for(k =0 ; k < m; ++k)
			{
				if(field[i][j] < field[i][k])
				{
					hor = false;
					break;
				}
			}
			
			if(!hor) return "NO";
		}
	}
	
	return "YES";
}

int main()
{
	int i,j;
	input>>tests;
	
	for(k = 1; k <= tests; ++k)
	{
		input>>n>>m;
		
		for(i = 0; i < n; ++i)
			for(j =0 ; j < m; ++j)
				input>>field[i][j];
		
		output<<"Case #"<<k<<": "<<isPossible()<<"\n";
	}
	
	input.close();
	output.close();
	
	return 0;
}
		