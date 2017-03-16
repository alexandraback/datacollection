#include<bits/stdc++.h>
#define md 1000000007
#define ll  long long
#define gc getchar//_unlocked
using namespace std;
int a[2000];
int main()
{
	
    int test,n;
	scanf("%d",&test);
	for(int j=1;j<=test;j++){
		scanf("%d",&n);
		int mx=md;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int tp=0;
		for(int i=a[n-1];i>0;i--){
			tp=i;
			for(int k=n-1;k>=0 && i<=a[k];k--){
				tp+=((a[k]-1)/i);
				
			}
			mx=min(mx,tp);
		}
		printf("Case #%d: %d\n",j,mx);
	}
	
    
    return 0;
}