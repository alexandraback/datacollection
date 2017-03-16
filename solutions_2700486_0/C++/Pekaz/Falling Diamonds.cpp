#include <stdio.h>

int l,r,need;
long long int sum,cnt;
int n;

struct diamondinfo
{
	int x;
	int y;
};
diamondinfo diamond[22],re;

void filldia(int x)
{
	if(x==n)
	{
		sum++;
		for(int i=0;i<n;i++)
		{
			if(diamond[i].x==re.x && diamond[i].y==re.y)
			{
				cnt++;
				break;
			}
		}
		return;
	}
	if(x==0)
	{
		diamond[x].x=0;
		diamond[x].y=0;
		l=r=0;
		filldia(x+1);
		return;
	}
	else
	{
		if(l==need && r==need)
		{
			diamond[x].x=0;
			diamond[x].y=need;
			l = r = 0;
			need+=2;
			filldia(x+1);
			need-=2;
			l=need;
			r=need;
			return;
		}
		else if(l==need)
		{
			diamond[x].x=need-r;
			diamond[x].y=r;
			r++;
			filldia(x+1);
			r--;
			return;
		}
		else if(r==need)
		{
			diamond[x].x=-1*need+l;
			diamond[x].y=l;
			l++;
			filldia(x+1);
			l--;
			return;
		}
		
		diamond[x].x=-1*need+l;
		diamond[x].y=l;
		l++;
		filldia(x+1);
		l--;
	
		diamond[x].x=need-r;
		diamond[x].y=r;
		r++;
		filldia(x+1);
		r--;
	}
}

int main()
{
	int t,tcase;
	FILE *in,*out;
	in=fopen("B-small-attempt3.in","r");
	out=fopen("output.out","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d",&n);
		fscanf(in,"%d",&re.x);
		fscanf(in,"%d",&re.y);

		sum = cnt = 0;
		need = 2;
		l = r = 0;
		if(re.x ==0 && re.y == 0)
		{
			fprintf(out,"Case #%d: 1.0\n",t+1);
			continue;
		}
		filldia(0);
		fprintf(out,"Case #%d: %.6lf\n",t+1,(float)cnt/(float)sum);
	}

	return 0;
}