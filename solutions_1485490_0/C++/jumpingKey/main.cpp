#include <iostream>

using namespace std;
struct Node
{
	long long c; int num; 
}box[105],toy[105];
int T,n,m;

long long min(long long a,long long b)
{
	if (a > b) return b;
	else return a;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&T);
	
	for (int ca = 1;ca <= T;++ca)
	{
		printf("Case #%d: ",ca);
		scanf("%d %d",&n,&m);
		for (int i = 0;i < n;++i) cin >> box[i].c >>box[i].num;
		for (int i = 0;i < m;++i) cin >> toy[i].c >>toy[i].num;

		long long ans = 0;
		for (int i = 0;i < n;++i)
		{
			long long sum1 = 0,sum2 = 0,sum3 = 0;
			int j,k,l;
			for (j = 0;j < m;++j)
			{
				if (box[i].num == toy[j].num && toy[j].c != 0)
					break;
				else
					sum1 += toy[j].c;
			}
			for (k = j;k < m;++k)
			{
				if (box[i].num == toy[k].num)
					sum2 += toy[k].c;
				else break;
			}

			long long tt = min(box[i].c,sum2);
			long long left[5] = {0};

			for (int x = i+1;x < n;++x)
			{
				for (int y = 0;y < j;++y)
				{
					if (box[x].num == toy[y].num) left[x] += toy[y].c;
				}
			}

			long long _max = -2000000000000000;
			for (int x = i+1;x < n;++x)
			{
				if (_max < left[x]) _max = left[x];
			}

			if ( _max < tt)
			{
				if (box[i].c > sum2)
				{
					ans += sum2;
					box[i].c -= sum2;
					//--i;
					for (int ind = 0;ind < k;++ind) toy[ind].c = 0;
				}
				else
				{
					ans += box[i].c;
					for (l = k;l < m;++l)
					{
						sum3 += toy[l].c;
						if (sum3 >= box[i].c) break;
					}
					toy[l].c -= (box[i].c - sum2);
					for (int ind = 0;ind < l;++ind) toy[ind].c = 0;
				}
			}
		}

		/*if (n == 1)
		{
			for (int i = 0;i < m;++i)
			{
				if (box[0].num == toy[i].num) ans += box[i].c;
			}
			ans = min(ans,box[0].c);
		}
		else if (n == 2)
		{
			long long sum1,sum2 = 0;
			int i,j;
			for ( i = 0;i < m;++i)
			{
				if (box[0].num == toy[i].num) break;
			}
			for (j = i;j < m;++j)
			{
				if (box[0].num != toy[i].num) break;
				else sum2 += toy[i].c;
			}
			if (sum2 > box[1].c)
			{
				long long tt = min(box[0].c,sum2);
				ans += tt;
			}
		}*/
		cout << ans <<endl;
	}

	return 0;
}