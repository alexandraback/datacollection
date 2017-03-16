#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

char str[SIZE];

bool ok(char c)
{
	return !(c=='a'||c=='i'||c=='u'||c=='e'||c=='o');
}
int len(int s,int e)//[s,e]
{
	return e-s+1;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%s",&str);
		int n;
		scanf("%d",&n);
		int l=strlen(str);
		vector <P> vec;
		int s;
		for(s=0;s<l;s++) if(ok(str[s])) break;
		for(int i=s+1;i<=l;i++)
		{
			if(i==l||!ok(str[i]))
			{
				int e=i-1;
				if(len(s,e)>=n) vec.push_back(P(s,e));
				s=i+1;
			}
		}
		ll ret=0;
		int pos=0;
		for(int i=0;i<l;i++)
		{
			if(pos>=vec.size()) break;
			P p=vec[pos];
			if(len(i,p.second)<n)
			{
				pos++;
				if(pos>=vec.size()) break;
				p=vec[pos];
			}
			int end=max(i,p.first)+n-1;
			ret+=l-end;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
