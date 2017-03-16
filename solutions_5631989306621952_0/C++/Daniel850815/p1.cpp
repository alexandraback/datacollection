#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int cas;
	//freopen("result.txt","w",stdout);
	scanf("%d ",&cas);
	for(int i=0;i<cas;i++)
	{
		char q[1200],a[1200];
		memset(q,'\0',sizeof(q));
		memset(a,'\0',sizeof(a));
		gets(q);
		int len=strlen(q);
		a[0]=q[0];
		for(int j=1;j<len;j++)
		{
			if(a[0]>q[j])
			{
				//cout<<q[j]<<" "<<strlen(a)<<endl;
				a[strlen(a)]=q[j];
				a[strlen(a)+1]='\0';
				//for(int k=0;k<strlen(a);k++)
				//	cout<<a[k];
				//cout<<endl;
			}
			else
			{
				char store[1200];
				memset(store,'\0',sizeof(store));
				store[0]=q[j];
				for(int k=0;k<strlen(a);k++)
					store[k+1]=a[k];
				strcpy(a,store);
			}
		}
		printf("Case #%d: %s\n",i+1,a);
	}
	return 0;
}
