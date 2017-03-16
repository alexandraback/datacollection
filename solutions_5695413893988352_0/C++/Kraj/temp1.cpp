#include<bits/stdc++.h>
using namespace std;
int arr[26];
string S[10];
int cnt[10];
string str,a,b,str1;
int mn,mnv,mnv1,l;
void func(int ind,int val1,int val2)
{
	
	if(ind==l)
	{
		int val=abs(val1-val2);
		if(mn>val)
		mn=val,mnv=val1,mnv1=val2,a=str,b=str1;
		else if(mn==val)
		{
			if(mnv>val1)
			mnv=val1,mnv1=val2,a=str,b=str1;
			else if(mnv==val1)
			{
				if(mnv1>val2)
				mnv1=val2,b=str1;
			}
		}
		return;
		
	}
	val1*=10,val2*=10;
	if(str[ind]=='?' &&str1[ind]=='?')
	{
		for(int i=0;i<10;i++)
		{
			val1+=i;
			str[ind]=i+'0';
			for(int j=0;j<10;j++)
			{
				val2+=j;
				str1[ind]=j+'0';
				func(ind+1,val1,val2);
				val2-=j;
				str1[ind]='?';
			}
			val1-=i;
			str[ind]='?';
			
		}
		
	}
	else if(str[ind]=='?')
	{
		val2+=(str1[ind]-'0');
		for(int i=0;i<10;i++)
		{
			val1+=i;
			str[ind]=i+'0';
			func(ind+1,val1,val2);
			val1-=i;
			str[ind]='?';
		}
		
		
	}
	else if(str1[ind]=='?')
	{
		
		val1+=(str[ind]-'0');
		for(int i=0;i<10;i++)
		{
			val2+=i;
			str1[ind]='0'+i;
			func(ind+1,val1,val2);
			str1[ind]='?';
			val2-=i;
		}
	}
	else
	{
		val1+=(str[ind]-'0');
		val2+=(str1[ind]-'0');
		func(ind+1,val1,val2);
	}
	
	
}
int main()
{
	ifstream cin("1B2s.in");
	ofstream cout("1B2sA.txt");
	int i,j,k,t,m,n,ind=1;
	
	
	cin>>t;
	while(t--)
	{
		cin>>str;
		cin>>str1;
		mn=mnv=mnv1=100000;
		l=str.length();
		i=0;
		func(0,0,0);
		cout<<"Case #"<<ind++<<": "<<a<<" "<<b<<endl;
		
		
	}
	
}
