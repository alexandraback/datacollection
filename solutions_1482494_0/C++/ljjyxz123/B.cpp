#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
using namespace std;
/*************************************************************************************/
int T;
int N;
typedef struct Node
{
	int a;
	int b;
}Node;
Node node[20];
Node node_flag[20];

bool cmpA(Node x, Node y);
bool cmpB(Node x, Node y);
bool cmpBd(Node x, Node y);
int judge(int n);
/*************************************************************************************/
bool cmpA(Node x, Node y)
{
	if(x.a != y.a)
		return (x.a < y.a);
	else
		return (x.b <= y.b);
}
bool cmpB(Node x, Node y)
{
	if(x.b != y.b)
		return (x.b < y.b);
	else
		return (x.a <= y.a);
}

bool cmpBd(Node x, Node y)
{
	if(x.b != y.b)
		return (x.b > y.b);
	else
		return (x.a < y.a);
}

int judge(int n)
{
	for(int i=0; i<n; i++)
	{
		if(node_flag[i].b == 0)
			return 0;
	}
	return 1;
}
/*************************************************************************************/
int main()
{
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B-small-attempt4.out", "w", stdout);
	
	cin >> T;
	int tcase = 1;
	int star_num = 0;
	int try_num = 0;
	int total_flag = 1;
	for(int k=0; k<T; k++)
	{
		star_num = 0;
		try_num = 0;
		total_flag = 1;
		for(int i=0; i<20; i++)
		{	
			node_flag[i].a = 0;
			node_flag[i].b = 0;
		}
		
		cin >> N;
		for(int i=0; i<N; i++)
		{
			cin >> node[i].a >> node[i].b;
		}
		sort(node, node+N, cmpB);
		
		for(int i=0; i<N; i++)
		{
			//cout << i << " " << try_num << " " << star_num << " " << node[i].a  << " " << node[i].b << endl;
			if(node_flag[i].b == 0)
			{
				//如果可以直接过第二关 
				if(star_num >= node[i].b)
				{
					if(node_flag[i].a == 1)
					{
						star_num += 1;	
						try_num += 1;
						node_flag[i].b = 1;
					}
					else
					{
						star_num += 2;
						try_num += 1;
						node_flag[i].b = 1;
					}
				}
				//如果不能直接过 
				else
				{
					sort(node+i, node+N, cmpBd);
					int tmp_flag = 0;
					for(int l=i; l<N; l++)
					{
						if(node_flag[l].a == 0)
						{
							if(star_num >= node[l].a)
							{
								star_num += 1;
								try_num += 1;
								node_flag[l].a = 1;
								sort(node+i, node+N, cmpB);
								tmp_flag = 1;
								i--; break;
							}
						}
					}
					if(!tmp_flag)
					{
						total_flag = 0;
						break;
					}
				}
			}
		}
		
		if(total_flag == 0)
		{
			printf("Case #%d: Too Bad\n", tcase++);
			continue;
		}
		if(judge(N))
		{
			printf("Case #%d: %d\n", tcase++, try_num);
			continue;
		}
		else
		{
			printf("Case #%d: Too Bad\n", tcase++);
			continue;
		}
	}
	
	return 0;
}
