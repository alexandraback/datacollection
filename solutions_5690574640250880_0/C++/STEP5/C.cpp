#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 64;
bool white[MAXN][MAXN];

int R, C, M, N;
bool swapped = false;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
	{
		swapped = false;
		cin>>R>>C>>M;
		N = R * C - M;

		if(R > C)
		{
			swap(R, C);
			swapped = true;
		}

		//calculate
		cout<<"Case #"<<t<<":"<<endl;
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				white[i][j] = false;
			}
		}

		if(R == 1)
		{
			for(int i=0; i<N; i++)
			{
				white[0][i] = true;
			}
		}
		else if(R == 2)
		{
			if(N == 1) ;
			else if(N==2 || N%2)
			{
				cout<<"Impossible"<<endl;
				continue;
			}
			else
			{
				for(int i=0; i<N/2; i++)
				{
					white[0][i] = white[1][i] = true;
				}
			}
		}
		else
		{
			if(N==1) ;
			else if(N==2 || N==3 || N==5 || N==7)
			{
				cout<<"Impossible"<<endl;
				continue;
			}
			else if(N==4)
			{
				white[0][0] = white[0][1] = white[1][0] = white[1][1] = true;
			}
			else if(N==6)
			{
				for(int i=0; i<2; i++)
				{
					for(int j=0; j<3; j++)
					{
						white[i][j] = true;
					}
				}
			}
			else if(N < 2*C+2)
			{
				if(N%2)
				{
					int K = (N - 3) / 2;
					for(int i=0; i<K; i++)
						white[0][i] = white[1][i] = true;
					white[2][0] = white[2][1] = white[2][2] = true;
				}
				else
				{
					int K = (N - 2) / 2;
					for(int i=0; i<K; i++)
						white[0][i] = white[1][i] = true;
					white[2][0] = white[2][1] = true;
				}
			}
			else if(N <= 3*C)
			{
				for(int i=0; i<C; i++)
					white[0][i] = white[1][i] = true;
				int K = N - 2*C;
				for(int i=0; i<K; i++)
					white[2][i] = true;
			}
			else
			{
				int mr = N / C;
				int rem = N % C;

				for(int i=0; i<mr; i++)
				{
					for(int j=0; j<C; j++)
						white[i][j] = true;
				}
				for(int i=0; i<rem; i++)
					white[mr][i] = true;

				if(rem == 1)
				{
					white[mr][1] = true;
					white[mr-1][C-1] = false;
				}
			}
		}

		//output
		if(swapped)
		{
			for(int i=0; i<MAXN; i++)
			{
				for(int j=0; j<i; j++)
				{
					swap(white[i][j], white[j][i]);
				}
			}
			swap(R, C);
		}

		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				if(i==0 && j==0)
					cout<<"c";
				else
					cout<<(white[i][j] ? "." : "*");
			}
			cout<<"\n";
		}
	}

    return 0;
}
