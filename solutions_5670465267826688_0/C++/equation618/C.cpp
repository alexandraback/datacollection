#include <bits/stdc++.h>
using namespace std;

struct bg
{
	int x;
	bg(int _x=1) {x=_x;}
	friend bg operator *(bg A,bg B)
	{
		int t=1;
		if (A.x<0) A.x*=-1,t*=-1;
		if (B.x<0) B.x*=-1,t*=-1;
		if (A.x==1||B.x==1) return bg(A.x*B.x*t);
		if (A.x==2) return bg(B.x==2?-t:B.x==3?4*t:-3*t);
		if (A.x==3) return bg(B.x==2?-4*t:B.x==3?-t:2*t);
		if (A.x==4) return bg(B.x==2?3*t:B.x==3?-2*t:-t);
	}
	bg pow(int k)
	{
		k%=4;
		if (x==1) return 1;
		if (x==-1) return k&1?-1:1;
		if (!k) return 1;
		else if (k==1) return bg(x);
		else if (k==2) return -1;
		else return bg(-x);
	}
} a[100005];
int L,X;
char s[10005];

bool can()
{
	scanf("%d%d%s",&L,&X,s);
	for (int i=0; i<L*10; i++) a[i]=bg(s[i%L]=='i'?2:s[i%L]=='j'?3:4);
	bg s(1);
	for (int i=0; i<L; i++) s=s*a[i];
	if (s.pow(X).x!=-1) return 0;
	X=min(X,10),s=bg(1);
	for (int i=0; i<L*X; i++)
	{
		s=s*a[i];
		if (s.x==2) for (int j=i+1; j<L*X; j++)
		{
			s=s*a[j];
			if (s.x==4) return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: %s\n",i,can()?"YES":"NO");
	return 0;
}

