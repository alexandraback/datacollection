#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#define REP(x,y) for(x=0;x<y;x++)
#define REPI(x,y) for(x=1;x<=y;x++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;

int N,M,n,m,k,i;
set<int> s;
int z[110][110];
bool u[110][110];

int main()
{
    int a,b,c,d;
	int xx,R;
	int cnt,all;
	int chk,tp,nx;
	cin >> R;
	REP(xx,R){
		cin >> N >> M;
		s.clear();
		REP(a,N)REP(b,M)
		{
			cin >> z[a][b];
			s.insert(z[a][b]);
		}
		s.insert(100);
		chk=1;
		while(!s.empty())
		{
			tp = *s.begin();
			s.erase(s.begin());
			if(!s.empty())nx = *s.begin();
			else nx=100;
			cnt=all=0;
			REP(a,N)REP(b,M)
			{
				u[a][b]=0;
				if(z[a][b]==tp)all++;
			}
			REP(a,N)
			{
				c=0;
				REP(b,M)
				{
					if(z[a][b]==tp)c++;
				}
				if(c==M)
				{
					REP(b,M)
					{
						if(u[a][b]==0)cnt++;
						u[a][b]=1;
					}
				}
			}
			REP(b,M)
			{
				c=0;
				REP(a,N)
				{
					if(z[a][b]==tp)c++;
				}
				if(c==N)
				{
					REP(a,N)
					{
						if(u[a][b]==0)cnt++;
						u[a][b]=1;
					}
				}
			}
			if(cnt!=all)
			{
				chk=0;
				break;
			}
			REP(a,N)REP(b,M)
			{
				if(z[a][b]==tp)z[a][b]=nx;
			}
		}
		printf("Case #%d: ",xx+1);
		if(chk)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
