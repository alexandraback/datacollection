/*
* Author: Cydonia
* Blog: http://hi.baidu.com/cydorniaknight
* Email: CydorniaKnight@gmail.com
* Problem: 判断类图是否存在菱形继承关系
* Algortihm: 并查集
*/

#include<iostream>
#include<cstdlib>
#include<math.h>
#include<time.h>
#include<map>
#include<deque>
#include<queue>
#include<hash_map>
#include<stack>
using namespace std;

//#define CYDONIA_DEBUG
#define MAXN 1010

// input value
int T;
int N;
int M[MAXN];

// data struct
struct INHERIT_FORM{
	int data[MAXN][MAXN];
	
	void init()
	{
		int i,j;
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
			{
				data[i][j] = 0;
			}
		}
	}

	void set_inherit(int x, int y)
	{
		data[x][y] += 1;
	}

	bool floyd_warshall()
	{
		int i,j,k;

		for(k=1;k<=N;++k)
		{
			for(i=1;i<=N;++i)
			{
				for(j=1;j<=N;++j)
				{
					if(data[i][k]&&data[k][j]){
						data[i][j] += 1;
						if(data[i][j]>1){
							return true;
						}
					}
				}
			}
		}

		return false;
	}

}inh;

int main()
{
#ifndef CYDONIA_DEBUG
	freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
#endif
	int i,j,k;
	int ti;
	scanf("%d",&T);
	for(ti=1;ti<=T;++ti)
	{
		scanf("%d",&N);
		inh.init();
		for(i=1;i<=N;++i)
		{
			scanf("%d",&M[i]);
			for(j=0;j<M[i];++j)
			{
				scanf("%d",&k);
				inh.set_inherit(i,k);
			}
		}
		if(inh.floyd_warshall()){
			printf("Case #%d: Yes\n", ti);
		}else{
			printf("Case #%d: No\n", ti);
		}
	}

#ifdef CYDONIA_DEBUG
	system("pause");
#endif

	return 0;
}