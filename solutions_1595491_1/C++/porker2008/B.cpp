#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T,N,S,p;
	int* score;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int pc = 0;
		cin >> N >> S >> p;
		score = new int[N];
		for(int j=0;j<N;j++)
		{
			cin >> score[j];
		}
		sort(score,score+N);
		for(int j=N-1;j>=0;j--)
		{
			int bs;
			bs = score[j]/3 + (score[j]%3 > 0);
			if(bs>=p)
				pc++;
			else if(score[j]>=p&&p-(score[j]-p)/2<=2)
			{
				if(S>0)
				{
					pc++;
					S--;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		cout << "Case #" << i << ": " << pc << endl;
		delete[] score;
	}
}
