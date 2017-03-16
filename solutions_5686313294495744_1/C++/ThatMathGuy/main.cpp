#include <bits/stdc++.h>

using namespace std;


map<string,int> m;

vector<int> e[2005];

int n;

int r = 0;

int le,ri;

///////

vector<bool> us;
vector<int> mt;
 
bool kuhn (int x)
{
    if (us[x]) return false;
    us[x]  = 1;
    for (auto i:e[x])
        if (mt[i]==-1 || kuhn(mt[i]))
            {
                mt[i] = x;
                return true;
            }
    return false;
}
 
void solve()
{
	mt.assign(ri+1,-1);
	for (int i=1; i<le+1; i++)
    {
        us.assign(le+1,0);
        kuhn(i);
    }
    
    int x = 0;
    
    for (int i=1; i<ri+1; i++)
    	x+=(mt[i]>0);
    	
    r -= le+ri-x;
}

//

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tst;
	cin>>tst;
	for (int ntst = 1; ntst<=tst; ntst++)
	{
		cout<<"Case #"<<ntst<<": ";	
		
		cin>>n;	
		
		le = ri = 0;	
		
		r = n;
		
		m.clear();
		for (int i=0; i<=2*n+3; i++)		
			e[i].clear();
			
		for (int i=0; i<n; i++)
		{
			string a,b;
			cin>>a>>b;
			a+="1";
			b+="2";
			if (!m[a]) m[a] = ++le;
			if (!m[b]) m[b] = ++ri;
			e[m[a]].push_back(m[b]);
		}
		
		solve();
		
		cout<<r;
		
		cout<<'\n';
	}

    return 0;
}

