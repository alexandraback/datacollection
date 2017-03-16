#include<bits/stdc++.h>

using namespace std;

string x,y;

int ans;

vector <int> s;

map < pair<int,int>, int> ma;
map<string,int> m;

int n;

int v[50],p[50],q[50];

void check(int f)
{
	if(f==n)
	{
		s.clear();
		ma.clear();
		
		int cnt=0;
		
		for(int i=0;i<n;i++)
			if(!v[i])
				s.push_back(i);
				
		for(int i=0;i<n;i++)
			if(v[i])
			{
				for(int k=0;k<n;k++)
					for(int j=0;j<n;j++)
						if(!v[k] && !v[j] && p[k]==p[i] && q[i]==q[j] && !ma[make_pair(k,j)] && k!=i && j!=i && k!=j)
						{
							ma[make_pair(k,j)]=1;
							goto ab;
						}
				return;
				
				ab:
				cnt++;
			}
			
		ans=max(ans,cnt);
			
		return;
	}
	
	v[f]=1;
	
	check(f+1);
	
	v[f]=0;
	
	check(f+1);
}


int main()
{
	
	freopen("C-small-attempt1.in","r",stdin);
	freopen("aa.txt","w",stdout);
	
	int t;
	
	cin >> t;
	
	for(int tt=0;tt<t;tt++)
	{
		cout << "Case #" << tt+1 << ": ";
	
		ans=0;
	
		cin >> n;
		
		int cnt=0;
		
		m.clear();
		
		for(int i=0;i<n;i++)
		{
			cin >> x >> y;
			
			if(!m[x])
				m[x]=++cnt;
			
			if(!m[y])
				m[y]=++cnt;
				
			p[i]=m[x];
			q[i]=m[y];
		}
		
		check(0);
		
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
