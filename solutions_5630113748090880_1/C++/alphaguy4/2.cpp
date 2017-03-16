#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define si(i) scanf("%d",&i)
#define fs first
#define sc second
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define REP(i,k) for(int i=0;i<k;i++)
#define FORR(i,j,k) for(int i=n;i>=k;i--)
#define MOD 1000000007
using namespace std;
int main()
{
	//Let's start
	int t;
	si(t);
	int Case = 1;
	while(t--)
	{	
		int n,tmp;
		si(n);
		int t1;
		int hash[2505]={0};
		for(int i=0;i<2*n-1;i++)
		{
			
			for(int j=0;j<n;j++)
			{	
				si(tmp);
				hash[tmp]++;
			}
			//cout << "1" << endl;
		}
		std::vector<int > v;
		REP(i,2501)
		{
			if(hash[i] % 2 != 0)
			{
				v.pb(i);
			}
		}
		//cout << v.size();
		printf("Case #%d: ",Case++);
		sort(v.begin(),v.end());
		FOR(i,0,n)
		{
			printf("%d ",v[i]);
		}
		cout << endl;
	}
	return 0;
}