#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[4][4] = { 1, 2, 3, 4,
2, -1, 4, -3,
3, -4, -1, 2,
4, 3, -2, -1 };
char s[10010];
int b[10010];
int f[500];
char sN[] = "NO\n", sY[] = "YES\n";
int mu(int x, int y)
{
	int sign = 1;
	if (x < 0)
	{
		sign *= -1;
		x = -x;
	}
	if (y < 0)
	{
		sign *= -1;
		y = -y;
	}

	return a[x - 1][y - 1] * sign;

}

int solve(char*ps,char*pe, int step, int aim,int ini)
{
	int i, j, k,t=ini;
	if (ini == aim)return 0;

	for (i = 0; ps + i != pe; i += step)
	{
		if(step==-1)t = mu(f[*(ps + i)],t);
		else t = mu(t, f[*(ps + i)]);
		if (t == aim)return i*step;
	}
	return -1;
}
int main()
{
	f['i'] = 2;
	f['j'] = 3;
	f['k'] = 4;
	int T,Cas = 1,L,X,ans;
	int i, j, t,LX,RX,Lini,Rini,Lans,Rans,flag;
	ifstream cin("C-small-attempt3.in");
	ofstream cout("out.txt");
	cin >> T;
	while (T--)
	{
		cin >> L >> X;
		cin >> s;
		t = 1;
		for (i = 0; s[i]; i++)
		{
			t = mu(t, f[s[i]]);
		}
		cout << "Case #" << Cas++ << ": ";
		if (t == -1 && X % 2);
		else if (t*t != 1 && X % 4 == 2);
		else
		{
			cout << sN;
			continue;
		}
		ans = 1; Lini = 1; flag = 0;
		for (LX = 0; LX < 4 && LX < X; LX++)
		{
			if ((Lans = solve(&s[0], &s[L], 1, 2, Lini)) != -1)
			{
				Rini = 1;
				for (RX = 0; RX < 4 && RX < X - LX; RX++)
				{
					if ((Rans = solve(&s[L - 1], &s[-1], -1, 4, Rini)) != -1)
					{
						if (LX + RX + 1 < X)flag = 1;
						else if (Lans + Rans + 2 < L)flag = 1;
					}
					if (flag)break;
					Rini = mu(Rini, t);
				}
			}
			if (flag)break;
			Lini = mu(t, Lini);
		}
		if (flag)cout << sY;
		else cout << sN;
	}

}