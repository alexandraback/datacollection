#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T,ca = 1,s,n,p,i,num;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	while(T-- && cin >>n>>s>>p)
	{
		int ans =0 ;
		for(i=0;i<n;i++) {
			cin>>num;
			if(num >= (p+max(p-1,0)*2  ) ) ans++;
			else if(s && num>=(p+max(p-2,0)+max(p-2,0))) ans++,s--;
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
}