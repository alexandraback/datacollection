#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX_L 10000
#define MAX_X 15

const int prod[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
const int sign[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}};

int a[MAX_L*MAX_X];
int L;
long long int X;

bool analyze()
{
	bool i_found(a[0] == 1);
	bool ij_found(false);
	int m_prod(a[0]);
	int m_sign(0);
	
	for (int i=1; i<L*X; ++i)
	{
		m_sign ^= sign[m_prod][a[i]];
		m_prod = prod[m_prod][a[i]];
		if (m_prod == 1 && !m_sign)
			i_found = true;
		if (m_prod == 3 && !m_sign && i_found)
			ij_found = true;
	}
	
	return i_found && ij_found && !m_prod && m_sign;
}

void readCase()
{
	string str;
	cin>>L>>X;
	X = min(X, (12ll + X%4));
	cin>>str;
	for (int i=0; i<L; ++i)
		for (int j=0; j<X; ++j)
			a[i+j*L] = str[i] - 'h';
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		if (analyze())
			cout<<"Case #"<<i+1<<": YES"<<endl;
		else
			cout<<"Case #"<<i+1<<": NO"<<endl;
	}
	return 0;
}