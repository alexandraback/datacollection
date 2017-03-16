#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define fo(i, n) for (int i = 0; i < (n); i++)
#define rfo(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;


const int MAXN = 2000010;
int visited[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	int T;
	cin >> T;
	fo(casenum,T)
	{
		int A,B;
		int deg = 0;
		int k = 1;
		ll answer = 0;
		
		cin >> A >> B;
		clr(visited,0);
		int temp = A;
		while (temp)
		{
			deg++;
			temp /= 10;
		}
		fo(i,deg-1)
			k = k * 10;
		for(int i = A; i <= B; ++i)
		{
			if (!visited[i])
			{
				int count = 0;
				int number = i;
				fo(j,deg)
				{
					int digit = number % 10;
					number /= 10;
					number = k*digit + number;
					if (number >= A && number <= B && !visited[number])
						count++;
					visited[number] = 1;	
				}
				if (count >= 2)
				{
					//cout << i << " " << count << endl;
					answer += count*(count-1)/2;
				}
			}
		}
		cout << "Case #" << casenum+1 << ": " << answer << endl;
	}
	
	
	return 0;
}