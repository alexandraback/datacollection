/*
name:Rollchuchy
type:
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map> 
using namespace std;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	int temp=T;
	int n;
	map<string,int> bian1,bian2;
	string s1,s2;
	int n1,n2;
	while(T--)
	{
		bian1.clear();bian2.clear(); 
		n1=n2=0;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s1>>s2;
			if(bian1[s1]!=0)
			{
				bian1[s1]=1;
				++n1;
			}
			if(bian2[s2]!=0)
			{
				bian2[s2]=1;
				++n2;
			}
			
		 } 
		 cout<<"Case #"<<temp-T<<": ";
		 printf("%d\n",n-(n1>n2?n1:n2)) ; 
		
	}
	return 0;
 } 
