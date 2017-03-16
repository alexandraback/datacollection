//Author : pakhandi
//
using namespace std;

#include<bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

#define si(n) scanf("%d", &n)
#define sll(l) scanf("%lld",&l)
#define ss(s) scanf("%s", s)
#define sc(c) scanf("%c", &c)
#define sd(f) scanf("%lf", &f)

#define pi(n) printf("%d\n", n)
#define pll(l) printf("%lld\n", l)
#define ps(s) printf("%s\n", s)
#define pc(c) printf("%c\n", c)
#define pd(f) printf("%lf\n", f)

#define debug(x) cout<<"\n#("<<x<<")#\n"
#define nline printf("\n")

#define mem(a,i) memset(a,i,sizeof(a))

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define PB push_back
#define SZ size
#define MP make_pair
#define fi first
#define sec second

std::vector<pair<string,string> > words;
int n;

int dp[1<<17];

int rec(int mask)
{
	int i;

	//cout<<mask<<" ";

	if(mask == (1 << 17) - 1)
		return 0;



	int &ret = dp[mask];

	if(ret != -1 )
		return ret;

	ret = 0;

	set<string> firstW, secondW;
	firstW.clear();
	secondW.clear();

	fl(i,0,n)
	{
		if( mask & (1 << i) )
		{
			firstW.insert(words[i].first);
			secondW.insert(words[i].second);
		}
	}

	fl(i,0,n)
	{
		if ( ! ( mask & (1 << i) )  )
		{
			if( firstW.find(words[i].first) != firstW.end()
				&&
				secondW.find(words[i].second) != secondW.end() )
			{
				//cout<<"h";
				ret = max(ret, 1 + rec( mask | (1 << i) ));
			}
			else
			{
				ret = max(ret, rec( mask | (1 << i) ));
			}
		}
	}

	return ret;
}

int main()
{
	int i, j;

	int cases;
	int caseNo = 1;

	cin>>cases;

	wl(cases)
	{
		cin>>n;

		words.clear();
		mem(dp,-1);

		fl(i,0,n)
		{
			string str1, str2;
			cin>>str1>>str2;
			words.PB(MP(str1,str2));
		}

		cout<<"Case #"<<caseNo<<": ";
		caseNo++;
		cout<<rec(0);
		nline;

	}


	return 0;
}
/*
	Powered by Buggy Plugin
*/
