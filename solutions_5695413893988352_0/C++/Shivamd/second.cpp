#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t,i,tt=1;
string a,b,a1,ans[4];
set< string >se[4];


void rec(ll ii,ll jj)
{
	if(ii==a.size()){
		se[jj].insert(a);
		return ;
	}

	ll aa=0,bb=0;
	if(a[ii]=='?'){
		for(ll i=0;i<=9;i++)
		{
			a[ii]=char('0'+i);
			aa=1;
			rec(ii+1,jj);
			a[ii]='?';
		}
	}
	else{
		rec(ii+1,jj);
	}

}

int main()
{
    freopen("C:/Users/SHIVAM/Desktop/B-small-attempt0 (2)", "r", stdin);
	freopen("C:/Users/SHIVAM/Desktop/out.txt", "w", stdout);


	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		rec(0,0);

		a1 = a;
		a = b;
		rec(0,1);

		ll mi = 10000000;
        set< string >::iterator it,it1;
		for( it=se[0].begin();it!=se[0].end();++it)
		{
			for(it1=se[1].begin();it1!=se[1].end();++it1)
			{
				ll k1 = stoi(*it);
				ll k2 = stoi(*it1);
				ll val = abs(k1-k2);
				if(val<mi)
				{
					mi = val;
					ans[0] = *it;
					ans[1] = *it1;
				}
				else if(val==mi)
				{
					if(*it<ans[0])
					{
						ans[0] = *it;
						ans[1] = *it1;
					}
					else if(*it==ans[0])
					{
						if(*it1<ans[1])
						{
							ans[0] = *it;
							ans[1] = *it1;
						}
					}
				}
			}
		}
		cout<<"Case #"<<tt<<": ";
		cout<<ans[0]<<" "<<ans[1]<<"\n";
		se[0].clear();se[1].clear();
		tt++;
	}
	return 0;
}
