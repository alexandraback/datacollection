#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, m, a, b, maxi, mini, k, l, ans, cnt;
string s;
vector<string> str;
vector<pair <char, int> > datas[100];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("B_small_good.out","w",stdout);
	int test = 0;
	scanf("%d",&test);
	for(int t=0; t<test; t++)
	{
		scanf("%d %d %d",&a,&b,&k);
		
		int ans = 0;
		for(int i=0; i<b; i++)
		{
			for(int j=0; j<a; j++)
			{
			int asd = i&j;
				if(asd < k)
					ans++;
			}
		}
			printf("Case #%d: %d\n",t+1,ans);
	}

return 0;
}