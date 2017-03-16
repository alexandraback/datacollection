#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
//#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pint;
typedef pair<LL,LL> pll;
#define fi first
#define se second
typedef map<int,int> mapint;
typedef vector<int> vint;
typedef vector<vint> vintp;
#define pb push_back
#define mp make_pair
#define SIZE(i) ((int)(i.size()))


int m,n,j,k,l,i,o,p,__t,R,N,M,K,product[1000],num[1000],could[10000];
int ans = 0;
vint ans_vector;


char ch;
void read(int &a)
{
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

/*void DFS(int P, int t2, int t3, int t4, int t5, int nowg)
{
	if (P == N + 1) 
	{
		
	}
	
	if (t2 != 0) 
	{
		DFS(P + 1, t2 - 1, t3, t4, t5, nowg * 2);
		DFS(P + 1, t2 - 1, t3, t4, t5, nowg);
	} else 
	if (t3 != 0) 
	{
		DFS(P + 1, t2, t3 - 1, t4, t5, nowg * 3);
		DFS(P + 1, t2, t3 - 1, t4, t5, nowg);
	} else 
	if (t4 != 0) 
	{
		DFS(P + 1, t2, t3, t4 - 1, t5, nowg * 4);
		DFS(P + 1, t2, t3, t4 - 1, t5, nowg);
	} else 
	if (t5 != 0) 
	{
		DFS(P + 1, t2, t3, t4, t5 - 1, nowg * 5);
		DFS(P + 1, t2, t3, t4, t5 - 1, nowg);
	}
}*/

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);

	cin >> o;
	printf("Case #1:\n");
	cin >> R >> N >> M >> K;
	
	for (; R --; )
	{
		ans = 0;
		ans_vector.clear();
		memset(could, 0, sizeof could);
		
		bool op = 0;
		for (int i = 1; i <= K; i ++)
		{
			cin >> product[i];
			int j = product[i],z;
			z = 0;
			for (; j % 2 == 0; j /= 2) z ++;
			could[2] = max(could[2], z);
			if (z == 1) op = 1;
			z = 0;
			for (; j % 3 == 0; j /= 3) z ++;
			could[3] = max(could[3], z);
			z = 0;
			for (; j % 5 == 0; j /= 5) z ++;
			could[5] = max(could[5], z);
		}
		sort(product + 1, product + 1 + K);
		ans_vector.clear();
		
		if (could[5] == 3) {
			for (int k = 1; k <= 3; k ++)
				ans_vector.pb(3);
		} else 
		if (could[5] == 2) {
			for (int k = 1; k <= 2; k ++)
				ans_vector.pb(5);
				
			if (could[2] == 2)
				ans_vector.pb(4);
			else 
			if (could[3] == 1)
				ans_vector.pb(3);
			else 
				ans_vector.pb(2);
		}
		else		
		if (could[5] == 1) {
			ans_vector.pb(5);
			if (op)
			{
				ans_vector.pb(2);
				if (could[2] >= 3 && could[3] == 0)
					ans_vector.pb(4);
				else 
				if (could[3] == 0)
					ans_vector.pb(2);
				else 
					ans_vector.pb(3);
			} else
			{
				if (could[2] >= 2)
					ans_vector.pb(4);
				if (could[3] >= 1)
					ans_vector.pb(3);
				else 
					ans_vector.pb(2);
			}
		}
		else
		{
			for (int i = 1; i <= could[3]; i ++)
				ans_vector.pb(3);
			int ret = N - could[3];
			if (could[2] >= 2)
				ret --, ans_vector.pb(4);
			for (; ret --; )
				ans_vector.pb(2);
		}
		
		if (SIZE(ans_vector) == 2)
			ans_vector.pb(2);
		for (int i = 0; i < SIZE(ans_vector); i ++)
			cout << ans_vector[i];
		cout << endl;
	}
	
	fclose(stdin); fclose(stdout);
}
