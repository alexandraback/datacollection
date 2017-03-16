#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int T,k,c,s;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>T;
	for (int z=1;z<=T;++z)
	{
		cin>>k>>c>>s;
		cout<<"Case #"<<z<<": ";
		for (int i=1;i<k;++i) cout<<i<<" ";
		cout<<k<<endl;
	}
	return 0;
}
