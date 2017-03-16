#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
ifstream cin("B-large.in");
int main()
{
	freopen("2.out","w",stdout);
	int T,n,k;
	string s;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>s;
		n=s.length();
		k=0;
		for(int j=1;j<n;j++)
			if(s[j]!=s[j-1])
				k++;
		if(s[n-1]=='-')
			k++;
		printf("Case #%d: %d\n",i,k);
	}
	
	return 0;
}

