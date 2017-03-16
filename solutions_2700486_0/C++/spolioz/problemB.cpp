#include<iostream>
#include<string>
#include<vector>

using namespace std;


int pascal(int j, int k)
{
	if(j == 0)
		return 1;
	if(j == k)
		return 1;
	return(pascal(j-1,k-1) + pascal(j,k-1));
}

int main()
{
	int T;
	cin >> T;
	int cases = 0;
	for(int i = 0; i < T; i++)
	{
		cases++;
		int N,X,Y;
		cin >> N >> X >> Y;
		int reste, nbtri;
		if(N < 6)
		{
			reste = N - 1;
			nbtri = 0;
		}
		else
		{
			if(N < 15)
			{
				reste = N - 6;
				nbtri = 1;
			}
			else
			{
				reste = N - 15;
				nbtri = 2;
			}
		}
		float result = 0;
		vector<float> meredalexandre(9);
		float cur = 1;
		for(int alpha = 0; alpha < 9; alpha++)
		{
			meredalexandre[alpha] = cur;
			cur = 2*cur;
		}
		if(X + Y > 2*(nbtri + 1))
			result = 0;
		else
		{
			if(X + Y < 2*(nbtri + 1))
				result = 1;
			else
			{
				if((Y > reste)||((X == 0)&&(Y == 2*(nbtri+1))))
					result = 0;
				else
				{
					for(int con = Y+1; con <= reste; con++)
					{
						float tem = pascal(con, reste);
						result = result + (tem/meredalexandre[reste]);
					}
				}
			}
		}
		cout << "Case #" << cases << ": " << result << endl;
	}
}
