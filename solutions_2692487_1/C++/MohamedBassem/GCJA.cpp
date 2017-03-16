#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define sor(a) sort((a).begin(),(a).end())
#define FOR(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
int a,n,arr[1000010],maxi;
int dp[101][1000010];
int solve(int i,int size){
	if(i == n)
		return 0;
	
	if(size > maxi)
		return 0;

	if(dp[i][size] != -1)
		return dp[i][size];

	if(size > arr[i])
		return dp[i][size] = solve(i+1,size+arr[i]);
	else if(2*size-1 == size)
		return dp[i][size] = 1+ solve(i+1,size);
	else
		return dp[i][size] = 1+ min (solve(i+1,size) , solve(i ,2*size -1 ) );
}	
int main()
{
	// freopen("test.txt","r",stdin);

	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	cin >> t;
	FOR(tc,1,t+1){
		cin >> a >> n;
		maxi = 0;
		FOR(i,0,n){
			cin >> arr[i];
			maxi = max(maxi,arr[i]);
		}
		sort(arr,arr+n);
		memset(dp,-1,sizeof dp);

		cout << "Case #" << tc << ": " << solve(0,a) << endl;
	}
}