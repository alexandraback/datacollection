//by Tanmay Chaudhari
#include <bits/stdc++.h>

using namespace std;

#define si(a)				scanf("%d",&a)
#define sl(a)				scanf("%lld",&a)
#define sd(a)				scanf("%lf",&a)
#define ss(a)				scanf("%s",a)
#define pi(a)				printf("%d\n",a)
#define pl(a)				printf("%lld\n",a)
#define LL				    long long 

#define pb(x)				push_back(x)
typedef vector<int>			vi;
typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef vector<vii>			vvii;

//FILE *fin = freopen("input.txt","r",stdin);
//FILE *fout = freopen("output.txt","w",stdout);

#define MOD					1000000007
#define MAX					1000005

#define all(a)				a.begin(),a.end()
#define allrev(a)			a.rbegin(),a.rend()			
#define forall(i,a,b)		for(int i=a; i<b; i++)
#define forrev(i,a,b)		for(int i=a; i>=b; i--)
#define w(t)				int t;si(t);while(t--)

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define bit(x,i)					(x&(1<<i))  //select the bit of position i of x
#define lowbit(x)					((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n)					asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x
#define endl "\n"

void solve()
{
	int r, c, w;
	cin >> r >> c >> w;
	if (w == c)
		cout << c << endl;
	else
		cout << (ceil((c*r*1.0) / w) - 1 + w) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("A-large.in", "r", stdin);
	freopen("output1.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}