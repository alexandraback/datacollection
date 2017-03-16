// Rohit Bhardwaj

#include<bits/stdc++.h>
#define md 1000000007
#define gc getchar//_unlocked
#define ll unsigned long long
using namespace std;
int ar[500];
int da[100];
int main()
{
	

    	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("out.txt","w",stdout);				
		#endif
		int test;
		int c,d,v,f;
		scanf("%d",&test);
		for(int tt=1;tt<=test;tt++){
			printf("Case #%d: ",tt);
			scanf("%d%d%d",&c,&d,&v);
			for(int i=0;i<=v;i++)
				ar[i]=0;
			for(int i=0;i<d;i++)
			{scanf("%d",&f);ar[f]=1;}
			int ct=0;
			int sum=0;
			
			for(int i=1;i<=v;i++)
			{if(ar[i]==0)
			{
					if(sum<i)
					{ct++;sum+=i;}
			}
			else
				sum+=i;
			}
				printf("%d\n",ct);
		}
    return 0;
}

