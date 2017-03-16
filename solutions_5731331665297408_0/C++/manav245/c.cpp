#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
vector<int> l[9];
string pin[9];
string ans="z";
int mark[9];
int proc=0;
int cnt=0;
int f=0;
int N;
void dfs(int a[8],int cur)
	{
//	printf("cur-%d\n",cur);
	for(int i=0;i<l[cur].size();i++)
		{
		if(l[cur][i]==a[proc])
			{
			proc=proc+1;
			if(proc!=N)
				{
				dfs(a,a[proc-1]);
				i=-1;
				}
			else
				{
				f=1;
				return;
				}
			}
		if(f==1)
			return ;
		}
	}
int main()
{
int T;
freopen("i2.txt","r",stdin);
freopen("o2.txt","w",stdout);
scanf("%d",&T);
int i,h,j,k;
int M;
for(int t=0;t<T;t++)
	{
	int a[8]={0,1,2,3,4,5,6,7};
	scanf("%d %d",&N,&M);
	ans="z";
	for(i=0;i<N;i++)
		{
		l[i].clear();
		}
	for(i=0;i<N;i++)
		{
		cin>>pin[i];
		}
	for(i=0;i<M;i++)
		{
		scanf("%d %d",&j,&k);
		j--;
		k--;
		l[j].push_back(k);
		l[k].push_back(j);
		}
	if(M==0)
		{
		printf("Case #%d: ",t+1);
	cout<<pin[0]<<endl;	
	continue;
		}
	do {
  		int cur=a[0];
		cnt=0;
		proc=1;
		f=0;
//		printf("dd\n");
		dfs(a,a[0]);
		
  		if(f==1)
  			{
  /*
  			for(int pp=0;pp<N;pp++)
  				printf("%d-",a[pp]);
  				printf("\n");
 */
  			string p="";
  			for(i=0;i<N;i++)
  				{
  				p+=pin[a[i]];
  				}
			if(ans.compare(p)>0)
				{
				ans=p;
				}
  			}
  		else
  			{
/*
  			printf("bobo\n");
  			for(int pp=0;pp<N;pp++)
  				printf("%d-",a[pp]);
  				printf("\n");
*/
  			}
 		} while ( next_permutation(a,a+N) );
	printf("Case #%d: ",t+1);
	cout<<ans<<endl;	
	}
}
