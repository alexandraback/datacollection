#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007
int digs(int num)
{
    int count = 0;
    while(num!=0)
    {
        count++;
        num/=10;
    }
    return count;
}
int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int n;
		cin>>n;
		vi dp(n+1,0);
		dp[1] = 1;
		fore(i,2,n+1)
		{
		    int num = i;
		    int rev = 0;
		    dp[i] = dp[i-1] + 1;
		    while(num!=0)
            {
                int dig = num%10;
                rev = (rev*10)+dig;
                num/=10;
            }
            if(rev<i && digs(rev) == digs(i))
            {
                dp[i] = min(dp[i],dp[rev] + 1);
            }
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
