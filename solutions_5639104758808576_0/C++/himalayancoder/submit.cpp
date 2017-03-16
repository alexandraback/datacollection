#include<bits/stdc++.h>
#define md 1000000007
#define ll  long long
#define gc getchar//_unlocked
using namespace std;
char a[2000];
int main()
{
	
    int test,mx;
	scanf("%d",&test);
	for(int j=1;j<=test;j++){
		scanf("%d",&mx);
		scanf("%s",a);
		int count=0;
		int add=0;
		int tm;
		for(int i=0;i<=mx;i++){
			tm=a[i]-'0';
			if(count>=i)
				count+=tm;
			else
			{	add+=(i-count);
		count=i+tm;
			}
		}
		printf("Case #%d: %d\n",j,add);
	}
	
    
    return 0;
}