#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int debug=0;

long long modulo=1000000007;

long long fact(int n)
{
	if(n<=1)return 1;
	if(n==30)return 109361473;
	if(n==50)return 318608048;
	if(n==70)return 108669496;
	return (n*fact(n-1))%modulo;
}

int n;
string str[102];
bool purechar[102];

int cmcnt[27],stcnt[27],edcnt[27],idcnt[27];

bool check_legal()
{
	memset(cmcnt,0,sizeof(cmcnt));
	memset(stcnt,0,sizeof(cmcnt));
	memset(edcnt,0,sizeof(cmcnt));
	memset(idcnt,0,sizeof(cmcnt));
	memset(purechar,0,sizeof(purechar));
	int i,j;
	
	for(i=0;i<n;i++)
	{
		string s=str[i];
		if(debug&&0){cout<<"checkstr:"<<s<<endl;}
		char lc=s[0];
		int l=s.length();
		stcnt[s[0]-'a']++;
		edcnt[s[l-1]-'a']++;
		int j=1;
		bool flag=false;
		while(j<l)
		{
			if(s[j]==lc)
			{}
			else
			{
				flag=true;
				if(s[j]!=s[l-1]){
					cmcnt[s[j]-'a']++;
					if(debug&&0){cout<<" newcm:";printf("%c",s[j]);}
				}
				lc=s[j];
			}
			j++;
		}
		if(flag==false)
		{
			purechar[i]++;
			idcnt[s[0]-'a']++;
		}
	}
	
	if(debug)
	{	
		cout<<"st:";
		for(i=0;i<26;i++)cout<<stcnt[i]<<"-";
		cout<<endl;
		cout<<"ed:";
		for(i=0;i<26;i++)cout<<edcnt[i]<<"-";
		cout<<endl;
		cout<<"cm:";
		for(i=0;i<26;i++)cout<<cmcnt[i]<<"-";
		cout<<endl;
		cout<<"id:";
		for(i=0;i<26;i++)cout<<idcnt[i]<<"-";
		cout<<endl;
	}
	for(i=0;i<26;i++)
	{
		if(cmcnt[i]>1)return false;
		if(cmcnt[i]>0&&(stcnt[i]+edcnt[i])>0)return false;
	}	//if anything in middle
	
	for(i=0;i<26;i++)
	{
		stcnt[i]-=idcnt[i];
		edcnt[i]-=idcnt[i];
	}	//remove independent sections like bbbb
	
	for(i=0;i<26;i++)
	{
		if(stcnt[i]>1)return false;
		if(edcnt[i]>1)return false;
	}	//check two heads (without independent start already)
	
	return true;
}

long long find_sol()
{
	int connto[27];
	int i;
	for(i=0;i<27;i++)connto[i]=-1;
	
	int visited[27];
	memset(visited,0,sizeof(visited));
	for(i=0;i<n;i++)
	if(!purechar[i])
	{
		int c1=str[i][0]-'a';
		int c2=str[i][str[i].length()-1]-'a';
		if(debug&&0)cout<<" assert-1="<<connto[c1];
		connto[c1]=c2;
	}
	
	long long ans=1;
	int totplan=0;
	//first round: start with 1
	for(i=0;i<26;i++)
	if(!visited[i])
	if(stcnt[i]==1&&edcnt[i]==0)//starting point!
	{
		long long mul=1;
		int j=i;
		while(1)
		{
			if(idcnt[j]>0)
			{
				mul=mul*fact(idcnt[j])%modulo;
				if(debug)cout<<"id-fact"<<idcnt[j];
			}
			
			visited[j]=true;
			j=connto[j];
			if(visited[j])
			{
			if(debug)cout<<"loop!";
			return 0;}
			
			if(stcnt[j]==0)
			{			
				if(idcnt[j]>0)
				{
					mul=mul*fact(idcnt[j])%modulo;
					if(debug)cout<<"id-fact"<<idcnt[j];
				}
			
			visited[j]=true;break;}
		}
		if(debug)cout<<"add plan:"<<mul<<endl;
		ans*=mul;
		ans%=modulo;
		totplan++;
	}
	
	//second round: start with whatever, but not iid
	for(i=0;i<26;i++)
	if(!visited[i])
	if(stcnt[i]==1)//starting point!
	{
		long long mul=1;
		long long len=1;
		int j=i;
		while(1)
		{
			if(idcnt[j]>0)
			{
				mul=mul*fact(idcnt[j])%modulo;
				if(debug)cout<<"id-fact"<<idcnt[j];
			}
			
			visited[j]=true;
			j=connto[j];
			if(visited[j])
			{
			if(debug)cout<<"loop!";
			return 0;}
			len++;
			if(j==i)
			{
				mul=(mul*fact(len))%modulo;
				break;
			}			
		}
		if(debug)cout<<"add plan2:"<<mul<<endl;
		ans*=mul;
		ans%=modulo;
		totplan++;
	}
	//third round: only iids
	for(i=0;i<26;i++)
	if(!visited[i])
	if(stcnt[i]==0&&idcnt[i]>0)
	{
		long long mul=fact(idcnt[i]);
		if(debug)cout<<"add plan id:"<<mul<<endl;
		ans*=mul;
		ans%=modulo;
		totplan++;
	}
	if(debug)cout<<"totplan:"<<totplan;
	ans*=fact(totplan);
	ans%=modulo;
	return ans;
}


int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
		if(str[i].length()==1)
		str[i]=str[i]+str[i];
	}
	bool flag=check_legal();
	long long ans=0;
	if(flag)
	{
		ans=find_sol();	
	}
	
	cout<<"Case #"<<(ti+1)<<": ";
	cout<<ans;
	cout<<endl;
}
return 0;
}