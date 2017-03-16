/*

*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
int a[105];
int main()
{
	freopen("A.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		printf("Case #%d: ",cas);
		int A,N;
		cin>>A>>N;
		int i;
		for(i=1;i<=N;i++) cin>>a[i];
		sort(a+1,a+1+N);
		int ans=0,s=A;
		int MIN=10000000;
		for(i=1;i<=N;i++)
		{
			if(a[i]<s) s+=a[i];
			else
			{

					int n=0;
					if(s==1){ans+=N-i+1;break;}
					while(s<=a[i])
					{
						s=2*s-1;
						n++;
					}
					s+=a[i];
					if(ans+N-i+1<MIN) MIN=ans+N-i+1;
					
					ans+=n;
			}
		}
		cout<<min(ans,MIN)<<endl;
	}
    return 0;
}
