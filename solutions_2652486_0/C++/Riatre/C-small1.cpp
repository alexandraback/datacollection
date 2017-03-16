// Warning: Small-1 Only

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	freopen("C-small-1-attempt0.in","rt",stdin);
	freopen("C-small1.out","wt",stdout);
	printf("Case #1:\n");
	scanf("%*d");
	int R = 0;
	int N = 0;
	int M = 0;
	int K = 0;
	scanf("%d %d %d %d",&R,&N,&M,&K);
	for(int i = 0;i < R;i++)
	{
		int prod[10] = {0};
		for(int j = 0;j < K;j++) scanf("%d",&prod[j]);
		
		bool found = false;
		map<string,int> okans;
		for(int d1 = 2;d1 <= M && !found;d1++) for(int d2 = 2;d2 <= M && !found;d2++) for(int d3 = 2;d3 <= M && !found;d3++)
		{
			int num = d1*100+d2*10+d3;
			int genprod[10] = {0};
			genprod[0] = 1;
			genprod[1] = d1;
			genprod[2] = d2;
			genprod[3] = d3;
			genprod[4] = d1*d2;
			genprod[5] = d1*d3;
			genprod[6] = d2*d3;
			genprod[7] = d1*d2*d3;
			
			bool fail = false;
			/*int miss = 0;
			for(int j = 0;j < 8;j++)
			{
				if(find(prod,prod+K,genprod[j]) == prod+K) miss++;
			}*/
			for(int j = 0;j < K;j++)
			{
				if(std::find(genprod,genprod+8,prod[j]) == genprod+8) fail = true;
			}
			if(!fail)
			{
				//found = true;
				//printf("%d\n",num);
				char buf[10] = {0};
				sprintf(buf,"%d",num);
				sort(buf,buf+3);
				okans[string(buf)]++;
			}
		}
		
		int mx = 0;
		for(auto it: okans)
		{
			if(it.second > mx) mx = it.second;
		}
		for(auto it: okans)
		{
			if(it.second == mx)
			{
				printf("%s\n",it.first.c_str());
				break;
			}
		}
	}
	return 0;
}
