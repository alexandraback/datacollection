#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int n1;
int a[107]={0,};
int ans1[207];
char ans[300007][107];
int ansle[300007];
int an[207];
int an1[207];
int mul[207];

char in1[107];
char in2[107];
int le1,le2,la1,la2,ca;

bool IsPalin(__int64 v)
{
	int i,n;
	__int64 v1;
	n=0;
	while(v!=0)
	{
		a[++n]=v%10;
		v/=10;
	}
	int o=0;
	for(i=1;i<=n/2;i++)
		if(a[i]!=a[n-i+1])
		{
			o++;
			break;
		}
	return o==0;
}

void input()
{
	scanf("%s",&in1[1]);
	le1=strlen(&in1[1]);
	scanf("%s",&in2[1]);
	le2=strlen(&in2[1]);
}
void process()
{
	int i,j,k,o;
	la1=la2=-2;
	if(le1%2==0)
		la1=ans1[le1+1]-1;
	else
	{
		for(i=ans1[le1];i<ans1[le1+2];i++)
		{
			o=0;
			for(j=le1;j>=1;j--)
			{
				if(in1[le1-j+1]>ans[i][j])
				{
					o=1;
					break;
				}
				if(in1[le1-j+1]<ans[i][j])
				{
					o=2;
					break;
				}
			}
			if(o==0 || o==2)
			{
				la1=i-1;
				break;
			}
		}
		if(la1==-2)
		{
			la1=ans1[le1+2]-1;
		}
	}
	if(le2%2==0)
		la2=ans1[le2+1]-1;
	else
	{
		for(i=ans1[le2];i<ans1[le2+2];i++)
		{
			o=0;
			for(j=le2;j>=1;j--)
			{
				if(in2[le2-j+1]>ans[i][j])
				{
					o=1;
					break;
				}
				if(in2[le2-j+1]<ans[i][j])
				{
					o=2;
					break;
				}
			}
			if(o==0)
			{
				la2=i;
				break;
			}
			if(o==2)
			{
		//	printf("%s %s\n",&in2[1],&ans[i][1]);
				la2=i-1;
				break;
			}
		}
		if(la2==-2)
		{
			la2=ans1[le2+2]-1;
		}
	}
//	if(ca==32)
//		printf("%d %d\n",la1,la2);
}
void output()
{
	ca++;
	printf("Case #%d: %d\n",ca,la2-la1);
}

void findSP1(int leng,int nn,int le,int h1)
{
	int i,j;
//	printf("%d %d %d %d\n",leng,nn,le,h1);
	if(le==nn+1)
	{
		n1++;
		ansle[n1]=2*leng-1;
		an1[1]=1;
		for(i=1;i<=nn;i++)
			an1[i+1]=an[i];
		for(i=nn+2;i<=leng;i++)
			an1[i]=an1[leng-i+1];
		for(i=1;i<=leng*2+1;i++)
			mul[i]=0;
		for(i=1;i<=leng;i++)
			for(j=1;j<=leng;j++)
				mul[i+j-1]+=an1[i]*an1[j];
		for(i=1;i<=2*leng-1;i++)
		{
			ans[n1][i]=(mul[i]%10)+'0';
			mul[i+1]+=mul[i]/10;
			mul[i]/=10;
		}
		
		if(nn*2+1==leng && an1[nn+1]==1)
		{
			n1++;
			ansle[n1]=2*leng-1;
			an1[nn+1]=2;
			for(i=1;i<=leng*2+3;i++)
				mul[i]=0;
			for(i=1;i<=leng;i++)
				for(j=1;j<=leng;j++)
					mul[i+j-1]+=an1[i]*an1[j];
			for(i=1;i<=2*leng;i++)
			{
				ans[n1][i]=(mul[i]%10)+'0';
				mul[i+1]+=mul[i]/10;
				mul[i]/=10;
			}
			int ch=0;
			if(mul[2*leng]!=0 || mul[2*leng+1]!=0)
				ch=1;
			else
			{
				for(i=1;i<=leng;i++)
					if(ans[n1][i]!=ans[n1][2*leng-i])
					{
						ch++;
						break;
					}
			}
			if(ch!=0)
				n1--;
		}
	}
	else
	{
		if(h1>3){
			an[le]=0;
			findSP1(leng,nn,le+1,h1);
		}
		else if(h1==3 && (nn*2+1!=leng || le!=nn)){
			an[le]=0;
			findSP1(leng,nn,le+1,h1);
		}
		else
		{
			an[le]=0;
			findSP1(leng,nn,le+1,h1);
			an[le]=1;
			findSP1(leng,nn,le+1,h1+1);
		}
	}
}

int main()
{
	__int64 i,j,i1;
	int leng,nn;
	int t=0;
	ans1[1]=n1+1;
	n1++;
	ansle[n1]=1;
	ans[n1][1]='1';
	n1++;
	ansle[n1]=1;
	ans[n1][1]='4';
	n1++;
	ansle[n1]=1;
	ans[n1][1]='9';
	for(i1=2;i1<=50;i1++)
	{
		ans1[2*i1-1]=n1+1;
		for(j=1;j<=i1;j++)
			an[j]=0;
		findSP1(i1,(i1-1)/2,1,0);
		leng=i1,nn=(i1-1)/2;
		n1++;
		ansle[n1]=2*leng-1;
		an1[1]=an1[leng]=2;
		for(i=2;i<leng;i++)
			an1[i]=0;
		for(i=1;i<=leng*2+1;i++)
			mul[i]=0;
		for(i=1;i<=leng;i++)
			for(j=1;j<=leng;j++)
				mul[i+j-1]+=an1[i]*an1[j];
		for(i=1;i<=2*leng-1;i++)
		{
			ans[n1][i]=(mul[i]%10)+'0';
			mul[i+1]+=mul[i]/10;
			mul[i]/=10;
		}

		if(leng%2==1)
		{
			n1++;
			ansle[n1]=2*leng-1;
			an1[1]=an1[leng]=2;
			for(i=2;i<leng;i++)
				an1[i]=0;
			an1[nn+1]=1;
			for(i=1;i<=leng*2+1;i++)
				mul[i]=0;
			for(i=1;i<=leng;i++)
				for(j=1;j<=leng;j++)
					mul[i+j-1]+=an1[i]*an1[j];
			for(i=1;i<=2*leng-1;i++)
			{
				ans[n1][i]=(mul[i]%10)+'0';
				mul[i+1]+=mul[i]/10;
				mul[i]/=10;
			}
		}
	}
	ans1[101]=n1+1;
//	printf("%d\n",n1);
	//for(i=1;i<=n1;i++,printf("\n"))
	//	for(j=ansle[i];j>=1;j--)
	//		printf("%c",ans[i][j]);
	/*
	for(i=1;i<=1000000000;i++)
	{
		if(IsPalin(i))
			if(IsPalin(i*i))
				printf("%I64d %I64d\n",i,i*i);
	}*/
	freopen("C-large-1.in","rt",stdin);
	freopen("C-large-1.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		input();
		process();
		output();
	}
	return 0;
}