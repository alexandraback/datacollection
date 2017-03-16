#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

#if 1

int x=100,y=100,off;
char dir[1000];
char strEW[] = "EW";
char strNS[] = "NS";

void main(void)
{
	int tst = 1;

	scanf("%d", &tst);
	for(int t=1 ; t<=tst ; ++t)
	{
		scanf("%d %d", &x, &y);
		off = 0;
		int xc = x;
		int xd = 0;
		if(xc < 0)
		{
			xc = -xc;
			xd = 1;
		}
		int yc = y;
		char yd = 0;
		if(yc < 0)
		{
			yd = 1;
			yc = -yc;
		}
		int jmp = 1;
		int xx=0, yy=0;
		int dx=0, dxg=0, dy=0, dyg = 0;

		// For x
		while(xx<xc && xx+jmp <= xc)
		{
			xx += jmp;
			jmp++;
			dx++;
		}

		// For y
		while(yy<yc && yy+jmp <= yc)
		{
			yy += jmp;
			jmp++;
			dy++;
		}

		// After add, will increase
		dxg = xc - xx;
		jmp += 2*dxg;

		// After add, will increase
		dyg = yc - yy;

		printf("Case #%d: ", t);

		while(dx--)
			printf("%c", strEW[xd]);
		while(dy--)
			printf("%c", strNS[yd]);
		while(dxg--)
			printf("%c%c", strEW[!xd], strEW[xd]);
		while(dyg--)
			printf("%c%c", strNS[!yd], strNS[yd]);
		printf("\n");
	}

	fflush(stdin);
	getchar();
}

#else

#define X	100
#define Y	100

struct node{
	int x;
	int y;
	int d;
	int j;
	char dir;
};

node arr[2*X][2*Y];

int que[2*X*Y][2],qlen;

int x=3,y=4,jmp;
int paths[4][2] = { {0,-1}, {0,1}, {1, 0}, {-1, 0} };
char direction[] = "snew";

void print_dir(int i, int j)
{
	while(i || j)
	{
		printf("%c", arr[i][j].dir);
		i = arr[i][j].x;
		j = arr[i][j].y;
	}
}

void do_jmp(int i, int j)
{
	for(int m=0 ; m<4 ; ++m)
	{
		int jmp = arr[i][j].j+1;
		int xx = paths[m][0]*jmp;
		int yy = paths[m][1]*jmp;

		int ii = i+xx;		
		int jj = j+yy;

		if(arr[ii][jj].d == 0)
		{
			// Mark it with predessor
			arr[ii][jj].x = i;
			arr[ii][jj].y = j;
			arr[ii][jj].d = arr[i][j].d + jmp; 
			arr[ii][jj].dir = direction[m];
			arr[ii][jj].j = jmp;
			if(ii==x && jj==y)
			{
				printf("Got it %d \n", arr[ii][jj].d);

				print_dir(ii,jj);

				getchar();
				exit(0);
			}

			que[qlen][0] = ii;
			que[qlen][1] = jj;
			qlen++;
		}
	}
}

void main(void)
{
	int n=3,tst = 1;

	//scanf("%d", &tst);

	for(int t=1 ; t<=tst ; ++t)
	{
		//scanf("%d %d", &x, &y);
		
		memset(arr,0,sizeof(arr));

		que[0][0] = 0;
		que[0][1] = 0;
		arr[0][0].d = 1;
		arr[0][0].j = 0;
		qlen = 1;

		for(int i=0 ; i<qlen ; ++i)
		{
			do_jmp(que[i][0],que[i][1]);
		}

	}

	getchar();
}
#endif
