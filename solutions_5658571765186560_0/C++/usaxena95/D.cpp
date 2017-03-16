/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("small.out","w",stdout);

	int T,x,r,c;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		printf("Case #%d: ",t);
		cin>>x>>r>>c;
		if(x >= 7)
			cout<<"RICHARD\n";
		else
		{
			int A = r*c;
			if(A % x != 0)
				cout<<"RICHARD\n";
			else
			{
				if(x == 1 || x == 2)
					cout<<"GABRIEL\n";
				else
				{
					int HA = x/2;
					if(min(r,c) <= HA || max(r,c) < x)
						cout<<"RICHARD\n";
					else
						cout<<"GABRIEL\n";
				}
			}
		}
	}
}
