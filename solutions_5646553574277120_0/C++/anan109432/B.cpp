#include <bits/stdc++.h>
using namespace std;
int arr[100],arr1[100];
void fill(int ini,int d,int p[])
{
	int sum = 0;
	for (int i=0; i<d; i++)
		sum+=arr[i]*arr1[i];
	p[sum] = 1;
	if (ini == d)
		return;
	for (int i=ini; i<d; i++)
	{
		fill(i+1,d,p);
		arr1[i] = 1;
		fill(i+1,d,p);
		arr1[i] = 0;
	}
}
void f(int d,int p[])
{
	for (int i=0; i<d; i++)
	{
		fill(i+1,d,p);
		arr1[i] = 1;
		fill(i+1,d,p);
		arr1[i] = 0;
	}
}
int main()
{
	int t,m=1;
	cin>>t;
	while (t--)
	{
		int c,d,v;
		cin>>c>>d>>v;
		int hash[40];
		memset(hash,0,sizeof(hash));
		memset(arr,0,sizeof(arr));
		memset(arr1,0,sizeof(arr1));
		for (int i=0; i<d; i++){
			cin>>arr[i];
			arr1[i] = 0;
			hash[arr[i]] = 1;
		}
		cout<<"Case #"<<m++<<": ";
		int p[1000];
		memset(p,0,sizeof(p));
		f(d,p);
		/*for (int i=0; i<=v; i++)
			cout<<p[i]<<" ";
		cout<<endl;*/
		int count = 0;
		for (int i=1; i<=v; i++)
		{
			int flag1=0;
			for (int j=1; j<=v; j++){
				if (p[j]==0)
					flag1=1;
			}
			if (flag1==0)
				break;
			if (hash[i]==0)
			{
				arr[d] = i;
				arr1[d] = 0;
				hash[i] = 1;
				d++;
				++count;
				f(d,p);
			}
		}	
		cout<<count<<endl;
	}
	return 0;
}