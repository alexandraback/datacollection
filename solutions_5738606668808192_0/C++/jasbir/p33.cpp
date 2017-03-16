#include<cstdio>

using namespace std;
#define sz 16
int ar[sz];
int ans = 0;
int N,J;
void pr()
{


	
	for(int i=sz-1;i>=0;i--) printf("%d",ar[i]); 
	for(int i=2;i<11;i++) printf(" %d",i+1); printf("\n");
	ans++;
}
void solve(int pos)
{
	if(pos==sz-1) return;
	int i=pos;
		if(ar[i]==0 && ar[i+1]==0)
		{
			ar[i] = 1; ar[i+1] = 1;
			pr();
			if(ans==J) return;
			solve(pos+2);
			ar[i] = 0; ar[i+1]=0;
			if(ans==J) return;
			
		}
		
		solve(pos+1);
		
	
	
	
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: \n",tc);
	 scanf("%d %d",&N,&J);
	
	ar[0] = 1; ar[sz-1]=1;  ar[1]=1; ar[sz-2]=1;
	
	solve(2);
		
	}
}
