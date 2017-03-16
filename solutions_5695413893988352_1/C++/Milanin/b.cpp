#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
#define N 25
char a[N], b[N];
long long d[N], ma[N], mb[N];
void upd(int i, long long xd, long long xa, long long xb)
{
	if(d[i]==-1 || xd<d[i] || (xd==d[i] && xa<ma[i]) || (xd==d[i] && xa==ma[i] && xb<mb[i])) { d[i]=xd; ma[i]=xa, mb[i]=xb; }
}
void sol()
{
	scanf("%s%s", a, b);
	int n=strlen(a);
	/*int pp[4]={0, 10, 100, 1000};
	int best=10000, besta, bestb;
	for(int za=0; za<pp[n]; za++)
	{
		int i;
		char s[10];
		sprintf(s, "%%0%dd", n);
		sprintf(s, s, za);
		for(i=0; i<n && s[i]==a[i] || a[i]=='?'; i++);
		if(i<n) continue;
		for(int zb=0; zb<pp[n]; zb++)
		{
			sprintf(s, "%%0%dd", n);
			sprintf(s, s, zb);
			for(i=0; i<n && s[i]==b[i] || b[i]=='?'; i++);
			if(i<n) continue;
			int df=abs(za-zb);
			if(df<best) { best=df; besta=za; bestb=zb; } 
		}
	}
	*/
	d[n]=0;
	ma[n]=0;
	mb[n]=0;
	for(int i=n-1; i>=0; i--)
	{
		d[i]=-1;
		for(int aa=0; aa<10; aa++)
			if(a[i]=='?' || a[i]-'0'==aa)
				for(int bb=0; bb<10; bb++)
					if(b[i]=='?' || b[i]-'0'==bb)
						if(aa>bb)
						{
							long long xa=aa, xb=bb;
							for(int j=i+1; j<n; j++)
							{
								xa*=10; xb*=10;
								if(a[j]=='?') xa+=0;
								else xa+=a[j]-'0';
								if(b[j]=='?') xb+=9;
								else xb+=b[j]-'0';
							}
							upd(i, xa-xb, xa, xb);
						}
						else if(aa<bb)
						{
							long long xa=aa, xb=bb;
							for(int j=i+1; j<n; j++)
							{
								xa*=10; xb*=10;
								if(a[j]=='?') xa+=9;
								else xa+=a[j]-'0';
								if(b[j]=='?') xb+=0;
								else xb+=b[j]-'0';
							}
							upd(i, xb-xa, xa, xb);
						}
						else 
						{
							long long p=1;
							for(int j=i+1; j<n; p*=10, j++);
							upd(i, d[i+1], aa*p+ma[i+1], bb*p+mb[i+1]);
						}
	}
	//if(best!=d[0] || besta!=ma[0] || bestb!=mb[0]) fprintf(stderr, "%s %s\n", a, b);
	sprintf(a, "%%0%dlld %%0%dlld\n", n, n);
	printf(a, ma[0], mb[0]);
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		sol();
	}
	return 0;
}