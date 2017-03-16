#include <iostream>

using namespace std;

int dx[4]={1,0,1,-1};
int dy[4]={0,1,1,1};

char out[4][30]={"Draw","O won","X won","Game has not completed"};

char d[4][5];

int go(int x,int y,int dir)
{
	char now=d[y][x];
	if(now=='.')
		return 0;
	if(now=='T')
		now=d[y+dy[dir]][x+dx[dir]];
	for(int i=0;i<3;i++)
	{
		x+=dx[dir];
		y+=dy[dir];
		if(d[y][x]!='T' && d[y][x]!=now)
			return 0;
	}
	if(now=='O')
		return 1;
	if(now=='X')
		return 2;
	return 0;
}

int draw()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(d[i][j]=='.')
				return 0;
	return 1;
}

void process(int Case)
{
	int result=0;
	int t;
	for(int i=0;i<4;i++)
		cin >> d[i];

	for(int i=0;i<4;i++)
		if(t=go(0,i,0))
			result=t;
	for(int i=0;i<4;i++)
		if(t=go(i,0,1))
			result=t;
	if(t=go(0,0,2))
		result=t;
	if(t=go(3,0,3))
		result=t;

	if(result==0 && !draw())
		result=3;

	cout << "Case #" << Case << ": " << out[result] << endl;
}

void main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
		process(i);
}