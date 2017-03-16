#include <iostream>
#include <vector>
using namespace std;

int arr[1000000];
int rev(int a)
{
	int rever=0;
	while (a)
	{
		rever=rever*10+a%10;
		a/=10;
	}
	return rever;
}
void f(int n,int c,int m)
{
	cout<<"HI"<<" "<<n<<" "<<c<<" "<<arr[n]<<endl;
	if (n>m*40000)
		return; 
	if (arr[n]==-1)
		arr[n]=c;
	else
	{
		arr[n]=min(arr[n],c);
	}
	if (arr[n+1]==-1 or arr[n+1]>c+1)
			f(n+1,c+1,m);
		n=rev(n);
		if (arr[n]==-1 or arr[n]>c+1)
			f(n,c+1,m);
		n=rev(n);
		if (arr[n]==-1 or arr[n]>c+1)
			f(n,c+1,m);
}

void cost(int n)
{
	if (n==21) cout<<n<<" "<<arr[n]<<endl;
	int m=rev(n);
	if (arr[m]>arr[n]+1)
	{
		arr[m]=arr[n]+1;
		cost(m);
	}
	n=m;
	m=rev(n);
	if (arr[m]>arr[n]+1)
	{
		arr[m]=arr[n]+1;
		cost(m);
	}
}

static vector<vector<int> > G;
void make(int i)
{
	int k;
//	cout<<"HI"<<endl;
	G[i].push_back(i+1);
//	cout<<"HI"<<endl;
	int j=rev(i);
	if (j!=i)
	{
		G[i].push_back(j);
		k=rev(j);
		if (k!=i and k!=j)
		{
			G[i].push_back(k);
			
		}
	}
}

int main()
{
	int i,x,n,t,j;
	G.clear();
	G.resize(1000001);
	for (i=0;i<1000002;i++) arr[i]=i;
//	f(1,1,1);
//	f(40001,arr[40000]+1,2);
//	cout<<"HI"<<endl;
	for (i=1;i<1000002;i++)
	{
//		cout<<i<<endl;
//		cost(i);
		make(i);
	}
	for (i=1;i<1000002;i++)
	{
		for (j=0;j<G[i].size();j++)
		{
			arr[G[i][j]]=min(arr[G[i][j]],arr[i]+1);
		}
	}
	cin>>t;
	int tt=1;
	while (tt<=t)
	{
		cin>>n;
		cout<<"Case #"<<tt<<": "<<arr[n]<<endl;
		tt+=1;
	}
}