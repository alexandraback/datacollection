
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

int R, C, D;

int  pnt_len = 0;
typedef struct pnt_s {
	int r;
	int c;
} pnt_t;
pnt_t  pnt[10000];


int add_pnt( int r, int c)
{
	if ( r*r+c*c <= D*D )
	{
		pnt[pnt_len].r = r;
		pnt[pnt_len].c = c;
		pnt_len++;
	}

	return 0;
}

int compare( const void *a, const void *b )
{
	pnt_t  *a1 = (pnt_t *)a;
	pnt_t  *b1 = (pnt_t *)b;
	return (a1->r)*(b1->c) - (b1->r)*(a1->c);
}

int F(int col, int row)
{
	pnt_len = 0;

	//
	// 1. determine distance in D
	for (int m=0; 2*m*R<=D; m++)
	{
		int r = 2*m*R;
		for (int k=0; 2*k*C<=D; k++)
		{
			int c = 2*k*C;

			int r1, c1;
			r1 = r + row*2 + 1;
			c1 = c + (C-1-col)*2 + 1;
			add_pnt(r1, c1);

			r1 = r + row*2 + 1;
			c1 = c + 2*C;
			add_pnt(r1, c1);

			r1 = r + 2*R;
			c1 = c + (C-1-col)*2 + 1;
			add_pnt(r1, c1);

			r1 = r + 2*R;
			c1 = c + 2*C;
			add_pnt(r1, c1);
		}
	}

	//
	// 2. Remove same angle
	
	// sort by tangent
	qsort( pnt, pnt_len, sizeof(pnt_t), compare);

	// count dup
	int dup_count = 0;
	float last_tng = 0.0;
	int last_r = 0;
	int last_c = 100;
	for (int j=0; j<pnt_len; j++)
	{
		if ( last_r*pnt[j].c == pnt[j].r*last_c )
			dup_count ++;
		last_r = pnt[j].r;
		last_c = pnt[j].c;
	}

	return  pnt_len - dup_count;
}

int main()
{
	gets(buf);
	int ncase = atoi(buf);
  
	for(int i=1; i<=ncase; i++)
	{
		int  H, W;
		scanf("%d %d %d", &H, &W, &D);

		R = H-2;
		C = W-2;

		int workcnt = 0;

		int col = 0;
		int row = 0;
		for (int k=0; k<H; k++)
		{
			//gets(buf);
			scanf("%s", buf);
			char* ret = strchr(buf, 'X');
			if ( ret != NULL )
			{
				col = ret-buf-1;
				row = k-1;
			}
		}


		//
		// A. up, down, left, right
		//
		if ( row*2+1 <= D )
			workcnt++;
		if ( (R-1-row)*2+1<= D )
			workcnt++;
		if ( col*2+1 <= D )
			workcnt++;
		if ( (C-1-col)*2+1 <= D )
			workcnt++;

		//
		// B  diagonal
		//
		workcnt += F(col, row);
		workcnt += F(col, R-1-row);
		workcnt += F(C-1-col, R-1-row);
		workcnt += F(C-1-col, row);


		printf("Case #%d: ", i);

		printf("%d", workcnt);
		printf("\n");
	}
  
	return  0;  
}
