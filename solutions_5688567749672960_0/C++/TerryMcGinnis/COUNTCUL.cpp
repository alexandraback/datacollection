#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

inline long long int fast_input(void)
{
	char t;
	long long int x=0;
	long long int neg=0;
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

inline void fast_output(long long int x)
{
	char a[20];
	long long int i=0,j;
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

inline long long int rev(long long int n)
{
	long long int temp=0,a=n;
	while(n)
	{
		temp=10*temp+n%10;
		n/=10;
	}
	if (a%10) return temp;
	else return a;
}

long long int mem[1000001];

inline long long int solve(long long int n)
{
	if (mem[n]) return mem[n];
	if (n==1) mem[n]=1;
	else if (rev(n)<n) mem[n]=1+min(solve(n-1),solve(rev(n)));
	else mem[n]=1+solve(n-1);
	return mem[n];
}

int main()
{
long long int t,i,n,ans;
t=fast_input();
for(i=1;i<=t;i++)
{
	n=fast_input();
	memset(mem,0,sizeof(mem));
	// ans=1;
	// while(n!=1)
	// {
	// 	if (rev(n)>=n) n--;
	// 	else n=rev(n);
	// 	ans++;
	// 	//if (n>0) fast_output(n);
 // 	}
	printf("Case #%lld: %lld\n",i,solve(n));
}
return 0;
}
