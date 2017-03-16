#include<cstdio>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
vector<int> vec[1002];
map<int,int> mp;
int st[1002];
int en[1002];
int mark[1002];
int b[1002];
int pos[1002];
int chain[1002];
int ans_mar[1002];
int ind[1002];
int ans,N;
int main()
{
int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&b[i]);
		for(int i=0;i<1002;i++) 
		{
			vec[i].clear(); st[i] = 0; en[i] = 0; mark[i] = 0;
		}
		ans = 0;
	//	printf("b[1] = %d\n",b[1]);
		for(int i=1;i<=N;i++)
		{
			if(mark[i]) continue;
			mark[i] = 1;
			chain[i] = i;
			pos[i] = 1;
			vec[i].push_back(i);
	
			int tmp = b[i];
			while(mark[tmp]==0)
			{
			//	printf(" tmp is %d\n",tmp);
				mark[tmp] = 1;
				vec[i].push_back(tmp);
				pos[tmp] = vec[i].size();
				chain[tmp] = i;
				tmp = b[tmp];
			}
			
			int chn = chain[tmp];
			if(chain[tmp]==i)
			{
				int tt = vec[i].size();
				tt -= pos[tmp]; tt++;
				if(ans<tt) ans = tt;
			}
			else
			{
				int p = pos[tmp];
				for(int j = p-1;j<vec[chn].size();j++)
				{ 
					vec[i].push_back(vec[chn][j]);
					pos[vec[chn][j]] = vec[i].size();
					chain[vec[chn][j]] = i;
					tmp = b[vec[chn][j]];
				}
				
				
				int ll=vec[i].size();  tmp = vec[i][ll-1];
				int btmp = b[tmp];
				if(mark[btmp])
				{
					if(chain[btmp]==i)
					{
						int tt = vec[i].size();
						tt -= pos[btmp]; tt++;
						if(ans<tt) ans = tt;
					}
				}
			}
			
			
		}
		
		
	/*	printf("chins are :\n");
		for(int i=0;i<1002;i++)
		{
			if(vec[i].size() > 0)
			{
				printf(" ch(%d) : ",i);
			for(int j=0;j<vec[i].size();j++)
			printf(" %d ",vec[i][j]); printf("\n");
			
			}
		}*/
		for(int i=0;i<1002;i++) ans_mar[i] = 0;
		for(int i=0;i<1002;i++)
		{
			if(vec[i].size() > 0)
			{
				int s = 1;
				int f = vec[i][0];
				int sec = vec[i][1];
				if(b[f] == sec) ;  else s = 0;
				
				int l = vec[i].size(); l--;
				f = vec[i][l];
				sec = vec[i][l-1];
				if(b[f] == sec) ;  else s = 0;
				if(s)
				{
					for(int j=0;j<vec[i].size();j++)
					ans_mar[vec[i][j]] = 1;
				}
			//	if(s)
	//			printf("indp found at %d\n",i);
				
			}
		}
		
		int tmpa = 0;
		for(int i=0;i<1002;i++) if(ans_mar[i]) tmpa++;
	//	printf("tmps is %d\n",tmpa);
		if(tmpa>ans)  ans = tmpa;
		printf("%d\n",ans);
		
		
		
	}	
}
