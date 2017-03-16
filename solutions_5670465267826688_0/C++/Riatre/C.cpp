#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int I = 2;
const int J = 3;
const int K = 4;

const int oper[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, I, J, K},
	{0, I, -1, K, -J},
	{0, J, -K, -1, I},
	{0, K, J, -I, -1}
};

inline int op(int a, int b)
{
	int nega = 1;
	if(a < 0) { a = -a; nega = -nega; }
	if(b < 0) { b = -b; nega = -nega; }
	return nega * oper[a][b];
}

bool F[222221][9][3];
char ijk[11111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ", ++TK);
		int L = 0;
		ll X = 0;
		scanf("%d %lld",&L,&X);

		scanf("%s",ijk);
		for(int i = 0;i < L;i++)
		{
			switch(ijk[i])
			{
				case 'i': ijk[i] = I; break;
				case 'j': ijk[i] = J; break;
				case 'k': ijk[i] = K; break;
				default: assert(false);
			}
		}
		int len = L * X;
		//if(X > 20) len = 20 * L;

		int whole = 1;
		for(int i = 0;i < L;i++) whole = op(whole, ijk[i]);
		int cnt = 1;
		int single_whole = whole;
		while(whole != 1)
		{
			whole = op(whole, single_whole);
			cnt++;
		}

		memset(F,0,sizeof(F));
		F[0][1 + 4][0] = true;
		bool okay = false;
		for(int i = 0;i < len;i++)
		{
			for(int j = -4;j <= 4;j++)
			{
				if(j == 0) continue;
				for(int k = 0;k < 3;k++)
				{
					if(!F[i][j+4][k]) continue;
					int nxt = op(j,ijk[i % L]);
					F[i+1][nxt+4][k] = true;
					if(nxt == I+k)
					{
						if(I+k != K) F[i+1][1 + 4][k+1] = true;
						else if((i+1) % L == 0 && (X-(i+1)/L) % cnt == 0) okay = true;
					}
				}
			}
		}
		puts(okay ? "YES" : "NO");
	}
	return 0;
}