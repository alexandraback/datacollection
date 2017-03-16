#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
ifstream in("c.in");
ofstream out("c.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
int a[10], b[10];
int main()
{
	int T, i, j, k, n, m, r, v1,v2,v3, ii, jj;
	in>>T;
	in>>r>>n>>m>>k;
	out<<"Case #1:"<<endl;
	fo(i, 1, r)
	{
		int best=0;
	    int ansv1=2, ansv2=2, ansv3=2;
		fo(j, 1, k)
			in>>a[j];
		fo(v1, 2, m)
			fo(v2, 2, m)
			  fo(v3, 2, m)
		{
			b[1]=1;
			b[2]=v1;
			b[3]=v1*v2;
			b[4]=v1*v3;
			b[5]=v1*v2*v3;
			b[6]=v2;
			b[7]=v2*v3;
			b[8]=v3;
			int now=1;
			fo(ii, 1, k)
			{
				int tmp=0;
				fo(jj, 1, 8)
					tmp+=( b[jj]==a[ii]);
				now*=tmp;
			}
			if (now>best)
			{
				best=now;
				ansv1=v1;
				ansv2=v2;
				ansv3=v3;
			}
		}
		out<<ansv1<<ansv2<<ansv3<<endl;
	}
}