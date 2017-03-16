#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <iostream>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j,n,l,p;
	char s[1000010];
	scanf("%d",&cas);
	std::set<int>::iterator itlow,itup;
	long long sum;
	for(ki=1;ki<=cas;ki++)
	{
		p=0;
		sum=0;
		printf("Case #%d: ",ki);
		scanf("%s%d",s,&n);
		l=strlen(s);
		set<int> vow;
		for(i=0;i<l;i++)
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			{
				vow.insert(i);
			}
		for(i=0;i<=l-n;i++)
		{
			itlow=vow.lower_bound(i);
			if(!(itlow!=vow.end()&&*itlow<i+n))
			{
				sum+=(l-i-n+1)*(i-p+1);
				p=i+1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}