#include <cstdio>
using namespace std;
typedef long long big;
big r,t,m;
int main()
{
	double ss;
	int Test,tt;
	int bs,sn;
	big ort;
	double a,b,c,mm;
	scanf(" %d",&Test);
	Test=5;
	for(tt=1;tt<=Test;tt++)
	{
		printf("Case #%d: ",tt);
		scanf(" %lld %lld",&r,&t);
		mm=m=(2*r+1)-4;
		bs=1; sn=1e9;
		while(bs<sn)
		{
			ort=(bs+sn+1)/2;
			ss=4*((ort)*(ort+1)/2)+mm*ort;
			if(ss > t) sn=ort-1;
			else bs=ort;
		}
		printf("%d\n",bs);
	} 
	return 0;
}