#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<memory.h>

using namespace std;
bool isvowel(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int nc;
	cin>>nc;

	char s[1000001];
	int n,len;
	int st,ed,count;
	long long total;
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>s>>n;
		len=strlen(s);
		st=ed=count=total=0;
		while(ed<len)
		{
			if(!isvowel(s[ed]))
			{
				count++;
				if(count==n)
				{
					total+=(ed-st-n+2)*(len-ed);
					st=ed-n+2;
					count--;
				}
			}
			else
				count=0;
			ed++;
		}
		cout<<"Case #"<<tc<<": "<<total<<endl;
	}	
	return 0;
}