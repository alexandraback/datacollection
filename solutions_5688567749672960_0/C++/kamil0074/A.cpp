#include<iostream>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;


queue<pli> Q;

ll odw(ll x)
{
	ll a=0;
	while(x!=0)
	{
		a*=10;
		a+=x%10;
		x/=10;
	}
	return a;
}

map<ll,bool> M;

int main()
{

	int z;
//	cout<<odw(12)<<endl;
//	cout<<odw(99)<<endl;
//	cout<<odw(211)<<endl;
//	cout<<odw(200)<<endl;
//	cout<<odw(34)<<endl;
	cin>>z;
	for(int v=0;v<z;v++)
	{
		ll n;
		cin>>n;
		Q.push(pli(n,1));
		while(Q.front().first!=1)
		{
			pli ee=Q.front();
			Q.pop();
			if(!M[ee.first-1])
			{
				Q.push(pli(ee.first-1,ee.second+1));
				M[ee.first-1]=true;
			}
			if(ee.first%10!=0)
			{
				if(!M[odw(ee.first)])
				{
					Q.push(pli(odw(ee.first),ee.second+1));
					M[odw(ee.first)]=true;
				}
			}
		}
		cout<<"Case #"<<v+1<<": "<<Q.front().second<<endl;
		while(!Q.empty())
		{
			Q.pop();
		}
		M.clear();
	}

}
