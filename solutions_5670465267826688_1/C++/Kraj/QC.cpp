#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(int &x)
{
	x=0;
	bool check=false;
	register int c;
	do{
		c=gc();
		if(c=='-')
		check=true;
	}while(c<48 || c>57);
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(check)
	x=-x;
}
inline void rd(int &x)
{
	x=0;
	bool check=false;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}

}
inline void pd(int x)
{
	char c[11];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
inline void pdl(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int li[10001];
char c[10001];
int T[5][5];

int main()
{
	ifstream cin("QC1L.in");
	ofstream cout("QC1AL.txt");
	int t,i,ind=1,l,sign,a,b,d,str,j;
	long long int x,k;
	bool check;
	T[1][1]=1;
	T[1][2]=2;
	T[1][3]=3;
	T[1][4]=4;
	T[2][1]=2;
	T[2][2]=-1;
	T[2][3]=4;
	T[2][4]=-3;
	T[3][1]=3;
	T[3][2]=-4;
	T[3][3]=-1;
	T[3][4]=2;
	T[4][1]=4;
	T[4][2]=3;
	T[4][3]=-2;
	T[4][4]=-1;
	cin>>t;
	while(t--)
	{
		cin>>l;
		cin>>x;
		check=false;
		cin>>c;
		for(i=0;i<l;i++)
		{
			b=c[i]-103;
			li[i]=b;
		}
		
		if(x%4!=0)
		d=x%4;
		else
		d=4;
		j=l*d;
		a=sign=1;
		for(i=0;i<j;i++)
		{
			
			b=li[i%l];
			a=T[a][b];
			a=sign*a;
			if(a<0)
			sign=-1,a=-a;
			else
			sign=1;
		}
		a=sign*a;
		
		if(a==-1)
		{
		
			a=sign=1;
			x=1LL*x*l;
			for(k=0;k<x;k++)
			{
				b=li[k%(1LL*l)];
				a=T[a][b];
				a=sign*a;
				if(a==2)
				break;
				if(a<0)
					sign=-1,a=-a;
				else
				sign=1;	
			}
			k++;
			if(k<x)
			{
				a=sign=1;
				for(;k<x;k++)
				{
					b=li[k%(1LL*l)];
					a=T[a][b];
					a=sign*a;
					if(a==3)
					{
						check=true;
						break;
					}
					if(a<0)
					sign=-1,a=-a;
					else
					sign=1;
				}
			}
			
		}
		if(check)
		cout<<"Case #"<<ind++<<": "<<"YES"<<endl;
		else
		cout<<"Case #"<<ind++<<": "<<"NO"<<endl;
	}
}
