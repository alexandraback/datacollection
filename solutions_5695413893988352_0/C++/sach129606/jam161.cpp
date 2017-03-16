#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
#define ll long long int 
using namespace std;

int main()
{
 
 freopen("inp.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 int t,id=1;;
 cin>>t;
 while(t--)
 {
 	
 	
 	
 	string S1,S2;
 	cin>>S1>>S2;
 	int n=S1.length();
 	ll diff=0,mul=1;;
 	
 	for(int i=n-1;i>=0;i--)
 	{
 		if(S1[i]!='?'&&S2[i]!='?')
 		diff+=((S1[i]-'0')-(S2[i]-'0'))*mul;
 		mul=mul*10;
	}
	
	ll abs_diff=abs(diff);
//	cout<<diff;
	mul=mul/10;
	for(int i=0;i<n;i++)
	{
		if(S1[i]!='?'&&S2[i]!='?')
		{
			mul=mul/10;
			continue;
		}
		ll tmp_diff=diff;
			if(S1[i]=='?'&&S2[i]=='?')
	{
	
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
			
				{
					if(abs(diff+(j-k)*mul)<abs_diff)
					{
						abs_diff=abs(diff+(j-k)*mul);
						tmp_diff=diff+(j-k)*mul;
						S1[i]=j+'0';
						S2[i]=k+'0';
					}
					else if(abs(diff+(j-k)*mul)==abs_diff)
					{
						
						if(S1[i]=='?'&&S2[i]=='?')
						{
							S1[i]=j+'0';
							S2[i]=k+'0';
						}
						 if(S1[i]-'0'>j)
						{
						S1[i]=j+'0';tmp_diff=diff+(j-k)*mul;}
						 if(S2[i]-'0'>k){
						tmp_diff=diff+(j-k)*mul;
						S2[i]=k+'0';
					}
					}
				
				}
		}
}
}				else if(S1[i]=='?')
				{
				int	k1=S2[i]-'0';
				for(int	j=0;j<=9;j++){
						if(abs(diff+(j-k1)*mul)<abs_diff)
					{
						abs_diff=abs(diff+(j-k1)*mul);
						tmp_diff=diff+(j-k1)*mul;
						S1[i]=j+'0';
						S2[i]=k1+'0';
					}
					else if(abs(diff+(j-k1)*mul)==abs_diff)
					{
					//	tmp_diff=diff+(j-k)*mul;
						if(S1[i]=='?'&&S2[i]=='?')
						{
							S1[i]=j+'0';
							S2[i]=k1+'0';
						}
						 if(S1[i]=='?'||S1[i]-'0'>j){
						tmp_diff=diff+(j-k1)*mul;
						S1[i]=j+'0';}
					}
				}
			}
				else
				{
				int	j1=S1[i]-'0';
				for(int	k=0;k<=9;k++)
				{
						if(abs(diff+(j1-k)*mul)<abs_diff)
					{
						abs_diff=abs(diff+(j1-k)*mul);
						tmp_diff=diff+(j1-k)*mul;
						S1[i]=j1+'0';
						S2[i]=k+'0';
					}
					else if(abs(diff+(j1-k)*mul)==abs_diff)
					{
					//	tmp_diff=diff+(j-k)*mul;
						if(S1[i]=='?'&&S2[i]=='?')
						{
							S1[i]=j1+'0';
							S2[i]=k+'0';
						}
						 if(S2[i]=='?'||S2[i]-'0'>k){
						tmp_diff=diff+(j1-k)*mul;
						S2[i]=k+'0';}
					}
				}
			}
			
		
		
	diff=tmp_diff;
		mul=mul/10;
	}
	
cout<<"Case #"<<id<<": ";
 	
 	id++;
 	cout<<S1<<" "<<S2;
    cout<<endl; 	
 }
 
return 0;
}

/*
	ll new_diff=min(abs(diff-mul),abs(diff+mul));
		ll cur_diff=abs(diff);
		
	
	 if(curr_diff==new_diff)
		{
			if(S1[i]==S2[i])
			S1[i]=S2[i]='0';
			else if(S1[i]=='?')
			S1[i]=S2[i];
			else
			S2[i]=S1[i];
		}
		else
		{
			if(abs(diff-mul)<abs(diff+mul))
			{
				if(S1[i]==S2[i])
		    	S1[i]=S2[i]='0';
			else if(S1[i]=='?')
			S1[i]=S2[i];
			else
			S2[i]=S1[i];
			}
		}
		
*/

