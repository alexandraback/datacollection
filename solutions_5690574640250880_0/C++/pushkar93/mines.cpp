//PUSHKAR SINGH
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include <cassert>
using namespace std;
// Input macros
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
// Useful constants
#define INF (int)1e9
#define EPS 1e-11
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
//#define sz(a) ((int)(a.size()))
#define mp make_pair
//#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define llu long long unsigned
#define ld long

int scan_d() {
	int ip = getchar_unlocked(), ret = 0, flag = 1;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ld scan_ld() {
	int ip = getchar_unlocked(), flag = 1;
	ld ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ll scan_ll() {
	int ip = getchar_unlocked(), flag = 1;
	ll ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
llu scan_llu() {
	int ip = getchar_unlocked();
	llu ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		;
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return ret;
}

//end of fast input

//fast output

//no line break
void print_d(int n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 10;
	char output_buffer[10];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 10);
}
void print_ld(ld n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 11;
	char output_buffer[11];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 11);
}
void print_ll(ll n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}
void print_llu(llu n) {
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}

#define DEBUG 1
#define debug(x) {if (DEBUG)cout <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#define mod 1000000007

#define checkbit(n,b) ( (n >> b) & 1)

#define mine 1
#define free 0

int r,c,m,fs,nr,nc,done;

int mat[51][51];

void handleone()// handling one case
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0 && j==0)
				printf("c");
			else
				printf("*");
		}
		printf("\n");
	}
	done=1;
}
void handlelinear()
{
	int freees = r*c - m;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0 && j==0)
			{
				printf("c");
				freees--;
			}
			else if(freees > 0)
			{
				printf(".");
				freees--;
			}
			else
				printf("*");
		}
		printf("\n");
	}
	done=1;
}
void handledual()
{
	if(m%2 == 1)
	{
		printf("Impossible\n");
		done = 1;
		return;
	}

	m = m/2;
	int leftover = m;

	if(r == 2)
	{
		for(int i=0;i<r;i++)
		{
			leftover = m;
			for(int j=0;j<c;j++)
			{
				if(leftover > 0)
				{
					printf("*");
					leftover--;
				}
				else if(i == 1 && j == c-1)
				{
					printf("c");
				}
				else
					printf(".");
			}
			printf("\n");
		}

	}
	else
	{
		leftover = m;
		for(int i=0;i<r;i++)
		{
			if(leftover > 0)
			{
				printf("**\n");
				leftover--;
			}
			else if(i == r-1 )
			{
				printf(".c\n");
			}
			else
				printf("..\n");

		}
	}
	done=1;
}

void solve(int r,int c)
{
	int flagblock = 0,leftover,flagone=0;

	nr= m/c;
	nc = m%c;

	if(nr >= r-2)
	{
		if((m - (r-2)*c)%2 == 0)
		{
			for(int i=0;i<r-2;i++)
			{
				for(int j=0;j<c;j++)
				{
					mat[i][j] = mine;
				}
			}
			leftover = (m - (r-2)*c);

			for(int i=0;i<c;i++)
			{
				if(leftover == 0) break;
				mat[r-2][i] = mine;
				mat[r-1][i] = mine;
				leftover -= 2;
			}
			done=1;
			return;
		}
	}
	else
	{

		if(c - nc == 1)
		{
			flagblock = 1;
		}

		leftover = m;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(leftover == 0)
				{
					if(flagblock == 1)
					{

						if(i+2 == r-2)
						{
							mat[i][j-1] = free;

							if(mat[i][0] == free)
							{
								mat[i][0] = mine;
							}
							else
							{
								mat[i+1][0] = mine;
							}

						}
						else
						{
							mat[i][j-2] = free;
							mat[i][j-1] = free;

							if(mat[i][0] == free)
							{
								mat[i][0] = mine;
								mat[i+1][0] = mine;
							}
							else
							{
								mat[i+1][0] = mine;
								mat[i+2][0] = mine;
							}
						}
					}
					break;
				}
				mat[i][j] = mine;
				leftover--;
			}
			if(leftover == 0)
			{
				break;
			}
		}
		done = 1;
		return;
	}

}

void spread(int r,int c)
{
	mat[0][0] = free;mat[1][0] = free;
	mat[0][1] = free;mat[2][0] = free;
	mat[0][2] = free;mat[1][1] = free;
	mat[2][1] = free;mat[1][2] = free;

	int leftover = r*c - m - 8;

	for(int i=3;i<c;i++)
	{
		if(leftover > 1)
		{
			mat[0][i]=free;
			mat[1][i]=free;
			leftover -= 2;
		}
		else
			break;
	}

	for(int i=3;i<r;i++)
	{
		if(leftover > 1)
		{
			mat[i][0]=free;
			mat[i][1]=free;
			leftover -= 2;
		}
		else
			break;
	}

	for(int i=2;i<r;i++)
	{
		for(int j=2;j<c;j++)
		{
			if(leftover == 0) break;
			mat[i][j] = free;
			leftover--;
		}
		if(leftover == 0) break;
	}

	done = 1;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0 && j==0)
				printf("c");
			else if(mat[i][j] == free)
			{
				printf(".");
			}
			else
				printf("*");
		}
		printf("\n");
	}

}

int main()
{

	int t,cno=0;
	s(t);
	while(t--)
	{
		done = 0;
		cno++;
		fill(mat,0);
		s(r);
		s(c);
		s(m);

		fs = r*c - m;

		if(fs == 1)
		{
			printf("Case #%d:\n",cno);
			handleone();
			continue;
		}

		if(r == 1 || c == 1)
		{
			printf("Case #%d:\n",cno);
			handlelinear();
			continue;
		}

		if(fs == 3 || fs == 5 || fs == 7 || fs == 2 || fs == 0)
		{
			printf("Case #%d:\nImpossible\n",cno);
			continue;
		}

		if(r == 2 || c == 2)
		{
			printf("Case #%d:\n",cno);
			handledual();
			continue;
		}

		solve(r,c);

		if(done == 1)
		{
			printf("Case #%d:\n",cno);
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(i == r-1 && j == c-1)
					{
						printf("c");
					}
					else if(mat[i][j] == mine)
						printf("*");
					else
						printf(".");
				}
				printf("\n");
			}
			continue;
		}

		solve(c,r);

		if(done == 1)
		{
			printf("Case #%d:\n",cno);
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(i == r-1 && j == c-1)
					{
						printf("c");
					}
					else if(mat[j][i] == mine)//
						printf("*");
					else
						printf(".");
				}
				printf("\n");
			}
			continue;
		}

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				mat[i][j] = mine;
			}
		}

		printf("Case #%d:\n",cno);
		spread(r,c);

	}

}
