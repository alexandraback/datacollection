#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)
#define DFOR(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define S(n) scanf("%d",&n)
#define SLL(n) scanf("%lld",&n)
#define SD(n) scanf("%lf",&n)
#define SS(n) scanf("%s",n)
#define P(n) printf("%d\n",n)
#define PLL(n) printf("%lld\n",n)
#define PD(n) printf("%lf\n",n)
#define PS(n) printf("%s\n",n)
#define eps 1e-9
#define inf 1e9
#define PB push_back
#define PF push_front

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VLL;
typedef vector <double> VD;
typedef vector <string> VS;
typedef list <int> LI;
typedef list <LL> LLL;
typedef list <string> LS;
typedef list <double> LD;

bool isConsonant(char a)
{
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
		return false;
	return true;
}

int main()
{
	int T,n,len;
	LL cnt,ans;
	char str[1000001];
	S(T);
	REP(loop,1,T)
	{
		cnt=0;
		ans=0;
		cin>>str;
		cin>>n;
		len=strlen(str);
		int i=0,j=0;
		if(isConsonant(str[j]))
		{
			j++;
			cnt++;
		}
		while(j<len && cnt<n)
		{
			if(isConsonant(str[j]))
				cnt++;
			else
				cnt=0;
			j++;
		}
		//cout<<j<<endl;
		if(cnt==n)
			ans=ans+len-j+1;
		//cout<<ans<<endl;
		while(j<len)
		{
			//while(i<j && !isConsonant(str[i]))
				//i++;
			ans+=j-n-i;
			if(i==j-n)
			{
				cnt--;
				i=j-n+1;
			}
			else
				i=j-n;
			while(j<len && cnt<n)
			{
				if(isConsonant(str[j]))
					cnt++;
				else
					cnt=0;
				j++;
				if(cnt==n)
					j--;
			}
			//cout<<j<<endl;
			ans+=len-j;
			j++;
		}
		ans+=j-n-i;
		cout<<"Case #"<<loop<<": "<<ans<<endl;
	}
	return 0;
}