#include<bits/stdc++.h>
using namespace std;
  
#define MOD 1000000007
#define MAX 1000000007
#define gc getchar()  
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a+1);
#define pri(a) printf("%d\n",a);
#define rep(a,b,c) for(a=b;a<c;a++) 
#define rrep(a,b,c) for(a=b;a>c;a--)  
#define vit vector<int > :: iterator
#define viit vector<ii > :: iterator
#define mp(a,b)  make_pair(a,b)
#define pb(a,b) a.push_back(b)
#define trv(it,v) for(it=v.begin();it!=v.end();it++)
#define F first
#define S second
#define all(v)	v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout);


vector<int > v;
int s[26];
int main()
{	
	read("input.in");
	write("output.out");
	int i,j,k,la,n,ta=0,t;
	cin>>t;
	string str;
	int a,b,c,d;
	while(t--)
	{	ta++;
		cin>>str;
		memset(s,0,sizeof(s));
		v.clear();
		for(i=0;i<str.size();i++)
		{
			s[str[i]-'A']++;
		}
		int ans=0;
		ans+=(s['Z'-'A']);
		s['E'-'A']-=(s['Z'-'A']);
		s['R'-'A']-=(s['Z'-'A']);
		s['O'-'A']-=(s['Z'-'A']);
		for(i=0;i<s['Z'-'A'];i++)	v.push_back(0);
		
		ans+=(s['W'-'A']);
		s['T'-'A']-=(s['W'-'A']);
		s['O'-'A']-=(s['W'-'A']);
		for(i=0;i<s['W'-'A'];i++)	v.push_back(2);
		
		ans+=(s['U'-'A']);
		s['F'-'A']-=(s['U'-'A']);
		s['O'-'A']-=(s['U'-'A']);
		s['R'-'A']-=(s['U'-'A']);
		for(i=0;i<s['U'-'A'];i++)	v.push_back(4);
		
		ans+=(s['F'-'A']);
		s['V'-'A']-=(s['F'-'A']);
		s['I'-'A']-=(s['F'-'A']);
		s['E'-'A']-=(s['F'-'A']);
		for(i=0;i<s['F'-'A'];i++)	v.push_back(5);
		
		ans+=(s['X'-'A']);
		s['S'-'A']-=(s['X'-'A']);
		s['I'-'A']-=(s['X'-'A']);
		for(i=0;i<s['X'-'A'];i++)	v.push_back(6);
		
		
		ans+=(s['V'-'A']);
		s['S'-'A']-=(s['V'-'A']);
		s['E'-'A']-=(s['V'-'A']);
		s['E'-'A']-=(s['V'-'A']);
		s['N'-'A']-=(s['V'-'A']);
		
		for(i=0;i<s['V'-'A'];i++)	v.push_back(7);
		
		
		ans+=(s['G'-'A']);
		s['E'-'A']-=(s['G'-'A']);
		s['I'-'A']-=(s['G'-'A']);
		s['H'-'A']-=(s['G'-'A']);
		s['T'-'A']-=(s['G'-'A']);
		
		for(i=0;i<s['G'-'A'];i++)	v.push_back(8);
		
		ans+=(s['O'-'A']);
		s['N'-'A']-=(s['O'-'A']);
		s['E'-'A']-=(s['O'-'A']);
		
		for(i=0;i<s['O'-'A'];i++)	v.push_back(1);
		
		ans+=(s['R'-'A']);
		s['T'-'A']-=(s['R'-'A']);
		s['H'-'A']-=(s['R'-'A']);
		s['E'-'A']-=(s['R'-'A']);
		s['E'-'A']-=(s['R'-'A']);
		
		for(i=0;i<s['R'-'A'];i++)	v.push_back(3);
		
		
		ans+=(s['I'-'A']);
		s['N'-'A']-=(s['I'-'A']);
		s['N'-'A']-=(s['I'-'A']);
		s['E'-'A']-=(s['I'-'A']);
		
		for(i=0;i<s['I'-'A'];i++)	v.push_back(9);
		
		
		
		sort(v.begin(),v.end());
		
		cout<<"Case #"<<ta<<": ";
		for(i=0;i<v.size();i++)
		cout<<v[i];
		cout<<endl;
		
		
	}

	return 0;
}
