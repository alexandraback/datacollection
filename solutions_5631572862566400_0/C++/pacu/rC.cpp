#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int N;
int b[1000];
int cid[1000];
void init()
{
	for(int i=0;i<N;i++) cid[i] = i;
}
int find(int i)
{
	if(cid[i]==i) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
bool join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return 1;
	cid[i] = j;
	return 0;
}

vector<int> edges[1000];

int dfs(int i,int par)
{
	int cur = 0;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			cur = max(cur,1+dfs(edges[i][j],i));
	return cur;
}

void test(int num)
{
	cin >> N;
	init();
	for(int i=0;i<N;i++)
	{
		cin >> b[i];
		b[i]--;
		edges[i].clear();
	}
	for(int i=0;i<N;i++) edges[b[i]].push_back(i);
	int cSum = 0;
	for(int i=0;i<N;i++)
		if(b[b[i]]==i && b[i] > i)
		{
			int cur = dfs(i,b[i])+dfs(b[i],i)+2;
			cSum += cur;
		}
	for(int i=0;i<N;i++)
	{
		if(join(i,b[i]))
		{
			int j = b[i];
			int l = 1;
			while(j != i)
			{
				j = b[j];
				l++;
			}
			cSum = max(cSum,l);
		}
	}
	cout << "Case #" << num << ": " << cSum << '\n';
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) test(i+1);
}