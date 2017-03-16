#include <iostream>
#include <cstdio>
using namespace std;

int tr[102];
int opt[102][102];
int N , S , p;


bool make(int x)
{
//	cerr << "CALL " << p << ' ' << x << endl;
	for (int i=-2;i<=2;i++)
		if ((x + i) % 3 == 0)
			if ((x + i)/3 >= p)
			{
				int t = (x+i)/3;
				if (i <= 0 || (i>0 && (t-1) >= 0))
				return	true;
			}
	return	false;
}

bool makeSur(int x)
{
	for (int i=-4;i<=4;i++)
		if (i && (x + i) % 3 == 0)
			if ((x + i)/3 >= p)
			{
				int t = (x+i)/3;
				if (i <= 0 || (i > 0 && (t-2) >= 0))
					return	true;
			}
	return	false;
}

int main()
{
	int nCase;
	scanf("%d",&nCase);
	for (int nc = 0 ; nc < nCase ; nc ++ ) {
		scanf("%d%d%d",&N,&S,&p);
		for (int i=0;i<N;i++)
			scanf("%d",tr+i);

		memset(opt,0,sizeof(opt));
		for (int j=1;j<=N;j++)		//opt[0][j]
			if (make(tr[j-1]))
				opt[0][j] = opt[0][j-1]+1;
			else
				opt[0][j] = opt[0][j-1];
		
//		for (int j=1;j<=N;j++)
//			cerr << j << ' ' << opt[0][j] << endl;
				
		for (int i=1;i<=S;i++)
			for (int j=1;j<=N;j++)
			{
				opt[i][j] = opt[i][j-1];
				if (make(tr[j-1]))
					opt[i][j] = max(opt[i][j],opt[i][j-1] + 1);
				if (makeSur(tr[j-1]))
					opt[i][j] = max(opt[i][j],opt[i-1][j-1] + 1);
			}
		printf("Case #%d: %d\n",nc+1,opt[S][N]);
	}
//	system("pause");
	return	0;
}
