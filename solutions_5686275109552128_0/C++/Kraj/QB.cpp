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

int arr[1001];
int main()
{
	ifstream cin("QB1.in");
	ofstream cout("QB1A.txt");
	int t,n,i,j,ind=1,mx,a,lo,high,mid,ans;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		mx=-1;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			mx=max(mx,arr[i]);
		}
		lo=1,high=mx;
		ans=mx;
		for(j=mx-1;j>0;j--)
		{
			
			a=j;
			for(i=0;i<n;i++)
			{
				if(arr[i]>j)
				{
					a+=(arr[i]/j)+((arr[i]%j)!=0)-1;
				}
			}
			if(a<ans)
				ans=a;
		
			
		}	
		cout<<"Case #"<<ind++<<": "<<ans<<endl;
		
	}
}
