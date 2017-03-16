#include<bits/stdc++.h>
using namespace std;
int M[5][5]={0,0,0,0,0,
	         0,1,2,3,4,		//M[i][j]=i*j
	         0,2,-1,4,-3,
	         0,3,-4,-1,2,
	         0,4,3,-2,-1
			 };
			 
int D[5][5]={0,0,0,0,0,		//D[i][j]=i/j
	         0,1,-2,-3,-4,
	         0,2,1,4,-3,
	         0,3,-4,1,2,
	         0,4,3,-2,1
			 };
			 
int store[10005];

int val(char c)
{
	if(c=='i')
	return 2;
	if(c=='j')
	return 3;
	if(c=='k')
	return 4;
}

int main()
{

    freopen("in3.txt", "r", stdin);
  freopen("3.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t,l,x,len;
	cin>>t;
	string s,temp;
	for(int i=1; i<=t; i++)
	{
		cin>>l>>x;
		cin>>s;
		temp=s;
		len=l*x;
		for(int j=0; j<x-1; j++)
		s=s+temp;
	//	cout<<s<<endl;
		store[1]=val(s[0]);
		for(int j=2; j<=len; j++)
		{
			if(store[j-1]>0)
			store[j]=M[abs(store[j-1])][val(s[j-1])];
			else
			store[j]=-M[abs(store[j-1])][val(s[j-1])];
		}
	//	for(int j=1; j<=len; j++)
	//	cout<<store[j]<<" ";
	//	cout<<endl;
		bool flag=false;
		int a1,a2,a3,t1,t2,t3;
		for(int j=1; j<=len; j++)
		{
			for(int k=j+1; k<=len; k++)
			{
				a1=store[j];
				a2=store[k];
				a3=store[len];
				
				if(a1!=2)
				continue;
				
				if(a1>0 && a2>0 || a1<0 && a2<0)
				t1=D[abs(a2)][abs(a1)];
				else
				t1=-D[abs(a2)][abs(a1)];;
				
				if(a2>0 && a3>0 || a1<0 && a2<0)
				t2=D[abs(a3)][abs(a3)];
				else
				t2=-D[abs(a3)][abs(a2)];;
				
				if(t1==3 && t2==4)
				{
					j=len+1;
					flag=true;
					break;
				}
			}
		}
		if(flag)
		cout<<"Case #"<<i<<": "<<"YES"<<endl;
		else
		cout<<"Case #"<<i<<": "<<"NO"<<endl;
	}
	return 0;
}
