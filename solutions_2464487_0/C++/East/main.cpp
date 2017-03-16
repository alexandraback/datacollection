#include<stdio.h>

int solve(int r, int t)
{
	int next = r+1;
	int result = 0;
	while(t>0)
	{
		int newarea = next*next;
		int area = (next-1)*(next-1);
		int used = newarea - area;
		t -= used;
		if(t<0)
			break;
		else
			result++;
		area = newarea;
		next+=2;		
	}
	return result;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T,r,t;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%d %d",&r,&t);
		printf("Case #%d: %d\n",c,solve(r,t));
	}
}