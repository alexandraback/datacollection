#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;

typedef struct subs
{
	int start;
	int end;
}subs;

vector<subs> subList;
vector<int> pos;
int n;
char buf[128];
void Calculate();
bool checkExist(subs a);

int main(void)
{
	freopen("a.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int nTest;
	scanf("%d", &nTest);

	for (int i = 0; i < nTest ; i++)
	{
		printf("Case #%d: ",i+1);
		scanf("%s %d", buf, &n);
		subList.clear();
		pos.clear();
		Calculate();
	}
	return 1;
}

void Calculate()
{
	int len  = strlen(buf);
	bool Nsub;
	for (int i = 0; i < (len+1-n) ; i++)
	{
		Nsub = true;
		for (int j = 0; j < n ; j++)
		{
			if ((i+j)>=len)
			{
				printf("error");
			}
			char tmp = buf[i+j];
			if ( (tmp == 'a' ) ||
				(tmp == 'e' ) ||
				(tmp == 'i' ) ||
				(tmp == 'o' ) ||
				(tmp == 'u' ) 
				)
			{
				Nsub =false;
				break;
			}
		}
		if (Nsub)
		{
			pos.push_back(i);
		}
	}


	int posLen = pos.size();
	for (int i = 0; i < posLen ; i++)
	{
		int pre = pos[i]+1;
		int suf = len - n - pos[i]+1;

		for (int ii = 0; ii < pre ; ii++)
		{
			for (int jj = 0; jj < suf ; jj++)
			{
				subs tmp;
				tmp.start = ii;
				tmp.end = jj+pos[i]+n-1;
				if (!checkExist(tmp))
				{
					subList.push_back(tmp);
				}
			}
		}
	}

	printf("%d\n", subList.size());

}

bool checkExist( subs a )
{
	int len = subList.size();
	for (int i = 0; i < len ; i++)
	{
		if ((subList[i].start == a.start) && (subList[i].end == a.end))
		{
			return true;
		}
		if(subList[i].start > a.start) 
			return false;
	}
	return false;
}
