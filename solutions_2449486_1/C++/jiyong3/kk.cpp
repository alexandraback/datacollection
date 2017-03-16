#include <iostream>
using namespace std;

#define MAXN 100

int m,n;
int d[MAXN][MAXN];

int go(int x,int y)
{
	int i,j;
	int now=d[y][x];

	for(i=0;i<m;i++)
		if(d[y][i]>now)
			break;

	for(j=0;j<n;j++)
		if(d[j][x]>now)
			break;

	if(i<m && j<n)
		return 1;

	return 0;
}

void process(int Case)
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> d[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(go(j,i))
			{
				cout << "Case #" << Case << ": NO" << endl;
				return;
			}

	cout << "Case #" << Case << ": YES" << endl;
}

void main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
		process(i);
}