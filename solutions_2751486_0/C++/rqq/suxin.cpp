#include<cstdlib> 
#include<iostream> 
#include<cmath> 
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<hash_set>
#include<time.h>
using namespace std; 


int main() 
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	hash_set<char> v;
	v.insert('a');
	v.insert('e');
	v.insert('i');
	v.insert('o');
	v.insert('u');
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		string s;
		int n,count=0,sum=0,k=0;
		cin>>s>>n;
		for(int i=0;i<s.length();i++)
		{
			if(v.find(s[i])!=v.end())
			{
				count=0;
				continue;
			}
			count++;
			if(count==n)
			{
				sum+=(i-n-k+2)*(s.length()-i);
				k=i-n+2;
				count=0;
				i=k-1;
			}
		}
		cout<<"Case #"<<cas<<": "<<sum<<endl;
	}
	return 0; 
}