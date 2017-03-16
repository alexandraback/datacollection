#include <iostream>
#include <algorithm>
using namespace std;

int score[300];
bool c[300];

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int N;
		cin >> N;
		int x = 0;
		for(int j=0;j<N;j++)
		{
			cin >> score[j];
			x += score[j];
			c[j] = true;
		}
		int M = N;
		double tempx = x*2.0/M;
		bool finish = false;
		while(!finish)
		{
			int tempscore = 0;
			finish = true;
			for(int j=0;j<N;j++)
			{
				if(c[j]==0) continue;
				if(score[j]>=tempx)
				{
					c[j] = 0;
					M--;
					finish = false;
				}
				else
				{
					tempscore += score[j];
				}
			}
			tempx = (tempscore + x)*1.0 / M;
		}
		printf("Case #%d:",i);
		for(int j=0;j<N;j++)
		{
			if(c[j])printf(" %.6lf",(tempx - score[j])*100/x);
			else printf(" 0.000000");
		}
		putchar(10);
	}
}
