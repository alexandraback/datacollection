/*
 * D.cpp
 *
 *  Created on: 2012-4-14
 *      Author: jesliwang
 */

#include <stdio.h>
#include <math.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

#define eps 1e-9

map<pair<int,int>, bool> my;
int gcd(int a,int b)
{
	if( 0 == b)
		return a;
	return gcd(b, a%b);
}

int getu(int x, int y, int y1, int y2, int D)
{
	int ret = 0;

	//printf("inx=%d iny=%d\n", x, y);
	if( x*x + y*y <= D*D )
	{
		int s = abs(gcd(x, y));
		int tx = x / s;
		int ty = y / s;
		if( !my[make_pair(tx,ty)])
		{
			ret ++;
		//	printf("%d %d\n", x, y);
			my[make_pair(tx,ty)] = true;
		}
	}
	else
		return 0;
	ret += getu(x, y + y1, y2, y1, D);
	//printf("x=%d y=%d, ret=%d\n", x, y, ret);
	return ret;


}

int getl(int x1, int x2, int y1, int y2, int D)
{
	int ret = 0;
	int x = x1, y = 0;

	int tx1 = x2, tx2 = x1;
	while( x*x + y*y <= D*D)
	{
		ret += getu(x, y + y1, y2, y1, D);
		ret += getu(x, y - y2, -y1, -y2, D);
		x += tx1;
		swap(tx1, tx2);
	}
	//printf("l = %d\n", ret);
	x = -x2, y = 0;
	tx1 = x2, tx2 = x1;
	while( x*x + y*y <= D*D)
	{
		ret += getu(x, y + y1, y2, y1, D);
		ret += getu(x, y - y2, -y1, -y2, D);
		x -= tx2;
		swap(tx1, tx2);
	}
	return ret;

}


int get(int x1, int x2, int y1, int y2, int D)
{
	int ret = getl(x1, x2, y1, y2, D);
	//printf("get = %d\n", ret);
	if(x1 <= D)
		ret ++;
	if(x2 <= D)
		ret ++;
	if(y1 <= D)
		ret ++;
	if(y2 <= D)
		ret ++;
	return ret;
}

int main(int argc, char* argv[])
{
	int T = 0;
	scanf("%d", &T);
	for(int i = 1; i <= T; i ++)
	{
		my.clear();
		int H = 0, W = 0, D = 0;
		scanf("%d %d %d\n", &H, &W, &D);
		int x1 = 0, x2 = 0;
		int y1 = 0, y2 = 0;

		for(int x = 0; x < H; x ++)
		{
			for(int y = 0; y < W; y ++)
			{
				char c=getchar();
				if( '\n' == c )
					c=getchar();

				if( 'X' == c )
				{
					y1 = 2*x - 1;
					y2 = 2*(H - 1 - x) - 1;
					x1 = 2*y - 1;
					x2 = 2*(W - 1 - y) - 1;
				}

			}
		}

	    int ans = 0;
	    ans += get(x1, x2, y1, y2, D);
	    printf("Case #%d: %d\n", i, ans);

	}
	return 0;
}



