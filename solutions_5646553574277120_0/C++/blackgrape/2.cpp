#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.begin())y=x.begin();y!=x.end();y++)
#define pb(f) push_back(f)
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a)
using namespace std;
//#include<windows.h>
FILE *fin = freopen("1.in","r",stdin);
FILE *fout = freopen("1.txt","w",stdout);
set<int> s;
typedef vector<int> vi;
vi vpp;
int main()
{
	int t;
	sc(t);
	int casse=0;
	while(t--)
	{
		s.clear();
		casse++;
		int i,j,k,l,c,v,d,dat[6];
		bool boole[31];
		sc(c);sc(d);sc(v);
		rep(i,1,d+1)
		{
			sc(dat[i]);
		}
		rep(i,1,v+1)
		boole[i]=false;
		boole[0]=true;
		s.insert(0);
		rep(i,1,d+1)
		{
			vpp.clear();
			trv(it,s)
			{
				vpp.pb(*it);
				
			}
			trv(it,vpp)
			{
				int aaa=*it+dat[i];
				if(aaa<=v)
				{
					boole[aaa]=true;
					s.insert(aaa);
				}
			}
		//	s.insert(dat[i]);
			
		}
	/*	trv(it,s)
			{
				int p=*it;
			cout<<p<<" "<<endl<<endl;
				
			}*/
		int ans=0;
		for(i=1;i<=v;i++)
		{
			if(boole[i]==true)
			continue;
			ans++;
			vpp.clear();
			trv(it,s)
			{
				vpp.pb(*it);
			}
			trv(it,vpp)
			{
				int aaa=*it+i;
				if(aaa<=v)
				{
					boole[aaa]=true;
					s.insert(aaa);
				}
			}
		}
		printf("Case #%d: %d\n",casse,ans);
	}
}
