#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
char sW[] = "GABRIEL\n", sL[] = "RICHARD\n";

int check(int r, int c, int r1, int c1)
{
	if (r > c)swap(r, c);
	if (r1 > c1)swap(r1, c1);
	if (r >= r1&&c >= c1)return 1;
	else return 0;
}



int main()
{
	int T,Cas = 1,X,R,C;
	int i, j, t;
	ifstream cin("D-small-attempt1.in");
	ofstream cout("out.txt");
	cin >> T;
	while (T--)
	{
		cin >> X >> R >> C;
		cout << "Case #" << Cas++ << ": ";

		if ((R*C)%X||X>=7)
		{
			cout << sL;
			continue;
		}
		for (i = 1; i <= X; i++)
		{
			if (check(R, C, i, X + 1 - i)==0)break;
		}
		if (i > X)cout << sW;
		else cout << sL;
	}

}