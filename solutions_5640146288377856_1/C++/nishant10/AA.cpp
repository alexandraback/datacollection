#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

//freopen("in.txt","r",stdin); 
//freopen("out.txt","w",stdout); 


int main()
{
	int t,r,c,w,i,j,y,cnt,idx;

	scanf("%d",&t);
	idx = 1;
	while(t--)
	{
		scanf("%d %d %d",&r,&c,&w);
		cnt = 0;
		y = c;
		for(i = 1;i <= r;i++)
		{
			for(j = w;j <= c;j = j+w)
			{
					cnt = cnt + 1;		
			}	
		}
		cnt = cnt + w;
		if(c%w == 0)
			cnt = cnt - 1;
		
		printf("Case #%d: %d\n",idx,cnt);
		idx++;		
	}
	return 0;
}
