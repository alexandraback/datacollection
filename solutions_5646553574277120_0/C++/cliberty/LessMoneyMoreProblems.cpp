#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> denomination;
vector<int> usage;
map<int,int> valid;
bool ok;
int c;

void canMake(int v)
{
	int s = 0;
	for(int i=0;i<denomination.size();i++)
	{
		if(usage[i] == 1)
		{
			s+=denomination[i];
		}
	}
	if(s != 0)
	{
		valid[s] = 1;
	}
	if(v == 0)
	{
		return;
	}
	for(int i=0;i<usage.size();i++)
	{
		if(usage[i] <= c)
		{
			usage[i]++;
			canMake(v-1);
			usage[i]--;
		}
	}
}

int main()
{
	int T,cta=1;
	scanf("%d",&T);
	while(T--)
	{
		int d,v;
		
		denomination.clear();
		valid.clear();
		
		scanf("%d%d%d",&c,&d,&v);

		

		for(int i=0;i<d;i++)
		{
			int k;
			scanf("%d",&k);
			denomination.push_back(k);	
		}
		usage.clear();
		usage.resize(d,0);
		canMake(denomination.size());

		int ct= 0;
		
		for(int i=1;i<=v;i++)
		{
			if(valid.count(i) == 0)
			{
				denomination.push_back(i);
				usage.clear();
				usage.resize(denomination.size(),0);
				canMake(denomination.size());
				ct++;
			}			
		}
		printf("Case #%d: %d\n",cta++,ct);
	}
	return 0;
}