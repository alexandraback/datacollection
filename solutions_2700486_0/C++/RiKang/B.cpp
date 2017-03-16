#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int ca,n,le,le1,m;
int x,y;
double la;

void input()
{
	int i,j;
	le=1;
	le1=1;
	scanf("%d %d %d",&n,&x,&y);
	m=n;
	while(true){
		if(le1>=n)
			break;
		m=n-le1;
		++le;
		le1=((2*le-1)*(2*le))/2;
	}
}

int abab(int xy)
{
	if(xy<0)
		return (-1)*xy;
	return xy;
}

void process()
{
	int i,j,o;
	double la1,la2;
	la=0.0;
				//if(ca==8)
			//	printf("%d %d\n",(2+abab(x)+abab(y))/2,le);
	if((2+abab(x)+abab(y))/2>le)
		la=0.0;
	else if((2+abab(x)+abab(y))/2<le)
		la=1.0;
	else{
		if(le1==n)
			la=1.0;
		else if(x==0)
			la=0.0;
		else if(m>=le+y+1)
				la=1.0;
			else{
			for(i=y+1;i<=m;i++)
			{				
				la2=1.0;
				o=1;
				for(j=y+1;j<i;++j)
				{
					la2*=j;
					la2/=(j-y);
					for(;o<=i;++o){
						la2/=2;
						if(la2<=100000000){
							++o;
							break;
						}
					}
				}
				for(;o<=i;++o)
					la2/=2;
				la+=la2;
//	if(ca==23)
//		printf("%lf\n",la2);
			
			}
		}
	}
}
void output()
{
	la+=0.000000001;
	printf("Case #%d: %.9lf\n",ca,la);
}

int main()
{
	int i,t;
	freopen("B-small-attempt3.in","rt",stdin);
	freopen("B-small-attempt3.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		input();
		process();
		output();
	}
	return 0;
}