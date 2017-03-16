#include <queue>
#include <iostream>
using namespace std;


const int max_n =  1010;

struct level_t
{
	int level1;
	int level2;
	int flag ; // 0 no try 1 tried level1 2 complete

};
level_t level[max_n];
struct nodel1
{
	int l;
	nodel1(int ll)
	{
		l = ll;
	}
friend bool operator<(nodel1  a, nodel1 b)
	{
		return level[a.l].level1 > level[b.l].level1; 
	}
};

struct nodel2
{
	int l;
	nodel2(int ll)
	{
		l = ll;
	}
friend	bool operator<(nodel2 a, nodel2 b)
	{
		return level[a.l].level2 > level[b.l].level2;
	}
};

int main()
{
	int t;
	scanf("%d",&t);
	for(int ii=1;ii<=t;++ii)
	{
		priority_queue<nodel1> Q1;
		priority_queue<nodel2> Q2;
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			level[i].level1 = a;
			level[i].level2 = b;
			level[i].flag = 0;
			
			Q1.push(nodel1(i));
			Q2.push(nodel2(i));
		}
		int cnt = 0;
		int stars = 0;
		while(!Q2.empty())
		{
			nodel2 tmp2_node = Q2.top();
			//printf("fuck level %d rate2  stars:%d need %d\n",tmp2_node.l,stars,level[tmp2_node.l].level2);
			while(stars < level[tmp2_node.l].level2)
			{
				//printf("not enought\n");
				if(Q1.empty())
				{
					cnt = -1;
					break;
				}
				
				nodel1 tmp1_node = Q1.top();
				if(level[tmp1_node.l].flag == 2)
				{
					Q1.pop();
					continue;
				}
				if(stars < level[tmp1_node.l].level1)
				{
					cnt = -1;
					break;
				}
				//printf("fuck level %d rate1  stars:%d need %d\n",tmp1_node.l,stars,level[tmp1_node.l].level1);
				stars++;
				cnt++;
				level[tmp1_node.l].flag = 1;
				Q1.pop();
			}
			if(cnt==-1)
				break;
			//printf("fuck level %d rate2  stars:%d need %d\n",tmp2_node.l,stars,level[tmp2_node.l].level2);
			cnt++;
			
			if(level[tmp2_node.l].flag == 1)
				stars+=1;
			else 
				stars+=2;
			level[tmp2_node.l].flag == 2;
			Q2.pop();
		}

		if(cnt == -1)
			printf("Case #%d: Too Bad\n",ii);
		else
			printf("Case #%d: %d\n",ii,cnt);
	}
	return 0;

}



