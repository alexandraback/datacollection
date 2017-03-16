#include<bits/stdc++.h>
using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)

typedef string            ss;
typedef long long         ll;
ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	ofstream outfile;
	outfile.open("output.txt");
	ifstream infile; 
   	infile.open("input.txt"); 
	infile>>t;
	lop(i, t)
	{
		infile >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		outfile<<"Case #"<<i+1<<": ";
		outfile <<fixed<<setprecision(6)<<mx-double(cnt)/tot<<endl;
	}
}