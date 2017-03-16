#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

inline int fast_input(void)
{
	char t;
	int x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
        x=(x<<3)+(x<<1)+t-48;
        t=getchar();
    }
	if(neg)
		x=-x;
	return x;
}

inline void fast_output(int x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

int main()
{
int t,i,r,c,w,ans;
t=fast_input();
for(i=1;i<=t;i++)
{
r=fast_input();
c=fast_input();
w=fast_input();
ans=c/w;
ans*=r;
ans+=w;
if (c%w==0) ans--;
printf("Case #%d: ",i);
fast_output(ans);
}
return 0;
}