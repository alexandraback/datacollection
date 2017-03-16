#include "stdio.h"
#include <string.h>
//#include <queue>

//using namespace std;

#if 1

//#define IN_FILE	"IO/CJ-3.in"

#define P 	printf
#define N	50

char a[N+2][N+2];

int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = {-1,0,1,1,1,0,-1,-1};

int r,c,m,ctr;

//char str[N+1] = "**************************************************";

int dfs(int, int);

int main(void)
{
	int t,tst;

	FILE* fin = stdin;
#ifdef IN_FILE
	fin = fopen(IN_FILE,"r");
	if(fin == NULL)
	{
		printf("Cannot Open file %s\n", IN_FILE);
		return 0;
	}
#endif

	fscanf(fin, "%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int i,rr=1,cc=1;

		fscanf(fin, "%d %d %d", &r, &c, &m);
		P("Case #%d:\n", t);
		//P("\n\nCase #%d: %d %d %d\n", t, r,c,m);

		memset(a[r+1]+1,0,sizeof(a[0][0])*(c+1));

#if 0
		for(rr=1 ; rr<=r ; ++rr)
		{
			for(cc=1 ; cc<=c ; ++cc)
			{
				for(i=1 ; i<=r ; ++i)
					strcpy(a[i]+1,str+N-c);

				queue< pair<int,int> > q;
				q.push(make_pair(rr,cc));
				a[rr][cc] = 'c';
				while(!q.empty())
				{
					int i = q.front().first;
					int j = q.front().second;
					q.pop();

					int cc=0;
					for(int d=0 ; d<8 ; ++d)
					{
						int ii = i+dr[d];
						int jj = j+dc[d];
						if(a[ii][jj]=='*')
							cc++;
					}
					if(r*c < m+ctr+cc)
						continue;
					for(int d=0 ; d<8 ; ++d)
					{
						int ii = i+dr[d];
						int jj = j+dc[d];
						if(a[ii][jj]=='*')
						{
							a[ii][jj] = '.';
							q.push(make_pair(ii,jj));
						}
					}
					ctr += cc;
					if(r*c == m+ctr)
						goto ANS;
				}
			}
		}
#else
		if(m==0)
		{
			for(rr=1 ; rr<=r ; ++rr)
			{
				memset(a[rr]+1,'.',c);
				a[rr][c+1] = 0;
			}
			a[1][1] = 'c';
			goto ANS;
		}

		for(i=1 ; i<=r ; ++i)
		{
			memset(a[i]+1,'*',c);
			a[i][c+1] = 0;
		}

		if(r*c == m+1)
		{
			a[1][1] = 'c';
			goto ANS;
		}

		for(rr=1 ; rr<=r ; ++rr)
			for(cc=1 ; cc<=c ; ++cc)
			{
				ctr = 1;
				a[rr][cc] = 'c';
				if(dfs(rr,cc))
					goto ANS;
				a[rr][cc] = '*';
			}

#endif

		P("Impossible\n");
		continue;
ANS:
		for(i=1 ; i<=r ; ++i)
			P("%s\n",&a[i][1]);
	}

#ifdef IN_FILE
	fclose(fin);
#endif

	return 0;
}

int dfs(int i, int j)
{
	int cc = 0;
	int arr[8][2], pos=0;
	for(int d=0 ; d<8 ; ++d)
	{
		int ii = i+dr[d];
		int jj = j+dc[d];
		if(a[ii][jj]=='*')
			cc++;
	}
	if(r*c < m+ctr+cc)
		return 0;
	ctr += cc;
	for(int d=0 ; d<8 ; ++d)
	{
		int ii = i+dr[d];
		int jj = j+dc[d];
		if(a[ii][jj]=='*')
		{
			a[ii][jj] = '.';
			arr[pos][0] = ii;
			arr[pos][1] = jj;
			pos++;
		}
	}
	if(r*c == m+ctr)
		return 1;
	for(int d=0 ; d<pos ; ++d)
	{
		if(dfs(arr[d][0],arr[d][1]))
			return 1;
	}
	for(pos-- ; pos>=0 ; pos--)
		a[arr[pos][0]][arr[pos][1]] = '*';
	ctr -= cc;
	return 0;
}

#endif
