#include <bits/stdc++.h>
using namespace std;

int a1[1005];
int b1[1005];

int fabsi(int a)
{
	return (a>0)?a:(-a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string str="Case #";


	for(int w=1;w<=t;w++)
	{
		string a,b;
		cin>>a>>b;

		int n=a.size();
	//	int a1=0,a2=0;
		int number=0;
		int cur=0;
		int v[3];
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
		for(int k=0;k<=9;k++)
		{
			v[0]=i;
			v[1]=j;
			v[2]=k;
			for(int l=0;l<n;l++)
				if(a[l]=='?')
					a1[cur]=a1[cur]*10+v[l];
				else a1[cur]=a1[cur]*10+(a[l]-'0');

				cur++;
		}	
		cur=0;
		for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
		for(int k=0;k<=9;k++)
		{
			v[0]=i;
			v[1]=j;
			v[2]=k;
			for(int l=0;l<n;l++)
				if(b[l]=='?')
					b1[cur]=b1[cur]*10+v[l];
				else b1[cur]=b1[cur]*10+(b[l]-'0');

				cur++;
		}

		int num1=a1[0],num2=b1[0];
		int d=fabsi(num1-num2);
		for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
		{
			int p=a1[i];
			int q=b1[j];
			int diff=fabsi(p-q);
			if(diff<d)
			{
				d=diff;
				num1=p;
				num2=q;
				continue;
			}
			if(diff>d)
				continue;
			if(p>num1)
				continue;
			if(p<num1)
			{
				num1=p;
				num2=q;
				continue;
			}
			if(q<num2)
				num2=q;


		}	
		string ans1="",ans2="";
		while(num1>0)
		{
			d=num1%10;

			ans1=(char)('0'+d)+ans1;
			num1/=10;
		}
		while(num2>0)
		{
						d=num2%10;

			ans2=(char)('0'+d)+ans2;
			num2/=10;
		}
		while(ans1.size()<n)
			ans1="0"+ans1;
		while(ans2.size()<n)
			ans2="0"+ans2;
		cout<<str<<w<<": "<<ans1<<" "<<ans2<<endl;
	}

	return 0;
}