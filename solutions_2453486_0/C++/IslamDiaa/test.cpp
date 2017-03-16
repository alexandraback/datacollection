#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int TEST;
string arr[5];
int X,Y;
int dx[] = {1,0,1,1};
int dy[] = {0,1,1,-1};

int calc(int x,int y,int d,char c)
{
	int cnt = 0;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[d] * i;
		int ny = y + dy[d] * i;
		cnt += (arr[nx][ny] == c || arr[nx][ny] == 'T');
	}
	return cnt;
}

bool won(char c)
{
	for(int i = 0; i < 4; i++)
		if(calc(i,0,1,c) == 4 || calc(0,i,0,c) == 4)
			return 1;
	if(calc(0,0,2,c) == 4 || calc(0,3,3,c) == 4)
		return 1;
	return 0;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> TEST;
	for(int T = 1; T <= TEST; ++T)
	{
		int cnt = 0;
		for(int i = 0; i < 4; ++i)
			cin >> arr[i];
		for(int i = 0; i < 4; ++i)
			for(int j = 0 ; j < 4; ++j)
				cnt += (arr[i][j] != '.');
		if(won('X'))
			printf("Case #%d: X won\n",T);
		else if(won('O'))
			printf("Case #%d: O won\n",T);
		else if(cnt == 16)
			printf("Case #%d: Draw\n",T);
		else
			printf("Case #%d: Game has not completed\n",T);
	}
    return 0;
}
