#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
const int N = 55;
int best[N];
vector<int> pp;
int bitcnt[1 << 11];
void A()
{
	memset(bitcnt, 0 ,sizeof(bitcnt));
	for (int i = 0;i < (1 << 11); i++)
	{
		for (int j = 0;j < 11;j ++)
		{
			bitcnt[i] += ((i >> j) & 1) ? 1: 0;
		}
	}
}
bool cmp(int a,int b)
{
	return bitcnt[a] > bitcnt[b];
}
void init(int n)
{
	pp.clear();
	for (int i = 0;i < (1 << n);i ++)pp.push_back(i);
	sort(pp.begin(), pp.end(), cmp);
}
bool check(vector<int> vec)
{
	int n = vec.size();
/*	for (int i = 0;i < n;i ++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
*/	for (int i = 0;i < n;i ++)
	{
		if ((i > 0 && best[vec[i]] == vec[i - 1]) || (i < n - 1 && best[vec[i]] == vec[i + 1]))
		{
			continue;
		}
		if ((i == 0 && best[vec[i]] == vec[n - 1]))
		{
			continue;
		}
		if ((i == n - 1 && best[vec[i]] == vec[0]))
		{
			continue;
		}
		return false;
	}
	return true;
}
int main(){
	int T;
	A();
	cin >> T;
	for (int cas = 1;cas <= T;cas ++)
	{
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> best[i];
		}
		init(n);
		int maxn = 0;
/*
		for (int i = n;i >= 1;i --){
			bool flag = false;
			do{
				bool ret = check(V[i]);
				if (ret)
				{
					maxn = n;
					flag =true;
					break;
				}
			}while(next_permutation(V[i].begin(), V[i].end()));
			if (flag)
			{
				break;
			}
		}
		*/
//		for (int i = 0;i < pp.size();i ++)cout << pp[i] << " ";cout << endl;
		for (int i = 0;i < pp.size();i ++)
		{
			vector<int> vec;
			for (int j = 0;j < n;j ++)
			{
				if ((pp[i] >> j) & 1)
				{
					vec.push_back(j + 1);
				}
			}
			bool flag = false;
			do{
				if (check(vec))
				{
					maxn = max(maxn, (int)vec.size());
					flag = true;
					break;
				}
			}while(next_permutation(vec.begin(), vec.end()));
			if (flag == true)break;
		}
		cout << "Case #" << cas << ": " << maxn << endl;

	}	
	return 0;
}
