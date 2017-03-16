#include <vector>  
#include <list>  
#include <map>  
#include <set>  
#include <deque>  
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
#include <ctime>  
#include <cstring>  
using namespace std;  

#define lowbit(a)  a&(-a)

int a , n;
vector < int > s;
bool ha[110];
int M;

int dp[110][1000010];
int rmin(int a , int b){
	if (a == -1)return b;
	if (b == -1)return a;
	return min(a , b);
}

int main()  
{ 
	freopen("A-small-attempt1.in" , "r" , stdin);
	freopen("A-small-attempt1.out" , "w" , stdout);
	int t;
	int cas = 0;
	scanf("%d" , &t);
	while (t --){

		cas ++;
		scanf("%d %d" , &a , &n);
		s.clear();
		memset(ha , 0 , sizeof(ha));
		M = 0;
		for(int i = 0 ; i < n ; i ++){
			int tmp;
			scanf("%d" , &tmp);
			s.push_back(tmp);
			M = max(tmp , M);
		}
		sort(s.begin()  ,s.end());
		M ++;
		memset(dp , -1 , sizeof(dp));
		M = max(a , M);
		dp[0][a] = 0;
		for (int i = 0 ; i < n ; i ++){
			for (int j = 0 ; j <= M ; j ++){

				if (dp[i][j] == -1)continue;
				int sz = s[i];
				if (j > sz){
					int mm = min(M , j + sz);
					dp[i + 1][mm] = rmin(dp[i + 1][mm] , dp[i][j]);
					dp[i + 1][j] = rmin(dp[i + 1][j] , dp[i][j] + 1);
				}
				else{
					int tmp = j;
					int cnt = 0;
					while (tmp <= sz && tmp > 1){
						tmp += tmp - 1;
						cnt ++;
					}
					if (tmp > sz){
						int mm = min(M , tmp + sz);
						dp[i + 1][mm] = rmin(dp[i + 1][mm] , dp[i][j] + cnt);
						dp[i + 1][j] = rmin(dp[i + 1][j] , dp[i][j] + 1);
					}
					else{
						dp[i + 1][j] = rmin(dp[i + 1][j] , dp[i][j] + 1);
					}
				}
			}
		}
		int ans = -1;
		for (int i = 0 ; i <= M ; i ++){
			ans = rmin(ans , dp[n][i]);
		}
		printf("Case #%d: %d\n" , cas , ans );

	}


}
