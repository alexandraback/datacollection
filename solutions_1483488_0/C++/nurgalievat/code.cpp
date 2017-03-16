#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<utility>
using namespace std;

int pw[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int t,a,b,ans;
int cyc,m;
int pow;
typedef pair<int,int> pii;
set<pii> st;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>a>>b;
		ans=0;
		cyc=a;
		pow=0;
		st.clear();
		while(cyc)
		{
			pow++;
			cyc/=10;
		}
		pow--;
		for(int i=a;i<=b;i++)
		{
			cyc = i;
			for(int j=0;j<pow;j++)
			{		
				m = cyc%10;
				cyc/=10;
				cyc = m*pw[pow]+cyc;
				if(cyc<=i || cyc>b)
					continue;
				ans++;
				//cout<<i<<' '<<cyc<<endl;
				pii p;
				p.first = i;
				p.second = cyc;
				if(!st.insert(p).second)
				{
					//cout<<i<<' '<<cyc<<endl;
					ans--;
				}
			}
		}
		cout<<"Case #"<<T<<": "<<ans<<endl;
	}
	return 0;
}