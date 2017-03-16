#include<cstdio>
#include<algorithm>

using namespace std;

int R,C,W;

int minmax(int,int);
int maxmin(int,int,int);

inline int bitcount(int x)
{
	int ret=0;
	for(ret=0;x;x>>=1)
		ret+=(x&1);
	return ret;
}

bool check(int x)
{
	int pat=(1<<W)-1;
//	printf("%x %x\n",pat,x);
	while(x)
		if((x&pat)==pat) return true;
		else x>>=1;
	return false;
}

int minmax(int board,int hit)
{
	if(check(board&hit))
		return bitcount(hit);
	int ret=C+1;
	for(int i = 1; i < (1<<C); i<<=1)
	{
		if(i & hit) continue;
		int tmp=maxmin(board,hit,i);//,new_board);
		if(tmp<ret)
			ret=tmp;
	}
	return ret;
}

bool zero(int board, int hit, int new_hit)
{
	for(int ship=(1<<W)-1; 0==(ship&(1<<C)); ship<<=1)
	{
		if((ship & hit) == board && (ship & new_hit) == 0)
			return true;
	}
	return false;
}

bool one(int board, int hit, int new_hit)
{
	for(int ship=(1<<W)-1; 0==(ship&(1<<C)); ship<<=1)
	{
		if((ship & hit) == board && (ship & new_hit))
			return true;
	}
	return false;
}

int maxmin(int board,int hit,int new_hit)
{
	int ret1=0, ret0=0;
	if(zero(board,hit,new_hit))
		ret0=minmax(board,hit|new_hit);
	if(one(board,hit,new_hit))
		ret1=minmax(board|new_hit,hit|new_hit);
	return max(ret0,ret1);
}

int solve()
{
	scanf("%d%d%d",&R,&C,&W);
	// R == 1
	return minmax(0,0);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i =1; i<=T; i++)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
