#include<iostream>
#include<vector>
using namespace std;

const long long verybig = 1000000007 ;

class car
{
	public:
	string s;
	char l,r;
	long long n;
	bool nice;
};

bool checks( string s )
{
	if (s.length()<=2) return true;
	int i;
	for (i=1;i<s.length();i++)
		if (s[i]!=s[0])
			break;
	for (int j=i+1;j<s.length();j++)
		if (s[j]!=s[i])
			return false;
	return true;
}

bool checks2( string s )
{
	for ( int i =0; i<s.length() ; i++)
	{
		bool flag = false;
		for (int j=i+1;j<s.length() ; j++ )
		{
			if (s[j]==s[i])
				if (flag)
					return false;
			if (s[j]!=s[i] )
				flag = true;
		}
	}
	return true;
}


long long f ( long long p )
{
	long long res = 1;
	for(long long i=0;i<p;i++)
		res = res * (i+1) % verybig;
	return res;
}


int n;
vector<car> c;

void work( int t )
{
	c.clear();
	string s;
	cin>>n;
	getline(cin,s);
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		car tmp;
		tmp.nice = checks(s);
		if (!checks2(s) )
		{
			cout<<"Case #"<<t<<": 0"<<endl;
			return;
		}
		tmp.s=s;
		tmp.l=s[0];
		tmp.r=s[s.length()-1];
		tmp.n=1;
		c.push_back( tmp );
	}


	for (char ch='a';ch<='z';ch++)
	{
		bool found = false;
		int l=-1,r=-1;
		long long mul = 1 , num = 0;
		string s="";
		for (long long i=0;i<c.size();i++)
		{
			if ( c[i].s.find(ch)!=string::npos )
			{
				found = true;
				num++;
				mul = mul * c[i].n % verybig;
				if ( c[i].l == ch && c[i].r!=ch )
				{
					if ( r>=0 )
					{
						cout<<"Case #"<<t<<": 0"<<endl;
						return;
					}
					r = i;
				}
				else if ( c[i].r == ch && c[i].l!= ch )
				{
					if ( l>=0 )
					{
						cout<<"Case #"<<t<<": 0"<<endl;
						return;
					}
					l = i;
				}
				else if ( !c[i].nice )
				{
					cout<<"Case #"<<t<<": 0"<<endl;
					return;
				}
				else
				{
					s+=c[i].s;
				}
			}
		}
		if (!found) continue;
		car tmp;
		if ( l==-1 && r==-1 )
		{
			tmp.l = ch;
			tmp.r = ch;
			tmp.s = s;
			tmp.n = f(num) * mul % verybig;
			tmp.nice = true;
		}
		else if ( l ==-1 && r>=0 )
		{
			tmp.l = ch;
			tmp.r = c[r].r;
			tmp.s = s + c[r].s;
			if (!checks2(tmp.s))
			{
				cout<<"Case #"<<t<<": 0"<<endl;
				return;
			}
			tmp.n = f(num-1) * mul % verybig;
		}
		else if ( l >=0 && r==-1 )
		{
			tmp.l = c[l].l;
			tmp.r = ch;
			tmp.s = c[l].s + s;
			if (!checks2(tmp.s))
			{
				cout<<"Case #"<<t<<": 0"<<endl;
				return;
			}
			tmp.n = f(num-1) * mul % verybig;
		}
		else if ( l >=0 && r>=0 )
		{
			tmp.l = c[l].l;
			tmp.r = c[r].r;
			tmp.s = c[l].s+s+c[r].s;
			if (!checks2(tmp.s))
			{
				cout<<"Case #"<<t<<": 0"<<endl;
				return;
			}
			tmp.n = f(num-2) * mul % verybig;
		}
		for (int i=0;i<c.size();i++)
			if ( c[i].s.find(ch)!=string::npos )
			{
				c.erase( c.begin()+i );
				i--;
			}
		c.push_back( tmp );
	}


	long long res=1;
	for (long long i=0;i<c.size();i++)
		res = res * c[i].n % verybig;
	res = res * f(c.size()) % verybig;


	cout<<"Case #"<<t<<": "<<res<<endl;

}

int main()
{
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	for (int i=1;i<=t;i++)
		work( i );
}

