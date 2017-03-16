#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>
#include <sstream>  

using namespace std;
typedef long long ll;

const ll max_n=10000000ll;
const int m=100000;

int T,n;
ll a[m];

int np=0;

bool palin(ll a)
{
	stringstream ss;
	ss<<a;
	
	string s;
	ss>>s;
	
	for(int i=0; i<s.size()/2; i++)
		if(s[i]!=s[s.size()-1-i])
			return false;
			
	return true;
}

void gen(string s)
{
	if(s.size()==7)
	{
		int i=0;
		while(i<6 and s[i]=='0')
			i++;
		string sd="";
		while(i<7)
		{
			sd+=s[i];
			i++;
		}
	
		stringstream ss;
		ss<<sd;
		
		ll r; 
		ss>>r;
		if(r>0ll and palin(r) and palin(r*r))
			a[np++]=r*r;
	}
	
	else
	{
		gen(s+'0');gen(s+'1');gen(s+'2');
	}
}

int main()
{
	gen("");	

	scanf("%d",&T);
	
	for(int z=1; z<=T; z++)
	{
		int res=0;
		ll l,r;
		cin>>l>>r;
		
		if(l<=9 and r>=9)
			res++;
		
		int i=0;
		while(a[i]<l)
			i++;
			
		while(i<np and a[i]<=r)
		{
			i++;
			res++;
		}
		
		printf("Case #%d: ",z);
		printf("%d\n",res);
	}
	
    return 0;
}
