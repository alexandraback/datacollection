#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	freopen("d:\\2.in", "r", stdin);
	freopen("d:\\2.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		int a, b, k;
		cin>>a>>b>>k;
		int ans = 0;
		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				if((i & j) < k)
					ans++;
		cout<<"Case #"<<kase<<": ";			
		cout<<ans<<endl;
	}
	return 0;
}
