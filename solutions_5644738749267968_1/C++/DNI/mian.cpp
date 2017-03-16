#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<map>
#include<set>

using namespace std;


int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("Dlarge.out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{


		int n;
		cin >> n;

		set<long double> a, b;
		for(int i = 0; i < n; i++)
		{
			long double r;
			cin >>r;
			a.insert(r);
		}
		for(int i = 0; i < n; i++)
		{
			long double r;
			cin >>r;
			b.insert(r);
		}
		
		int r1 = 0, r2 = 0;
		set<long double> a1 = a, b1 = b;

		set<long double>::iterator it_a, it_b;

		for(it_a = a.begin(); it_a != a.end(); it_a++)
		{
			bool bD = false;
			for(it_b = b.begin(); it_b != b.end(); it_b++)
			{
				if(*it_b > *it_a)
				{
					bD = true;
					b.erase(it_b);
					break;
				}
			}
			if(!bD)
			{
				r1++;
				b.erase(b.begin());
			}
		}

		a = a1;
		b = b1;

		while(!a.empty())
		{
			it_a = a.begin();
			//it_a--;
			it_b = b.begin();
			//it_b--;
			if(*it_a > *it_b)
			{
				r2++;
				a.erase(it_a);
				b.erase(b.begin());
			}
			else
			{
				b.erase(--b.end());
				a.erase(a.begin());
			}
		}

		printf("Case #%d: %d %d\n", tt+1, r2, r1);

		//int n = 5, k = 3;
		//long double d = 0;
		//for(int i =0; i< k; i++ )
		//	d+= 1/(long double)(n*i+2);
		//cout << d << "	"<<(n - 4)/(long double)(2*n-2);
	
		//if(res == 1)
		//{
		//	printf("Case #%d: %d\n", tt+1, ans);
		//}
		//else if(res == 0)
		//{
		//	printf("Case #%d: Volunteer cheated!\n", tt+1);
		//}
		//else
		//{
		//	printf("Case #%d: Bad magician!\n", tt+1);
		//}
	}
	return 0;
}

