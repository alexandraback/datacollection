#include<stdio.h>
#include<string.h>
//1,-1,2,-2,3,-3,4,-4

int isneg(int val)
{
	if(val>=0)
		return 1;
	else 
		return -1;
}
int rettype(char c)
{
	if(c=='i')
		return 2;
	if(c=='j')
		return 3;
	if(c=='k')
		return 4;
}
int exval(int a,long long int b)
{
	int j=1;
	if(a>0)
	{
		if(a==1)
			return 1;
		if(b%4==0)
			return 1;
		if(b%4==1)
			return a;
		if(b%4==2)
			return -1;
		if(b%4==3)
			return -a;	
	}
	else {
		if(b%2==1)
			j=-1;
		if(a==-1)
			return j;
		if(b%4==0)
			return 1;
		if(b%4==1)
			return a;
		if(b%4==2)
			return -1;
		if(b%4==3)
			return -a;	
	}
}
int a[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int findmul(char s[],int start,int end)
{
	int res=1,i;
	for(i=start;i<=end;i++)
		res=a[abs(res)][rettype(s[i])]*isneg(res);
	return res;
}
int main()
{
 int t;
 int i;
 char s[10005],check[80005];
 int l,j,k,flag,r=1,res=1,end;
 long long int x;
 //printf("%d\n",findmul("iijjkk",0,5));
// return;
 for(scanf("%d",&t),i=1;i<=t;i++)
 {
	 scanf("%d%lld",&l,&x);
	 scanf("%s",s);
	 //printf("%d %s\n",x,s);
	 if(l*x<3)
	{
		printf("Case #%d: NO\n",i);
		continue;
	}
	r=findmul(s,0,l-1);
	//printf("%d %d\n",r,exval(r,x));
	if(exval(r,x)!=-1)
		printf("Case #%d: NO\n",i);	 
	else
	{
		strcpy(check,s);
		if(x>4)
			x=4+x%4;
		for(j=1,end=l;j<(x);j++,end+=l)
			strcat(check,s);
		//printf("%s %d\n",check,end);
		for(j=0,res=1;j<=end;j++)
		{
			res=a[abs(res)][rettype(check[j])]*isneg(res);
	        if(res==2)
				break;
		}
		if(j>end)
		{
			printf("Case #%d: NO\n",i);
			continue;
		}
		res=1;
		//printf("h%d",j);
		for(j++;j<=end;j++)
		{
			res=a[abs(res)][rettype(check[j])]*isneg(res);
	        if(res==3)
				break;
		}
		if(j>=end)
		{
			printf("Case #%d: NO\n",i);
			continue;
		}		
		//printf("h%d",j);
		printf("Case #%d: YES\n",i);
	}
		
 }
 return 0;
}