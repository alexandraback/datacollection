#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void solve(int caseNum)
{
	int blockNum = 0;
	scanf("%d",&blockNum);
	vector<double> NBlock,KBlock;
	NBlock.assign(blockNum,0);
	KBlock.assign(blockNum,0);
	for (int i = 0; i < blockNum; i++)
	{
		cin>> NBlock[i];
	}
	for (int i = 0; i < blockNum; i++)
	{
		cin>> KBlock[i];
	}
	sort(NBlock.begin(),NBlock.end());
	sort(KBlock.begin(),KBlock.end());
	int scoredw = 0, scorew=0;
	int k = 0;
	for (int i = 0; i < blockNum; i ++)
	{
		while (k < blockNum && KBlock[k]<NBlock[i])
		{
			k++;
		}
		if (k==blockNum)
		{
			break;
		}
		else
		{
			scorew++;
			k++;
		}

	}
	scorew = blockNum - scorew;

	k = 0;
	for (int i = 0; i < blockNum; i ++)
	{
		while (k < blockNum && NBlock[k]<KBlock[i])
		{
			k++;
		}
		if (k==blockNum)
		{
			break;
		}
		else
		{
			scoredw++;
			k++;
		}

	}
	printf("Case #%d: %d %d\n",caseNum,scoredw, scorew);
}
int main()
{
	int caseNum = 0;
	scanf("%d",&caseNum);
	for (int i = 0; i < caseNum; i ++)
	{
		solve(i+1);
	}
	return 0;
}