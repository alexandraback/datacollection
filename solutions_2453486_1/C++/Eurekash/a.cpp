#include <cstdio>
#include <cstring>

typedef long long LL;

int check(const LL &S)
{
	int X,O,p;
	for(int i=0;i<32;i+=8)
	{
		X=0,O=0;
		for(int j=0;j<8;j+=2)
		{
			p=(S>>(i+j))&3;
			if(p&1)  ++X;
			if(p&2)  ++O;
		}
		if(X==4)  return 1;
		if(O==4)  return -1;
	}
	for(int i=0;i<8;i+=2)
	{
		X=0,O=0;
		for(int j=0;j<32;j+=8)
		{
			p=(S>>(i+j))&3;
			if(p&1)  ++X;
			if(p&2)  ++O;
		}
		if(X==4)  return 1;
		if(O==4)  return -1;
	}
	X=0,O=0;
	for(int i=0;i<32;i+=10)
	{
		p=(S>>i)&3;
		if(p&1) ++X;
		if(p&2) ++O;
	}
	if(X==4)  return 1;
	if(O==4)  return -1;
	X=0,O=0;
	for(int i=6;i<30;i+=6)
	{
		p=(S>>i)&3;
		if(p&1) ++X;
		if(p&2) ++O;
	}
	if(X==4)  return 1;
	if(O==4)  return -1;
	return 0;
}

int main()
{
	char s[5];
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		LL S=0;
		int nX=0,nO=0,nT=0,ret;
		for(int i=0;i<4;++i)
		{
			scanf("%s",s);
			for(int j=0;j<4;++j)
			{
				S<<=2;
				if(s[j]=='X')  S^=1,++nX;
				if(s[j]=='O')  S^=2,++nO;
				if(s[j]=='T')  S^=3,++nT;
			}
		}
		ret=check(S);
		printf("Case #%d: ",t);
		if(ret==1)  puts("X won");
		else if(ret==-1)  puts("O won");
		else if(nX+nO+nT==16)
			puts("Draw");
		else
			puts("Game has not completed");
	}
	return 0;
}
