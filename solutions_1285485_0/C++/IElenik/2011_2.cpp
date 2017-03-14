// 2011_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

FILE * in, * out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int ri() { int a; fscanf(in, "%d", &a ); return a; }
double rf() { double a; fscanf(in, "%lf", &a ); return a; }
char sbuf[100005]; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\n' || c == 255) break;
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

int getSym()
{
	fi(5)
	{
		char c = fgetc(in);
		if(c == '.') return 0;
		if(c == '#') return 1;
		if(c == 'X') return 2;
	}
	return 0;
}


bool isBad(int i, int j)
{
	if(!i && !j)  return true;
	if(!i && j>1) return true;
	if(i>1 && !j) return true;
	if(!i || !j) return false;
	for(int k = 2; k<=i; k++)
		if( (i%k) == 0 && (j%k) == 0) return true;
	return false;
}

void checkX(int * r, int w, int h, int x, int y, int & dx, int & dy)
{
	if(dx < 0) x--;
	if(r[x+y*w] == 1)
		dx = -dx;
}

void checkY(int * r, int w, int h, int x, int y, int & dx, int & dy)
{
	if(dy < 0) y--;
	if(r[x+y*w] == 1)
		dy = -dy;
}

bool checkU(int * r, int w, int h, int x, int y, int & dx, int & dy)
{
	int px, py;
	if(dx < 0) { x--; px = x+1; }
	else px = x-1;
	if(dy < 0) { y--; py = y+1; }
	else py = y-1;
	if(r[x+y*w] == 1)
	{
		if(r[x+py*w] != 1 && r[px+y*w] != 1) 
			return false;
		if(r[x+py*w] == 1) 
			dx = -dx;
		if(r[px+y*w] == 1) 
			dy = -dy;
	}
	return true;
}


bool travel(int * r, int w, int h, int x, int y, int dx, int dy, int mult, int steps)
{
	int sx = x, sy = y;

	while(steps--)
	{
		x += dx;
		y += dy;

		if(x == sx && y == sy) return true;

		if(x < 0 || y < 0 || x > mult*w || y > mult * h)
			printf("Error\n");

		if( (x%mult) == 0 && (y%mult) == 0)
		{
			if(!checkU(r, w, h, x/mult, y/mult, dx, dy)) return false;
		}
		else if((x%mult) == 0)
			checkX(r, w, h, x/mult, y/mult, dx, dy);
		else if((y%mult) == 0)
			checkY(r, w, h, x/mult, y/mult, dx, dy);
	}
	return false;
}

long _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("D-small-attempt1.in","rt");
//	in	= fopen("test.in","rt");
	out	= fopen("s_out.txt","wt");
	
	int T = ri(); 
	int r[1000];
	for(int i = 0; i<T; i++)
	{
		int h = ri(); 
		int w = ri(); 
		int d = ri(); 


		int * pr = r;
		int x = 1,y = 1;
		fj(h)
		fk(w)
		{
			int s = getSym();
			if(s == 1 && j != 0 && k != 0 && j != h-1 && k != w-1)
				printf("found\n");
			if(s == 2)
			{
				x = k;
				y = j;
			}
			*pr++ = s;
		}


		__int64 count = 0;
		int maxd = 0;
		fj(d+1)
		fk(d+1)
		{
			if(isBad(j,k)) continue;
			int m = 1;

			if(k && j) m = k*j*2;
			else if(k) m = k*2;
			else m = j*2;


			int s = count;
			int steps = sqrt(d*(double)d*m*m/(j*j+k*k));
			if(travel(r,w,h, (x*2+1)*m/2,(y*2+1)*m/2,j,k,m,steps) ) count++;
			if(k && travel(r,w,h, (x*2+1)*m/2,(y*2+1)*m/2,j,-k,m,steps) ) count++;
			if(j && travel(r,w,h, (x*2+1)*m/2,(y*2+1)*m/2,-j,k,m,steps) ) count++;
			if(k && j && travel(r,w,h, (x*2+1)*m/2,(y*2+1)*m/2,-j,-k,m,steps) ) count++;
			if(s != count)
			{
				if(j > maxd) maxd = j;
				if(k > maxd) maxd = k;
				//printf("Case #%d: %lld %d %d %d\n",i+1, count, (maxd+d-1)/d, j, k);
			}
		}

				

		fprintf(out, "Case #%d: %lld\n",i+1, count);
		printf("Case #%d: %lld %d\n",i+1, count, (maxd+d-1)/d);
	}

	fclose(in);
	fclose(out);
	return 0;
}

