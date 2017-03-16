#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <stack>

using namespace std;
int find(char s[100], int len) //? ????? ?????? ????? ???????? ????? ?????
{
	int k = -1;
	for(int i=1;i<len;i++)
	{
		int flag = 1;
		for(int j=0;j<len-i;j++)
		{
			if(s[i] != s[j])
				flag = 0;
		}
		if(flag == 1)
		{
			k = i;
			break;
		}
	}
	return k;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	double cnt;
	int K, L, S;
	char k[100], l[100];
	for(int t1 = 1;t1<=T;t1++)
	{
		map<char,int> mp;
		map<char,double> imov;
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", &k);
		scanf("%s", &l);
		for(int i=0;i<K;i++)
			mp[k[i]]++;
		for(int i=0;i<K;i++)
			imov[k[i]] = (double)mp[k[i]]/K;
		int flag = 1;
		for(int i=0;i<L;i++)
			if(mp[l[i]] == 0)
				flag = 0;
		if(S < L)
			flag = 0;
		int Max = 0;
		if(flag != 0)
		{
			int k = find(l,L);
			if(k == -1)
				Max = S/L;
			else
			{
				Max = 1;
				int temp = L;
				while(temp<=L)
				{
					temp += k;
					Max++;
				}
			}
			double res = 1;
			double res1 = 1;
			for(int i=0;i<L;i++)//???? ??? ??????
				res *= imov[l[i]];
			cnt = 0;
			if(k != -1)
			{
				int len = L - k;
				for(int i=len;i<L;i++)
					res1 *= imov[l[i]];
				cnt += res;
				for(int i=2;i<=Max;i++)
				{
					res*=res1;
					cnt += res;
				}
			}
			else
			{
				double ress = res;
				cnt += res;
				for(int i=2;i<=Max;i++)
				{
					res*=ress;
					cnt += i*res;
				}
			}
			cnt = Max - cnt;
			if(cnt<0)
			cnt = 0;
			printf("Case #%d: %.6lf\n", t1, cnt);
		}
		else
		printf("Case #%d: 0.000000\n", t1);
	}
	system("Pause");
	return 0;
}
