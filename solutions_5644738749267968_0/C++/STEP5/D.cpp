#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
int N;

double arr[2*MAXN];
int ord[2*MAXN];

bool cmp(int a, int b)
{
	return arr[a] < arr[b];
}

int getWinNum(bool dir)
{
	int rcnt = 0, res = 0;
	for(int i=0; i<2*N; i++)
	{
		if((ord[i]<N) == dir)
		{
			if(rcnt > 0)
			{
				rcnt--;
				res++;
			}
		}
		else
		{
			rcnt++;
		}
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		cin>>N;
		for(int i=0; i<2*N; i++)
			ord[i] = i;
		for(int i=0; i<2*N; i++)
			cin>>arr[i];
		sort(ord, ord + 2*N, cmp);

		int num1 = N - getWinNum(false);
		int num2 = getWinNum(true);

		cout<<"Case #"<<t<<": "<<num2<<" "<<num1<<endl;

	}

    return 0;
}
