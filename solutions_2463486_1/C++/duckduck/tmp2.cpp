#include <stdio.h>
#include <string.h>

const int maxl=201;

int l[maxl+1],r[maxl+1],m[maxl+1],sq[maxl+1],tar[maxl+1];
char s[maxl];
int i,j,k,n,t,tt;
long long ans,ansa,ansb,t1,t2,t3;

void clean(int *a)
{
	int i;

	for (i=0;i<=maxl;i++)
		*(a+i)=0;
}

void clear(int *a)
{
	int i;

	for (i=maxl;i>0;i--)
	{
		*(a+i-1)+=*(a+i)/10;
		*(a+i)%=10;
		if (*(a+i)<0)
		{
			*(a+i-1)-=1;
			*(a+i)+=10;
		}
	}
}

int compare(int *a,int *b)
{
	int i;

	for (i=0;i<=maxl;i++)
	{
		if (*(a+i)<*(b+i))
			return -1;
		if (*(a+i)>*(b+i))
			return 1;
	}
	return 0;
}

void add(int *a,int *b,int *c)
{
	int i;

	for (i=0;i<=maxl;i++)
		*(c+i)=*(a+i)+*(b+i);
	clear(c);
}

void div(int *a)
{
	int i,j;

	j=0;
	for (i=0;i<=maxl;i++)
	{
		j=j*10+*(a+i);
		*(a+i)=j/2;
		j%=2;
	}
}

void copy(int *a,int *b)
{
	int i;

	for (i=0;i<=maxl;i++)
		*(a+i)=*(b+i);
}

void mul(int *a,int *b,int *c)
{
	int i,j;

	clean(c);
	for (i=0;i<=maxl;i++)
		if (*(a+i)!=0)
			for (j=0;j<=maxl;j++)
				if (*(b+j)!=0)
					*(c+i+j-maxl)+=*(a+i)* *(b+j);
	clear(c);
}

void initial(int bas)
{
	int i,j,len;

	len=strlen(s);
	clean(r);
	clean(tar);

	for (i=0;i<len;i++)
		tar[maxl-len+1+i]=s[i]-'0';
	tar[maxl]-=bas;
	clear(tar);
}

void find()
{
	int i;

	clean(l);
	
	copy(r,tar);

	while (compare(l,r)<1)
	{
		add(l,r,m);
		div(m);
		mul(m,m,sq);
		if (compare(sq,tar)<1)
		{
			copy(l,m);
			l[maxl]++;
			clear(l);
		}
		else
		{
			copy(r,m);
			r[maxl]--;
			clear(r);
		}
	}
	copy(m,l);
	m[maxl]--;
	clear(m);
}

void work()
{
	int i,j,st,len,hlen;
	bool out=false;

	ans=0;
	for (st=0;st<=maxl;st++)
		if (m[st]!=0)
			break;

	len=maxl-st+1;
	hlen=(len+1)/2;

	if (len<=0)
		return;

	if (len==1)
	{
		ans=m[maxl];
		if (ans>3)
			ans=3;
		return;
	}
	ans=3;
	for (i=2;i<len;i++)
	{
		ans++;//2**2
		t1=(i+1)/2;
		t1--;
		t2=1;
		ans+=(t2<<t1);
		if ((i%2)==1)
			ans+=1+t1;
	}

	for (i=st;i<st+hlen;i++)
	{
		for (j=0;j<m[i];j++)
		{
			if ((i!=st)||(j!=0))
			{
				t1=st+hlen-1-i;
				t2=1;
				ans+=(t2<<t1);
			}
			if (j>=1)
			{
				out=true;
				break;
			}
		}
		if (out)
			break;
	}
	if (!out)
	{
		copy(sq,m);
		for (i=st;i<st+hlen;i++)
			sq[maxl-(i-st)]=sq[i];
		if (compare(sq,m)<1)
			ans++;
	}
	clean(sq);
	sq[st]=2;
	sq[maxl]=2;
	if (compare(sq,m)<1)
		ans++;
	if ((len%2)==1)
	{
		sq[st+hlen-1]=1;
		if (compare(sq,m)<1)
			ans++;
		sq[st]=1;
		sq[maxl]=1;
		sq[st+hlen-1]=2;
		if (compare(sq,m)<1)
			ans++;
		for (i=st+1;i<st+hlen-1;i++)
		{
			sq[i]=sq[maxl-(i-st)]=1;
			if (compare(sq,m)<1)
				ans++;
			sq[i]=sq[maxl-(i-st)]=0;
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%s ",s);
		initial(1);
		find();
		work();
		ansa=ans;
		scanf("%s\n",s);
		initial(0);
		find();
		work();
		ansb=ans;
		printf("Case #%d: %lld\n",tt,ansb-ansa);
	}
	return 0;
}