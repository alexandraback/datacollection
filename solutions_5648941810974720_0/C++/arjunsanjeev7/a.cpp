/*	 Hello World!	*/

#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define let(x,a) __typeof(a) x(a)
#define all(a) (a).begin(),(a).end() 
#define endl '\n'
#define present(c,x) ((c).find(x) != (c).end()) 
#define tr(v,it) for( let(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( let(it,v.rbegin()) ; it != v.rend() ; it++)
#define rep1(i,n) for(int i=0; i<(int)n;i++)
#define rep2(i,a,b) for(int i=(int)a; i<=(int)b; i++)

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define LL long long int
#define PII pair<int,int>
#define VI vector<int>
#define inf INT_MAX

using namespace std;

void FastIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();
	int t;
	string s;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>s;
		cout<<"Case #"<<z<<": ";
		VI cnt(256,0);
		multiset<int> S;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='X')
			{
				S.insert(6);
			}
			else if(s[i]=='Z')
			{
				S.insert(0);
			}
			else if(s[i]=='G')
			{
				S.insert(8);
			}
			else if(s[i]=='W')
			{
				S.insert(2);
			}
			cnt[s[i]]++;
		}
		tr(S,it)
		{
			if(*it==0)
			{
				cnt['Z']--;
				cnt['E']--;
				cnt['R']--;
				cnt['O']--;
			}
			else if(*it==2)
			{
				cnt['T']--;
				cnt['W']--;
				cnt['O']--;
			}
			else if(*it==6)
			{
				cnt['S']--;
				cnt['I']--;
				cnt['X']--;
			}
			else if(*it==8)
			{
				cnt['E']--;
				cnt['I']--;
				cnt['G']--;
				cnt['H']--;
				cnt['T']--;
			}
		}
		for(int i=0;i<cnt['H'];i++)
		{
			S.insert(3);
			cnt['T']--;
			cnt['R']--;
			cnt['E']--;
			cnt['E']--;
		}
		cnt['H']=0;
		for(int i=0;i<cnt['R'];i++)
		{
			S.insert(4);
			cnt['F']--;
			cnt['O']--;
			cnt['U']--;
		}
		cnt['R']=0;
		for(int i=0;i<cnt['F'];i++)
		{
			S.insert(5);
			cnt['I']--;
			cnt['V']--;
			cnt['E']--;
		}
		cnt['F']=0;
		for(int i=0;i<cnt['V'];i++)
		{
			S.insert(7);
			cnt['S']--;
			cnt['E']--;
			cnt['E']--;
			cnt['N']--;
		}
		cnt['V']=0;
		for(int i=0;i<cnt['O'];i++)
		{
			S.insert(1);
			cnt['N']--;
			cnt['E']--;
		}
		cnt['O']=0;
		for(int i=0;i<cnt['I'];i++)
		{
			S.insert(9);
		}
		tr(S,it)
		{
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}