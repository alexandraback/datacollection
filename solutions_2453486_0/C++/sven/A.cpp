#include <iostream>
#include <vector>
#include <cassert>
#define X 4

using namespace std;

int solve(int T);
int calculate(char A, int *target);
int judge(int target);

int main()
{
	int T;
	cin >> T;
	for(int i=1; i<=T; i++)
		switch(solve(i))
		{
			case 0:
				cout << "Draw" << endl;
				break;
			case -1:
				cout << "Game has not completed" << endl;
				break;
			case 1:
				cout << "O won" << endl;
				break;
			case 2:
				cout << "X won" << endl;
				break;
		}
}

int solve(int T)
{
	cout << "Case #" << T << ": ";
	vector <vector <char> > A;
	A.resize(X);
	for(int i=0; i<X; i++)
		A[i].resize(X); // reserve

	for(int i=0; i<X; i++)
		for(int j=0; j<X; j++)
		{
			char temp;
			cin >> temp;
			A[i][j] = temp;
		}

	for(int i=0; i<X; i++)
	{
		int flag = 0;
		for(int j=0; j<X; j++)
			calculate(A[i][j], &flag);
		if(judge(flag))
			return judge(flag);
	}
	for(int i=0; i<X; i++)
	{
		int flag = 0;
		for(int j=0; j<X; j++)
			calculate(A[j][i], &flag);
		if(judge(flag))
			return judge(flag);
	}

	int flag = 0;
	for(int i=0; i<X; i++)
		calculate(A[i][i], &flag);
	if(judge(flag))
		return judge(flag);
	
	flag = 0;
	for(int i=0; i<X; i++)
		calculate(A[i][X-i-1], &flag);
	if(judge(flag))
		return judge(flag);

	for(int i=0; i<X; i++)
		for(int j=0; j<X; j++)
			if(A[i][j] == '.')
				return -1;
	return 0;
}

int judge(int target)
{	
	if(target == 3 || target == 4)
		return 1;
	if(target == -3 || target == -4)
		return 2;
	return 0;
}

int calculate(char A, int *target)
{
	if(A == 'O')
		(*target)++;
	else if(A == 'X')
		(*target)--;
	else if(A == '.')
		*target += 1000;
	else
		assert(A == 'T');
}

