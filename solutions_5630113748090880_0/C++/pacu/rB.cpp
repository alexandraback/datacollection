#include <iostream>
#include <fstream>
using namespace std;

int l[100][50];
int N;

bool seen[100];
int cnt[2501];
int ans[50];

void test(int num)
{
	cin >> N;
	for(int i=0;i<2*N-1;i++)
	{
		seen[i] = 0;
		for(int j=0;j<N;j++)
			cin >> l[i][j];
	}
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<=2500;i++) cnt[i] = 0;
		int low1 = -1;
		int low2 = -1;
		for(int i=0;i<2*N-1;i++)
		{
			if(seen[i]==0)
			{
				if(low1==-1 || l[i][k] <= l[low1][k])
				{
					low2 = low1;
					low1 = i;
				}
				else if(low2==-1 || l[i][k] <= l[low2][k])
					low2 = i;
			}
			cnt[l[i][k]]++;
		}
		if(low2 == -1 || l[low1][k]!=l[low2][k])
		{
			ans[k] = l[low1][k];
			seen[low1] = 1;
			continue;
		}
		for(int j=0;j<N;j++)
		{
			cnt[l[low1][j]]--;
			cnt[l[low2][j]]--;
		}
		for(int j=0;j<N;j++)
		{
			if(cnt[l[low1][j]]<0)
				ans[k] = l[low1][j];
			if(cnt[l[low2][j]]<0)
				ans[k] = l[low2][j];
		}
		seen[low1] = 1;
		seen[low2] = 1;
	}
	cout << "Case #" << num << ":";
	for(int i=0;i<N;i++)
		cout << ' ' << ans[i];
	cout << '\n';
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) test(i+1);
}