#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
using namespace std;
typedef unsigned uint;
typedef unsigned char uchar;

typedef vector<uchar> LONGINT;

LONGINT li_zero, li_one;
LONGINT A, B, sqrA, sqrB;
uint count;

void li_normalize(LONGINT & x)
{
	if(x.size()==0) 
	{
		x.resize(1);
		x[0] = 0;
		return;
	}
	for(int i=x.size()-1; i>=0; i--)
	{
		if(x[i] != 0 || i == 0)
		{
			x.resize(i+1);
			return;
		}
	}
}
void li_from_uint(uint a, LONGINT & x)
{
	x.resize(20);
	for(int i=0; i<20; i++)
	{
		x[i] = a % 10;
		if(a==0) break;
		a = a / 10;
	}
	li_normalize(x);
}
void li_from_str(const char* s, LONGINT & x)
{
	char buf[16];
	buf[1] = 0;

	x.resize(strlen(s));
	for(int i=0; i<x.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			buf[0] = s[i];
			x[x.size()-1-i] = atoi(buf);
		}
		else throw "li_from_str(): invalid char";
	}
	li_normalize(x);
}
string li_to_str(const LONGINT & x)
{
	string s;
	s.resize(x.size());
	for(int i=0; i<x.size(); i++)
		s[i] = x[x.size()-1-i] + '0';
	return s;
}
int li_cmp(const LONGINT & a, const LONGINT & b)
{
	if(a.size() > b.size()) return  1;
	if(a.size() < b.size()) return -1;
	for(int i = a.size() - 1; i>=0; i--)
	{
		if(a[i] > b[i]) return 1;
		if(a[i] < b[i]) return -1;
	}
	return 0;
}
void li_mul(const LONGINT & a, const LONGINT & b, LONGINT & x)
{
	int i, j, k;
	uint tmp;

	x.resize(a.size() + b.size());
	for(i=0; i<x.size(); i++) x[i] = 0;

	for(i=0; i<a.size(); i++)
	{
		tmp = 0;
		for(j=0; j<b.size(); j++)
		{
			tmp = tmp + a[i] * b[j] + x[i+j];
			x[i+j] = tmp % 10;
			tmp = tmp / 10;
		}
		x[i + b.size()] = tmp;
	}
	li_normalize(x);
}
void li_add(const LONGINT & a, const LONGINT & b, LONGINT & x)
{
	uint tmp = 0;
	x.resize(max(a.size(), b.size())+1);
	for(int i=0; i<x.size(); i++)		x[i] = 0;
	for(int i=0; i<a.size(); i++)		x[i] = a[i];
	for(int i=0; i<b.size(); i++)		x[i] += b[i];
	for(int i=0; i<x.size(); i++)
	{
		tmp = tmp + x[i];
		x[i] = tmp % 10;
		tmp = tmp / 10;
	}
	li_normalize(x);
}
void li_sqr(const LONGINT & a, LONGINT & x)
{
	li_mul(a, a, x);
}
void li_sqrt_down(const LONGINT & a, LONGINT & x)
{
	LONGINT y;
	x.resize((a.size()+1)/2);
	for(int i=0; i<x.size(); i++) x[i] = 0;

	if(li_cmp(a, li_zero) > 0)
	{
		for(int i=x.size()-1; i>=0; i--)
		{
			for(x[i] = 1; x[i] < 10; x[i]++)
			{
				li_sqr(x, y);
				int cmp = li_cmp(y, a);
				if(cmp==0) goto exit;
				if(cmp>0) break;
			}
			x[i]--;
		}
	}

exit:
	li_normalize(x);
}
void li_sqrt_up(const LONGINT & a, LONGINT & x)
{
	LONGINT y;
	li_sqrt_down(a, x);
	li_sqr(x, y);
	if(0==li_cmp(a, y)) return;
	li_add(x, li_one, y);
	x = y;
}
void li_zeroall(LONGINT & x)
{
	if(x.size()) memset(&x[0], 0, x.size());
}
typedef void (*P_plndr_callback)(const LONGINT & p, void* param);
void gen_pldnr_call1(LONGINT & x, P_plndr_callback callback, void* param)
{
	callback(x, param);
	uint d = x.size();
	if(d%2)
	{
		x[d/2] = 1;
		callback(x, param);
		x[d/2] = 0;
	}
}
void gen_pldnr(uint d, P_plndr_callback callback, void* param)
{
	LONGINT x;
	int i, j, k;

	x.resize(d);
	li_zeroall(x);
	if(d==0) return;
	if(d==1)
	{
		for(i=0; i<=3; i++)
		{
			x[0] = i;
			callback(x, param);
		}
		return;
	}

	//2..0..2|2..1..2
	if(d>=2)
	{
		li_zeroall(x);
		x[0] = x[d-1] = 2;
		gen_pldnr_call1(x, callback, param);
	}

	//1..2..1
	if((d%2) && d>=3)
	{
		li_zeroall(x);
		x[d/2] = 2;
		x[d-1] = x[0] = 1;
		callback(x, param);
		if(d>=5)
		{
			for(i=1; i<d/2; i++)
			{
				x[i] = x[d-1-i] = 1;
				callback(x, param);
				x[i] = x[d-1-i] = 0;
			}
		}
	}

	//1..1
	if(d>=2)
	{
		li_zeroall(x);
		x[d-1] = x[0] = 1;
		gen_pldnr_call1(x, callback, param);

		if(d>=4)
		{
			for(i=1; i<d/2; i++)
			{
				x[i] = x[d-1-i] = 1;
				gen_pldnr_call1(x, callback, param);
				x[i] = x[d-1-i] = 0;
			}
		}

		if(d>=6)
		{
			for(i=1; i<d/2-1; i++)
			{
				x[i] = x[d-1-i] = 1;
				for(j=i+1; j<d/2; j++)
				{
					x[j] = x[d-1-j] = 1;
					gen_pldnr_call1(x, callback, param);
					x[j] = x[d-1-j] = 0;
				}
				x[i] = x[d-1-i] = 0;
			}
		}

		if(d>=8)
		{
			for(i=1; i<d/2-2; i++)
			{
				x[i] = x[d-1-i] = 1;
				for(j=i+1; j<d/2-1; j++)
				{
					x[j] = x[d-1-j] = 1;
					for(k=j+1; k<d/2; k++)
					{
						x[k] = x[d-1-k] = 1;
						gen_pldnr_call1(x, callback, param);
						x[k] = x[d-1-k] = 0;
					}
					x[j] = x[d-1-j] = 0;
				}
				x[i] = x[d-1-i] = 0;
			}
		}
	}
}
void plndr_callback(const LONGINT & p, void* param)
{
	//string s = li_to_str(p);
	//printf("s = %s\n", s.c_str());
	if(li_cmp(sqrA, p) <= 0 && li_cmp(p, sqrB) <= 0)
	{
		count++;
	}
}
uint solve()
{
	li_sqrt_up(A, sqrA);
	li_sqrt_down(B, sqrB);
	count = 0;

	for(int sz=sqrA.size(); sz<=sqrB.size(); sz++)
	{
		gen_pldnr(sz, plndr_callback, 0);
	}

	/*
	if(A.size()==B.size())
	{
	}
	else
	{
	}
	*/

	return count;
}
int _tmain(int argc, _TCHAR* argv[])
{
	li_from_uint(0, li_zero);
	li_from_uint(1, li_one);

	/*
	LONGINT x, y, z;
	string s;
	li_from_str("5374587428623763785234927483732457668234234", x);
	li_from_str("115678763254672348367982345345", y);
	li_mul(x, y, z);
	s = li_to_str(z);
	printf("s = %s\n", s.c_str());	

	li_from_str("00145", x);
	li_sqrt_up(x, z);
	s = li_to_str(z);
	printf("s = %s\n", s.c_str());
	*/

	uint cTask, t, i, j;
	char lineA[256], lineB[256];
	uint ret;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(t=1; t<=cTask; t++)
	{
		fscanf(fin, "%s %s\n", lineA, lineB);
		li_from_str(lineA, A);
		li_from_str(lineB, B);

		ret = solve();

		fprintf(fout, "Case #%u: %u\n", t, ret);
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
	return 0;
}

