#include <iostream>
#include <string>
#include <vector>
using namespace std;


int ComputeNeedFriend(int sMax, string& str)
{
	vector<int> records(sMax + 1, 0);
	for (int i = 0; i <= sMax; ++i)
	{
		records[i] = str[i] - '0';
	}
	int curLevel = 0;
	int curClap = 0;
	int needFriend = 0;
	while (curLevel <= sMax)
	{
		if (curClap < curLevel)
		{
			needFriend += curLevel - curClap;
			curClap = curLevel;
		}

		curClap += records[curLevel];
		curLevel++;
	}
	return needFriend;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	int N;
	cin >> N;

	FILE * p; p = fopen ("result.txt","w"); 

	for (int i = 0; i < N; ++i)
	{
		int sMax;
		string data;
		cin >> sMax >> data;
		int needFriend = ComputeNeedFriend(sMax, data);
		fprintf(p, "Case #%d: %d\n", i+1, needFriend);
	}
	fclose(p);
	return 0;
}
