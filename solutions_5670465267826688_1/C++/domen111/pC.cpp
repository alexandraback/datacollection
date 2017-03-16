#include<bits/stdc++.h>
#define int long long
using namespace std;
struct num{
	int v;
	num(){}
	num(int v):v(v){}
};
int mp[5][5]={{},{0, 1,2,3,4} ,
				  {0, 2,-1,4,-3},
				  {0, 3,-4,-1,2},
				  {0, 4,3,-2,-1}};
int c2i(char c)
{
	switch(c)
	{
		case '1':return 1;
		case 'i':return 2;
		case 'j':return 3;
		case 'k':return 4;
	}
	throw;
}
num operator*(num a,num b)
{
	bool neg=(a.v<0)^(b.v<0);
	int v=mp[abs(a.v)][abs(b.v)];
	neg^=(v<0);
	v=abs(v);
	if(neg)v=-v;
	return {v};
}
struct repstr{
	string s;
	int rep;
	int size()const
	{return s.size()*rep;}
	char operator[](int i)
	{return s[i%s.size()];}
};
signed main()
{
	int T;
	scanf("%lld",&T);
	int no=1;
	while(no<=T)
	{
		int l,x;
		cin>>l>>x;
		repstr s;
		cin>>s.s;
		s.rep=x;
		num t=1;
		num goal=2;
		int i;
		bool ok=0;
		int j=-1;
		for(i=0;i<s.size();i++)
		{
			t=t*c2i(s[i]);
			if(t.v==goal.v)
				goal.v++, t=1, j=i;
			else if((i-j)==l*4)
				{ok=0; break;}
			if(goal.v==5){ok=1; break;}
		}
		if(ok)
		{
			t=1;
//			clog<<(4*l)<<endl;
			for(i++;(s.size()-i)%(4*l)!=0;i++)
			{
//				clog<<i<<endl;
				t=t*c2i(s[i]);
			}
			if(t.v!=1)
				ok=0;
		}
		if(ok)
			printf("Case #%d: YES\n",no++);
		else
			printf("Case #%d: NO\n",no++);
	}
}
