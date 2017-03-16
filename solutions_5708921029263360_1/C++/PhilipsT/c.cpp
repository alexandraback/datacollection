#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int Co[3][15][15],Apear[15][15][15];

bool Fal(int a,int b,int c,int k)
{
	if (Apear[a][b][c]) return 0;
	if (Co[0][a][b] == k || Co[1][a][c] == k || Co[2][b][c] == k) return 0;
	return 1;
}

void Push(int a,int b,int c)
{
	Apear[a][b][c] = 1;
	Co[0][a][b] ++,Co[1][a][c] ++,Co[2][b][c] ++;
}

void Solve()
{
	memset(Apear,0,sizeof Apear);
	int a,b,c,k,cnt = 0,ct = 0;
	scanf("%d%d%d%d", &a, &b, &c, &k);
	static int All[MAXN][3];
	for(int i = 1;i <= a;i ++)
		for(int j = 1;j <= b;j ++)
		{
			for(int h = 1;h <= min(k,c);h ++)
				All[++ cnt][0] = i,All[cnt][1] = j,All[cnt][2] = (i + j + h) % c + 1;
			ct ++;
		}
	memset(Co,0,sizeof Co);
	for(int i = 1;i <= cnt;i ++)
	{
		if (!Fal(All[i][0],All[i][1],All[i][2],k)) 
		{
			swap(All[i],All[cnt --]);
			i --;
		} else
		{
			Push(All[i][0],All[i][1],All[i][2]);
		}
	}
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i ++) printf("%d %d %d\n", All[i][0], All[i][1], All[i][2]);
}

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
