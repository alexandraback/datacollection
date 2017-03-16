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


int canMove(int x, int y, int * c, int * f, int w, int h, int H, int ct, int dir)
{
	int cc = c[x+y*w];
	int cf = f[x+y*w];
	int nc = c[x+y*w+dir];
	int nf = f[x+y*w+dir];

	int ch = H-ct;

	if(nc < cf+50 || nc < nf+50 || cc < nf+50) return 0xFFFFFF;
	if(nc >= ch + 50)
	{
		if(ct == 0) return 0;
		else if(ch - cf >= 20) return ct+10;
		return ct+100;
	}
	ct += (ch+50-nc);
	ch = H-ct;
	if(ch - cf >= 20) return ct+10;
	return ct+100;
//
//The water level, the floor height of your current square, 
//and the floor height of the adjacent square must all be at least 50 centimeters 
//lower than the ceiling height of the adjacent square. 
//Note: this means that you will never be able to enter a square with less than 50 centimeters between the floor and the ceiling.
//
//The floor height of the adjacent square must be at least 50 centimeters below the ceiling height of your current square as well.
//You can never move off the edge of the map.
//	
//
	return 0;
}


void move0(int x, int y, int * t, int * c, int * f, int w, int h, int H)
{
	if(x < w-1 && t[x+y*w+1] > 0)
	{
		int ct = canMove(x,y,c,f,w,h,H,0,1);
		if(ct == 0)
		{
			t[x+y*w+1] = 0;
			move0(x+1,y,t,c,f,w,h,H);
		}
		else if(t[x+y*w+1] > ct) t[x+y*w+1] = ct;
	}
	if(x > 0 && t[x+y*w-1] > 0)
	{
		int ct = canMove(x,y,c,f,w,h,H,0,-1);
		if(ct == 0)
		{
			t[x+y*w-1] = 0;
			move0(x-1,y,t,c,f,w,h,H);
		}
		else if(t[x+y*w-1] > ct) t[x+y*w-1] = ct;
	}
	if(y < h-1 && t[x+y*w+w] > 0)
	{
		int ct = canMove(x,y,c,f,w,h,H,0,w);
		if(ct == 0)
		{
			t[x+y*w+w] = 0;
			move0(x,y+1,t,c,f,w,h,H);
		}
		else if(t[x+y*w+w] > ct) t[x+y*w+w] = ct;
	}
	if(y > 0 && t[x+y*w-w] > 0)
	{
		int ct = canMove(x,y,c,f,w,h,H,0,-w);
		if(ct == 0)
		{
			t[x+y*w-w] = 0;
			move0(x,y-1,t,c,f,w,h,H);
		}
		else if(t[x+y*w-w] > ct) t[x+y*w-w] = ct;
	}
}

int nextTime(int * t, int w, int h, int ct)
{
	int nt = 0xFFFFFF;
	fi(w*h) { if(t[i]<nt && t[i] > ct) nt = t[i]; }
	return nt;
}

void moveT(int * t, int * c, int * f, int w, int h, int H, int ct)
{
	for(int x = 0; x<w; x++)
	for(int y = 0; y<h; y++)
	{ 
		if(t[x+y*w] == ct)
		{
			if(x < w-1 && t[x+y*w+1] > ct+1)
			{
				int nt = canMove(x,y,c,f,w,h,H,ct,1);
				if(t[x+y*w+1] > nt) t[x+y*w+1] = nt;
			}
			if(x > 0 && t[x+y*w-1] > ct+1)
			{
				int nt = canMove(x,y,c,f,w,h,H,ct,-1);
				if(t[x+y*w-1] > nt) t[x+y*w-1] = nt;
			}
			if(y < h-1 && t[x+y*w+w] > ct+1)
			{
				int nt = canMove(x,y,c,f,w,h,H,ct,w);
				if(t[x+y*w+w] > nt) t[x+y*w+w] = nt;
			}
			if(y > 0 && t[x+y*w-w] > ct+1)
			{
				int nt = canMove(x,y,c,f,w,h,H,ct,-w);
				if(t[x+y*w-w] > nt) t[x+y*w-w] = nt;
			}
		}
	}
}

int sum(int * v, int mask)
{
	int r = 0;
	for(int j = 0; j<20; j++)
	{
		if((1<<j)&mask) 
			r += v[j];
	}
	return r;
}

long _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("C-small-attempt0.in","rt");
	out	= fopen("s_out.txt","wt");
	
	int T = ri(); 
	
	int f[10000];
	for(int i = 0; i<T; i++)
	{
		int h = ri(); 
		
		fj(h) 
		{ 
			f[j] = ri(); 
		}

		map<int, int> sums;

		
		fprintf(out, "Case #%d:\n",i+1);
		bool bfound = false;
		for(int i = 1; i < (1<<20) && !bfound; i++)
		{
			int s = sum(f, i);
			if(sums[s] != 0)
			{
				bfound = true;
				for(int j = 0; j<20; j++)
				{
					if((1<<j)&i) 
						fprintf(out, "%d ",f[j]);
				}
				int k = sums[s];
				fprintf(out, "\n");
				for(int j = 0; j<20; j++)
				{
					if((1<<j)&k) 
						fprintf(out, "%d ",f[j]);
				}
				fprintf(out, "\n");
			}
			sums[s] = i;
		}

		if(!bfound)
				fprintf(out, "Impossible\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}

