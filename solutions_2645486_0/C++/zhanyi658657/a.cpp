#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<fstream>
using namespace std;
#include <iostream>   
#include<algorithm>
#define INF 100000000    
using namespace std;  
const double PI = acos(-1.0);

int v[2000];

int imax = 0;
int E, R, N;


void solve()
{
	
	cin>>E>>R>>N;
	for (int i = 0;i < N;++i) {
		cin>>v[i];
	}
	int ans[100][100];
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < E;++j) {
			ans[i][j] = 0;
		}
	}
	for (int i = 0;i < N;++i) {
		if(i == 0) {
			for (int j = 0;j <= E;++j) {
				ans[i][j] = j * v[i];
			}
		} else {
			for (int j = 0;j <= E;++j) {
				int tmpmax = 0;
				for (int t = 0;t <= j;++t) {
					int remain = j - t + R;
					if(remain >= E)remain = E;
					if(v[i] * t + ans[i - 1][remain] > tmpmax) {
						tmpmax = v[i] * t + ans[i - 1][remain];
					}
				}
				ans[i][j] = tmpmax;
			}
		}
	}
	cout<<ans[N - 1][E]<<endl;
}
int main()
{
	//freopen("data.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int t = 0;
	scanf("%d", &t);

	for(int i = 0;i < t;++i) {
		cout<<"Case #"<<i + 1<<": ";
		solve();
	}
	return 0;
}