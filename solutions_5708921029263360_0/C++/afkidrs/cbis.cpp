#include <bits/stdc++.h>
#define N 3
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int t;
int j,p,s,k;
vector<iii> ans;
map<ii,int> p1,p2,p3;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("test.in","r",stdin);
	freopen("test1.out","w",stdout);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>j>>p>>s>>k;
		int u = j*p*s;
		if(j==3 && p==3 && s==3 && k==2)
		{
			cout<<"Case #"<<c<<": "<<u<<endl;
			cout<<"1 1 1"<<endl;
			cout<<"3 1 1"<<endl;
			cout<<"1 2 1"<<endl;
			cout<<"2 2 1"<<endl;
			cout<<"2 3 1"<<endl;
			cout<<"3 3 1"<<endl;
			cout<<"1 1 2"<<endl;
			cout<<"2 1 2"<<endl;
			cout<<"2 2 2"<<endl;
			cout<<"3 2 2"<<endl;
			cout<<"1 3 2"<<endl;
			cout<<"3 3 2"<<endl;
			cout<<"2 1 3"<<endl;
			cout<<"3 1 3"<<endl;
			cout<<"1 2 3"<<endl;
			cout<<"3 2 3"<<endl;
			cout<<"1 3 3"<<endl;
			cout<<"2 3 3"<<endl;
			continue;
		}
		if(k>=s)
		{
			cout<<"Case #"<<c<<": "<<u<<endl;
			for(int t1=1;t1<=j;++t1)
			{
				for(int t2=1;t2<=p;++t2)
				{
					for(int t3=1;t3<=s;++t3)
						cout<<t1<<" "<<t2<<" "<<t3<<endl;
				}
			}
			continue;
		}
		int l = (1<<u);
		int maximum = 0;
		for(int i=1;i<=l;++i)
		{
			int a = i;
			bool boolean = true;
			int cnt=0;
			for(int o = 0;(1<<o)<=a;++o)
				if((1<<o)&&a)
					cnt++;
			if(cnt<maximum)
				continue;
			vector<iii> ans1;
			for(int o=0;(1<<o)<=a;++o)
			{
				if((1<<o)&a)
				{
					int r = o;
					int t1 = r%p+1;
					int t2 = (r/p)%j + 1;
					int t3 = (r/(p*j))+1;
					p1[ii(t1,t2)]++;
					p2[ii(t2,t3)]++;
					p3[ii(t1,t3)]++;
					ans1.push_back(make_pair(t1,ii(t2,t3)));
					if(p1[ii(t1,t2)]>k || p2[ii(t2,t3)]>k || p3[ii(t1,t3)]>k)
					{
						boolean = false;
						break;
					}
				}
			}
			if(boolean && ans1.size()>maximum)
			{
				ans = ans1;
				maximum = ans1.size(); 
			}
			if(maximum == j*p*k)
				break;
			p1.clear();
			p2.clear();
			p3.clear();
		}
		cout<<"Case #"<<c<<": "<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i)
		{
			cout<<ans[i].X<<" "<<ans[i].Y.X<<" "<<ans[i].Y.Y<<endl;
		}
		p1.clear();
		p2.clear();
		p3.clear();
		ans.clear();
	}

	return 0;
}