#include <bits/stdc++.h>
#define forall(i,a,b)               for(int i=a;i<=b;i++)
#define pb                          push_back
#define mp			  			    make_pair
#define MOD                         1000000007

#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map <string, int> msi;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }

int  k, l, s,cnt,temp,tot,mx;
string  keys, target,x;
void rec()
{
 
	if (x.length() == s)
	{
		temp = 0;
		forall(i,0,s-1)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	forall(i,0,k-1)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}	
}

int main()
{
	 #ifndef ONLINE_JUDGE
     	freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
     #endif
     ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	forall(kase,1,t)
	{
		cin>>k>>l>>s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		cout<<"Case #"<<kase<<": ";
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
		

	}
	return 0;
}
