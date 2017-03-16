#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<limits>
using namespace std;

typedef long long LL;
set<pair<int,int> > sp;
int main(int argc, char *argv[])
{
#ifdef CHAOS
	freopen("data.in","r",stdin);
#endif
	int T;
	cin>>T;

	int t;
	for(t=1;t<=T;++t)
	{
		sp.clear();
		cout<<"Case #"<<t<<": ";
		int A,B;
		cin>>A>>B;
		int n;
		for(n=A;n<=B;++n)
		{
			char num[32];
			char tmp[32];
			memset(num,0,sizeof(num));
			memset(tmp,0,sizeof(tmp));
			sprintf(num,"%d",n);
			int len=strlen(num);
			int i;
			for(i=1;i<len;++i)
			{
				strcpy(tmp,num+i);
				strncat(tmp,num,i);
				int x=atoi(tmp);
				if(x!=n && x<=B && x>=A)
				{
					sp.insert(make_pair(n,x));
					sp.insert(make_pair(x,n));
					
				}
			}
		}
		cout<<sp.size()/2<<endl;
	}
	return 0;
}
