#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

vector<int> gv;
map<long long, vector<int> > mres;
bool f = false;
vector<int> set1, set2;

void init()
{
	gv.clear();
	mres.clear();
	f = false;
	set1.clear();
	set2.clear();
}


bool isValid(vector<int> v1, vector<int> v2)
{
	for(int i = 0; i < v1.size(); ++i)
	{
		for(int j = i+1; j < v2.size(); ++j)
		{
			if( v1[i] == v2[j] )
				return false;
		}
	}
	return true;
}
void solve(int curr, long long sum, vector<int> res, bool test)
{
	if(f)
		return;

	if(curr == gv.size() )
		return;

	if(test && mres[sum].size() )
	{
		set1 = mres[sum];
		set2 = res;
		if( isValid(set1, set2) )
		{
			f = true;
			return;
		}
	}
	else
	{
		mres[sum] = res;
	}

	solve(curr+1, sum, res, 0);
	if(f)
		return;

	res.push_back(gv[curr]);
	solve(curr+1, sum + gv[curr], res, 1);
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
	int T;
	scanf("%d", &T);
	for(int C = 0; C < T; ++C)
	{
		
		int N;
		scanf("%d", &N);
		init();
		vector<int> v;
		int temp;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d",&temp);
			v.push_back(temp);
		}

		gv = v;
		vector<int> vt;
		solve(0, 0, vt, 0);
		printf("Case #%d: ", (C+1));
		if(f)
		{
			printf("\n");
			for(int i = 0; i <(int)set1.size()-1; ++i)
			{
				printf("%d ", set1[i]);
			}
			printf("%d\n", set1[(int)set1.size()-1]);
			
			for(int i = 0; i <(int)set2.size()-1; ++i)
			{
				printf("%d ", set2[i]);
			}
			printf("%d\n", set2[(int)set2.size()-1]);
		}
		else
		{
			printf("Impossible\n");
		}

	}
	return 0;
}