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

int main()
{
	int t,cno=0;
	s(t);
	double c,f,x,ctotal,new_ctotal,production,new_production,e1,e2,ec,sec,new_e;
	while(t--)
	{
		cno++;

		ctotal = 0;
		sec = 0;
		production = 2;

		cin>>c>>f>>x;

		while(1)
		{
			if(ctotal <= x+EPS && ctotal >= x-EPS)
				break;

			e1 = (x - ctotal)/production;

			if(ctotal >= c - EPS)
			{
				sec += e1;
				break;
			}
			else
				ec = (c - ctotal)/production;

			if(e1 <= ec + EPS)
			{
				sec += e1;
				break;
			}
			else
			{
				sec += ec;
				ctotal += (c - ctotal);
			}

			if(ctotal >= c - EPS)
			{
				new_production = production + f;
				new_ctotal = ctotal - c;
				new_e = (x - new_ctotal)/new_production;
				e2 = (x - ctotal)/production;

				if(new_e <= e2 + EPS)
				{
					production = new_production;
					ctotal = new_ctotal;
				}
			}

		}

		printf("Case #%d: %.7lf\n",cno,sec);

	}
}
