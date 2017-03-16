#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int matrix[4][4] =
{
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

inline int calc(int i, int j)
{
	//int tans = matrix[0][1];
	int ai = abs(i) -1, aj = abs(j) - 1;
	int ans = matrix[ai][aj];
	if ((i > 0 && j > 0) || ( i < 0 && j < 0))
	{
		return ans;
	}
	else
	{
		return -ans;
	}
}

inline int ch2int(char ch)
{
	if (ch == 'i')
	{
		return 2;
	}
	else if (ch == 'j')
	{
		return 3;
	}
	else if (ch == 'k')
	{
		return 4;
	}
	cout << "Unknown Error!\n" <<endl;
	return 0;
}

int T, L;
long long X;
string S;


int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,j;
    cin >> T;
    for (int cases=1;cases<=T;cases++)
	{
		bool ans = false;
		int period;
		int indicator = 0;
		cin >> L >> X;
		cin >> S;
		int prefix = 1;
		for (i=0;i < L;++i)
		{
			int n = ch2int(S[i]);
			prefix = calc(prefix, n);
		}
		if (prefix == 1)
		{
			goto PRINT;
		}
		if (prefix == -1)
		{
			period = 2;
			if (X % 2 != 1)
			{
				goto PRINT;
			}
		}
		else
		{
			period = 4;
			if (X % 4 != 2)
			{
				goto PRINT;
			}
		}
		
		prefix = 1;
		for (i=0;i<period *2;++i)
			for (j=0;j<L;++j)
			{
				prefix = calc(prefix, ch2int(S[j]));
				if (indicator == 0)
				{
					if (prefix == 2) // prefix == i
					{
						indicator ++;
					}
				}
				else 
				{
					if (prefix == 4)
					{
						indicator ++;
						goto OUT_LOOP;
					}
				}
			}
	OUT_LOOP:
		if (indicator < 2)
		{
			goto PRINT;
		}
		
		if (i < X)
		{
			ans = true;
		}
	PRINT:
		cout << "Case #" << cases << ": ";
		if (ans)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << "\n";
		
		
	}
    return 0;
}
