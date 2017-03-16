#include<iostream>
#include<algorithm>
using namespace std;
string in1,in2;
long long aabs(long long a)
{
	if(a<0LL)return -a;
	return a;
}
bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
	long long d1=aabs(a.first-a.second);
	long long d2=aabs(b.first-b.second);
	if(d1!=d2)return d1<d2;
	if(a.first!=b.first)return a.first<b.first;
	return a.second<b.second;
}
pair<long long,long long> go(long long a,long long b,int pos)
{
	if(pos<0)return {a,b};
	long long A=a*10LL+in1[pos]-'0',B=b*10LL+in2[pos]-'0';
	if(in2[pos]!='?' and in1[pos]!='?')
		return go(A,B,pos-1);
	if(a<b)
	{
		if(in1[pos]=='?' and in2[pos]=='?')
		{
			A=a*10LL+9;
			B=b*10LL;
		}
		else if(in1[pos]=='?')
		{
			A=a*10LL+9;
		}
		else
		{
			B=b*10LL;
		}
		return go(A,B,pos-1);
	}
	else if(a>b)
	{
		if(in1[pos]=='?' and in2[pos]=='?')
		{
			A=a*10LL;
			B=b*10LL+9;
		}
		else if(in1[pos]=='?')
		{
			A=a*10LL;
		}
		else
		{
			B=b*10LL+9;
		}
		return go(A,B,pos-1);
	}
	else
	{
		vector<pair<long long,long long> >V;
		if(in1[pos]=='?' and in2[pos]=='?')
		{
			V.push_back(go(a*10,b*10,pos-1));
			V.push_back(go(a*10+1,b*10,pos-1));
			V.push_back(go(a*10,b*10+1,pos-1));
		}
		else if(in1[pos]=='?')
		{
			int val=in2[pos]-'0';
			if(val>0)
				V.push_back(go(a*10+val-1,b*10+val,pos-1));
			V.push_back(go(a*10+val,b*10+val,pos-1));
			if(val<9)
			V.push_back(go(a*10+val+1,b*10+val,pos-1));
		}
		else
		{
			int val=in1[pos]-'0';
			if(val>0)
				V.push_back(go(a*10+val,b*10+val-1,pos-1));
			V.push_back(go(a*10+val,b*10+val,pos-1));
			if(val<9)
			V.push_back(go(a*10+val,b*10+val+1,pos-1));
		}
		sort(V.begin(),V.end(),cmp);
		return V[0];
	}
}
pair<string,string> test()
{
	cin >> in1>>in2;
	reverse(in1.begin(),in1.end());
	reverse(in2.begin(),in2.end());
	auto p=go(0LL,0LL,in1.size()-1);
	for(size_t i=0;i<in1.size();i++)
	{
		if(in1[i]=='?')in1[i]=p.first%10+'0';
		if(in2[i]=='?')in2[i]=p.second%10+'0';
		p.first/=10;
		p.second/=10;
	}
	reverse(in1.begin(),in1.end());
	reverse(in2.begin(),in2.end());
	return {in1,in2};
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int T=1;T<=t;T++)
	{
		auto p=test();
		cout << "Case #"<<T<<": "<<p.first << " " << p.second << "\n";
	}
}
