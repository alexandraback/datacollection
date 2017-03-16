#include <stdio.h>


int tab[4][4][4] = {
	{
	{0,1,1,1},//1*1
	{0,0,1,1},//1*2
	{0,1,1,1},//1*3
	{0,0,1,1}//1*4
	},{
	{0,0,1,1},//1*2
	{0,0,1,1},//2*2
	{0,0,0,1},//2*3
	{0,0,1,1}//2*4
	},{
	{0,1,1,1},//1*3
	{0,0,0,1},//2*3
	{0,1,0,1},//3*3
	{0,0,0,0}//3*4
	},{
	{0,0,1,1},//1*4
	{0,0,1,1},//2*4
	{0,0,0,0},//3*4
	{0,0,1,0}//4*4
	}
};


int main()
{
	int T, cas, x, r, c;
	freopen ("D-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &x, &r, &c);
		printf ("Case #%d: %s\n", cas, tab[r-1][c-1][x-1] ? "RICHARD" : "GABRIEL");	
	}
	return 0;
}
