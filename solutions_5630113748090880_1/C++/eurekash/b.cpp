#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T,N;
	scanf("%d\n",&T);
	char s[200];
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d: ",tt);
	
		int cnt[2600];
		memset(cnt,0,sizeof(cnt));
			cin>>N;


		for(int i=0;i<2*N-1;i++)
		for(int j=0;j<N;j++)
		{
			int tmp;cin>>tmp;
			cnt[tmp]++;
		}
		
		for(int i=0;i<2501;i++){
			if(cnt[i]%2==1)cout<<i<<" ";
		}
		printf("\n");
	}
}

