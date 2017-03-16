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
string a, b;
int k, l, s;
long long pw(long long b, long long p)
{ 
	if (!p) 
		return 1; 
	long long sq = pw(b, p / 2); 
	sq *= sq; 
	if (p % 2) 
		sq *= b; 
	return sq; 
}
int temp;

ii solve2(int index, string x)
{
	if (index == s)
	{
		temp = 0;
		forall(i,0,s-l+1)
		{
			if (!x.compare(i, l, b))
				temp++;
		}
		return make_pair(temp, temp);
	}
	ii ans = make_pair(0, -(0x7f7f7f7f));
	forall(i, 0, k)
	{
		ii tmp = solve2(index + 1, x + a[i]);
		ans.second = max(ans.second, tmp.second);
		ans.first += tmp.first;
	}
	return ans;
}

void solve()
{
	
	si(k); si(l); si(s);
	cin >> a >> b;
	ii res = solve2(0, "");
	double ans = (double)res.second - double(res.first) / double(pw(k, s));
	printf("%.12f\n", ans);
}


int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int t;
	si(t);
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}