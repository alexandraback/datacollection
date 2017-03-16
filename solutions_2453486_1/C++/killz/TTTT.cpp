#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define REP(x,y) for(x=0;x<y;x++)
#define REPI(x,y) for(x=1;x<=y;x++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;

int N,M,n,m,k,i;
string s[10];

int main()
{
    int a,b,c,d,R,xx,X=0,O=0;
	N=4;
	cin >> R;
	REP(xx,R)
	{
		X=O=0;
		cin >> s[0];
		cin >> s[1];
		cin >> s[2];
		cin >> s[3];
		REP(a,N)
		{
			c=0;
			d=0;
			REP(b,N)
			{
				if(s[a][b]=='O')
					c++;
				if(s[a][b]=='X')
					d++;
				if(s[a][b]=='T'){
					c++;d++;
				}
			}
			if(c==4)O=1;
			if(d==4)X=1;
		}
		REP(b,N)
		{
			c=0;
			d=0;
			REP(a,N)
			{
				if(s[a][b]=='O')
					c++;
				if(s[a][b]=='X')
					d++;
				if(s[a][b]=='T'){
					c++;d++;
				}
			}
			if(c==4)O=1;
			if(d==4)X=1;
		}
		c=0;d=0;
		REP(a,N)
		{
			if(s[a][a]=='O')
				c++;
			if(s[a][a]=='X')
				d++;
			if(s[a][a]=='T'){
				c++;d++;
			}
			if(c==4)O=1;
			if(d==4)X=1;
//			printf("%d: %d %d\n",xx,c,d);
		}
		c=0;d=0;
		REP(a,N)
		{
			if(s[a][4-a-1]=='O')
				c++;
			if(s[a][4-a-1]=='X')
				d++;
			if(s[a][4-a-1]=='T'){
				c++;d++;
			}
			if(c==4)O=1;
			if(d==4)X=1;
		}
		printf("Case #%d: ",xx+1);
		if(O==1)
		{
			printf("O won\n");
		}
		else if(X==1)
		{
			printf("X won\n");
		}
		else
		{
			c=0;
			REP(a,N)REP(b,N)
			{
				if(s[a][b]=='.')c=1;
			}
			if(c==1)printf("Game has not completed\n");
			else printf("Draw\n");
		}

	}
    return 0;
}
