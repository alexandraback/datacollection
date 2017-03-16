//mohit____the_____great______and_________powerful_______!!!
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first 
#define se second
#define pb push_back  
#define mp make_pair

int main()
{
	//freopen()
	freopen("inp.txt","r",stdin);
	 freopen("out.txt","w",stdout);
	ll a ,t, i ,j , k ,fre[10008], l, n, arr[10005] ,r;
	cin>>t;
	l=1;
	while(t--)
	{	r=0;
		cin>>n;
		memset(fre,0,sizeof(fre));
		for(i=1;i<=2*n-1;i++)
		{
			for(j=1;j<=n;j++)
			{cin>>a;fre[a]++;}
		}
		for(i=0;i<=10000;i++)
		{
			if(fre[i]%2==1)
				arr[r++]=i;
		}
 	sort(arr,arr+r);
 	cout<<"Case #"<<l<<": ";
 	l+=1;
 	for(i=0;i<r;i++)
 		cout<<arr[i]<<" ";
 	cout<<endl;
	}

	
}