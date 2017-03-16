#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int x[8][8]=
{	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},
	{5,0,7,2,1,4,3,6},
	{6,3,0,5,2,7,4,1},
	{7,6,1,0,3,2,5,4}
};

const int inv[8]={0,5,6,7,4,1,2,3};

char in[10240];
int pat[10240];
int pre[40960];

bool solve()
{
	long long X,L;
	scanf("%lld%lld%s",&L,&X,in);
	for(int i = 0; i<L; i++)
		pat[i]=(in[i]=='i')?1:(in[i]=='j'?2:3);
	pre[0]=0;
	for(int i = 0; i<4*L; i++)
		pre[i+1]=x[pre[i]][pat[i%L]];
	// i = 1, ij = k = 3, ijk = -1
	// step 1: check if the total product is ijk == -1
	if(pre[(X%4)*L]!=4)
		return false;

	// step 2: find the leftmost i == 1
	long long leftmost_i=-1;
	for(int i = 1; i <= min(4LL,X)*L; i++)
	{
		if(pre[i]==1)
		{
			leftmost_i=i;
			break;
		}
	}
	if(leftmost_i==-1LL) return false;

	// step 3: find the rightmost ij == k == 3
	long long rightmost_k=-1;
	for(int i = (X%4)*L; i>0; i--)
	{
		if(pre[i]==3)
		{
			rightmost_k=(X&(~3LL))*L+i;
			break;
		}
	}
	for(int i = 4*L; i<=X*L && rightmost_k==-1 && i>0; i--)
	{
		if(pre[i]==3)
		{
			rightmost_k=((X&(~3LL)-4))*L+i;
			break;
		}
	}
	if(rightmost_k==-1LL) return false;

	return leftmost_i < rightmost_k;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i=1; i<=ncases; i++)
		printf("Case #%d: %s\n",i,solve()?"YES":"NO");
	return 0;
}
