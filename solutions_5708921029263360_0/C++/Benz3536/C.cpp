#include<bits/stdc++.h>
#define mp make_tuple
using namespace std;
vector<tuple<int,int,int> > v;
int m[5][20][5][20],n[20][20][20];
int main()
{
	freopen("C-small-attempt3.in","r",stdin);
	freopen("C-small-attempt3.txt","w",stdout);
	int T,P,S,K,J,a,b,c,d,e,check;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	for(e=0;e<T;e++)
	{
		memset(m,0,sizeof(m));
		memset(n,0,sizeof(n));
		v.clear();
		check=1;
		cin>>J>>P>>S>>K;
		while(check)
		{
			check=0;
			for(a=0;a<J;a++)
			{
				for(b=0;b<P;b++)
				{
					for(c=0;c<S;c++)
					{
						if(m[0][a][1][b]<K&&m[0][a][2][c]<K&&m[1][b][2][c]<K&&n[a][b][c]==0)
						{
							n[a][b][c]++;
							m[0][a][1][b]++;
							m[0][a][2][c]++;
							m[1][b][2][c]++;
							v.push_back(mp(a,b,c));
							check=1;
							break;
						}
					}
				}
			}
		}
		
		cout<<"Case #"<<e+1<<": "<<v.size()<<"\n";
		for(a=0;a<v.size();a++)
		{
			tie(b,c,d)=v[a];
			cout<<b+1<<" "<<c+1<<" "<<d+1<<"\n";
		}
	}
}
