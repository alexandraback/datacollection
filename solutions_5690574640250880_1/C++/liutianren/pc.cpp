#include <iostream>
//#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

bool table[64][64];

void mine(unsigned int R, unsigned int C, unsigned int M)
{
	unsigned int F = R*C - M;
	
	bool rotated = (R>C);
	if(R>C)
	{
		unsigned int tmp = R;
		R = C;
		C = tmp;
	}

	for (int i=0; i<R; i++)
		for (int j=0; j<C; j++)
			table[i][j] = true;

	if(F == 1)
	{
		table[0][0] = false;
	}
	else if(R == 1)
	{
		for(int j=0; j<F; j++)
			table[0][j] = false;
	}
	else if(F > 2 && F%2 == 0 && F<=2*C)
	{
		for(int j=0; j<F/2; j++)
			table[0][j] = table[1][j] = false;
	}
	else if(R > 2)
	{
		if(F >= 8)
		{
			//unsigned int rF = F;
			unsigned int cW = R;
			//unsigned int fC = 0;
			if (F < 2*R+2)
				cW = (F-2)/2;
			for(int i=0; i<cW; i++)
				for(int j=0; j<(F/cW); j++)
					table[i][j] = false;
			unsigned int rF = F - (F/cW)*cW;
			for(int i=0; i<rF; i++)
				table[i][F/cW] = false;
			if(rF == 1)
			{
				table[1][F/cW] = false;
				table[cW-1][F/cW-1] = true;
			}
			//rF -= 2*cW;
			//fC = 2;
		}
	}

	if(table[0][0])
		cout<<"Impossible"<<endl;
	else if(!rotated)
	{
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				if(i==0 && j==0)
					cout<<'c';
				else if(table[i][j])
					cout<<'*';
				else
					cout<<'.';
			}
			cout<<endl;
		}
	}
	else
	{
		for(int i=0; i<C; i++)
		{
			for(int j=0; j<R; j++)
			{
				if(i==0 && j==0)
					cout<<'c';
				else if(table[j][i])
					cout<<'*';
				else
					cout<<'.';
			}
			cout<<endl;
		}	
	}
}

int main()
{
	int caseNum;
	cin >> caseNum;
	for(int t=1; t<=caseNum; t++)
	{
		unsigned int R,C,M;
		cin>> R>>C>>M;
		cout<<"Case #"<<t<<":"<<endl;
		mine(R,C,M);
	}
	return 0;
}