/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int tab[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
class val
{
	public:
	bool f;
	int d;
	val()
	{
		f=false;d=0;
	}
	val(bool ff,int dd)
	{
		f=ff;d=dd;
	}
	val(char c)
	{
		f=false;
		if(c=='i')d=1;
		if(c=='j')d=2;
		if(c=='k')d=3;
	}
	void ass(bool ff,int dd)
	{
		f=ff;d=dd;
	}
	void ass(char c)
	{
		f=false;
		if(c=='i')d=1;
		if(c=='j')d=2;
		if(c=='k')d=3;
	}
	bool isi()
	{
		if((!f)&&(d==1))return true;
		return false;
	}
	bool isj()
	{
		if((!f)&&(d==2))return true;
		return false;
	}
	bool isk()
	{
		if((!f)&&(d==3))return true;
		return false;
	}
};
val mul(val a,val b)
{
	val an;
	an.f=(a.f^b.f);
	an.d=tab[a.d][b.d];
	if((a.d==1)&&((b.d==1)||(b.d==3)))an.f^=true;
	if((a.d==2)&&((b.d==1)||(b.d==2)))an.f^=true;
	if((a.d==3)&&((b.d==2)||(b.d==3)))an.f^=true;
	return an;
}
val pw(val a,ll p)
{
	val an;
	if(p==0)return an;
	if(a.d==0)
	{
		an=a;
		if(a.f&&(p%2==0))an.f=false;
		return an;
	}
	if(p%2==1)an.d=a.d;
	else an.d=0;

	if((p%4==2)||(p%4==3))an.f=true;
	else an.f=false;

	if(a.f&&(p%2==1))an.f^=true;
	return an;
}
val mul(val a,char c)
{
	val b(c);
	return mul(a,b);
}
val mul(char c,val s)
{
	val b(c);
	return mul(b,s);
}
int x;
string bs,s;
val bsv;
val M[1000000];
void ini(int node, int b, int e)
{
	if (b == e)
	M[node].ass(s[b]);
	else
	{

		//compute the values in the left and right subtrees
		ini(2 * node, b, (b + e) / 2);
		ini(2 * node + 1, (b + e) / 2 + 1, e);

		//search for the minimum value in the first and 
		//second half of the interval
		M[node]=mul(M[2*node],M[2*node+1]);
	}
}
val que(int node, int b, int e, int i, int j)
{
	val an,p1,p2;

	if (i > e || j < b)return an;
   
	if (b >= i && e <= j)return M[node];
   
	p1 = que(2 * node, b, (b + e) / 2, i, j);
	p2 = que(2 * node + 1, (b + e) / 2 + 1, e, i, j);

	an=mul(p1,p2);
	return an;
}
void ps()
{
	int i,j,k;
	s="";
	for(i=0;i<x;i++)s+=bs;
	ini(1,0,s.sz);
}
val fn(int l,int r)
{
	return que(1,0,s.sz,l,r);
}
vector<int> le,re;
int main()
{
	int t,i,j,k,cs,css;
	bool f;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>k>>x>>bs;
		ps();
		val l,r,m;
		le.clear();
		re.clear();
		f=false;
		for(i=0;i<s.sz;i++)
		{
			l=mul(l,s[i]);
			if(l.isi())le.PB(i);
		}
		for(i=s.sz-1;i>=0;i--)
		{
			r=mul(s[i],r);
			if(r.isk())re.PB(i);
		}
		for(i=0;i<le.sz;i++)
		{
			for(j=0;j<re.sz;j++)
			{
				if(re[j]-le[i]<=1)break;
				if(fn(le[i]+1,re[j]-1).isj())
				{
					f=true;break;
				}
			}
			if(f)break;
		}
		if(f)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
