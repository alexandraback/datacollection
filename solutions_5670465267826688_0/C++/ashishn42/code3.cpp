#include <bits/stdc++.h>
using namespace std;

pair<int,char> f(pair<int,char> a,pair<int,char> b)
{
	if(a.second=='i'&&b.second=='j')
		return make_pair(a.first*b.first,'k');
	if(a.second=='j'&&b.second=='k')
		return make_pair(a.first*b.first,'i');
	if(a.second=='k'&&b.second=='i')
		return make_pair(a.first*b.first,'j');
	if(a.second=='j'&&b.second=='i')
		return make_pair(a.first*b.first*-1,'k');
	if(a.second=='i'&&b.second=='k')
		return make_pair(a.first*b.first*-1,'j');
	if(a.second=='k'&&b.second=='j')
		return make_pair(a.first*b.first*-1,'i');
	if(a.second=='1')
		return make_pair(a.first*b.first,b.second);
	if(b.second=='1')
		return make_pair(a.first*b.first,a.second);
	if(a.second==b.second)
		return make_pair(a.first*b.first*-1,'1');
}

pair<int,char> powD(pair<int,char> a,long long b)
{
	if(b==0)
		return make_pair(1,'1');
	if(b%2==1)
		return f(a,powD(a,b-1));
	pair<int,char> p=powD(a,b/2);
	return f(p,p);
}

pair<int,int> finder1(vector <pair<int,char> > &w)
{
	for(int i=w.size()-1;i>=0;i--)
	{
		if(w[i].first==1&&w[i].second=='k')
			return make_pair(0,w.size()-i);
	}
	pair<int,char> a=w[0],b;
	vector <pair<int,char> > v;
	v.push_back(a);
	bool done;
	for(int i=1;i<10;i++)
	{
		done=false;
		b=f(a,v[i-1]);
		for(int j=0;j<i;j++)
		{
			if(b.first==v[i].first&&b.second==v[i].second)
			{
				done=true;
			}
		}
		if(!done)
			v.push_back(b);
		else
			break;
	}
	for(int i=w.size()-1;i>=0;i--)
	{
		for(int j=0;j<v.size();j++)
		{
			a=f(w[i],v[j]);
			if(a.first==1&&a.second=='k')
			{
				return make_pair(j+1,w.size()-i);
			}
		}
	}
	return make_pair(-1,-1);
}

pair<int,int> finder2(vector <pair<int,char> > &w)
{
	for(int i=0;i<w.size();i++)
	{
		if(w[i].first==1&&w[i].second=='i')
			return make_pair(0,i+1);
	}
	pair<int,char> a=w[w.size()-1],b;
	vector <pair<int,char> > v;
	v.push_back(a);
	bool done;
	for(int i=1;i<10;i++)
	{
		done=false;
		b=f(v[i-1],a);
		for(int j=0;j<i;j++)
		{
			if(b.first==v[i].first&&b.second==v[i].second)
			{
				done=true;
			}
		}
		if(!done)
			v.push_back(b);
		else
			break;
	}
	for(int i=w.size()-1;i>=0;i--)
	{
		for(int j=0;j<v.size();j++)
		{
			a=f(v[j],w[i]);
			if(a.first==1&&a.second=='i')
			{
				return make_pair(j+1,i+1);
			}
		}
	}
	return make_pair(-1,-1);
}

int main() 
{
	freopen("i.txt","r",stdin);
	int t,u=1;
	cin>>t;
	long long l,x;
	string s;
	while(t--)
	{
		cin>>l>>x>>s;
		if(l*x<3)
		{
			cout<<"Case #"<<u++<<": NO\n";
		}
		else
		{
			vector <pair<int,char> > v(l),w(l);
			v[0]=make_pair(1,s[0]);
			w[l-1]=make_pair(1,s[l-1]);
			for(int i=1;i<s.length();i++)
			{
				v[i]=f(v[i-1],make_pair(1,s[i]));
				w[l-1-i]=f(make_pair(1,s[l-i-1]),w[l-i]);
			}
			//cout<<w[0].first<<" "<<w[0].second<<" "<<x<<endl;
			pair<int,char> ko=powD(w[0],x);
			if(!((ko.first==-1)&&(ko.second=='1')))
				cout<<"Case #"<<u++<<": NO\n";
			else
			{
				pair<int,int> cur=finder1(w),cur2;
				if(cur.first==-1)
					cout<<"Case #"<<u++<<": NO\n";
				else
				{
					//cout<<cur.first<<" "<<cur.second<<endl;
					cur2=finder2(v);
					if(cur2.first==-1)
						cout<<"Case #"<<u++<<": NO\n";
					else
					{
						if((cur.first+cur2.first)*l+cur.second+cur2.second<l*x)
						{
							cout<<"Case #"<<u++<<": YES\n";
						}
						else
						{
							cout<<"Case #"<<u++<<": NO\n";
						}
					}
				}
			}
		}
	}
	return 0;
}