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

pair<string,string> pp[1005];

pair<string,string> pp1[1005];

int main()
{	
	read("input.in");
	write("output.out");
	int i,j,k,la,n,ta=0,t;
	
	map<string,int> mp1,mp2; 
	string aa[2][1005];
	cin>>t;
	string str1,str2;
	int a,b,c,d,e,f;
	while(t--)
	{	ta++;
		cin>>n;
		mp1.clear();mp2.clear();
		for(i=0;i<n;i++)
		{
			cin>>str1>>str2;
			pp[i].S=str1;pp[i].F=str2;
			pp1[i].F=str1;pp1[i].S=str2;
			mp1[str1]++;mp2[str2]++;
		}
		string pre="";int len1=0,len2=0;
		
		sort(pp,pp+n);
		sort(pp1,pp1+n);
		int ans=0,ans1=0;
		for(i=0;i<n;i++)
		{
			if(pre!=pp[i].F)
			{
				if(len1==0||len2!=len1)
				ans+=len2;
				else
				ans+=len2-1;
				//cout<<pp[i].F<<" "<<len2<<" ";
				len1=0;len2=0;
			
			}
			
			if(mp1[pp[i].S]>1)
				len2++;
			len1++;
			pre=pp[i].F;
		}
				if(len1==0||len2!=len1)
				ans+=len2;
				else
				ans+=len2-1;
				len1=0;len2=0;
		
		pre="";len1=0;len2=0;
		
		for(i=0;i<n;i++)
		{
			if(pre!=pp1[i].F)
			{
				if(len1==0||len2!=len1)
				ans1+=len2;
				else
				ans1+=len2-1;
				//cout<<pp1[i].F<<" "<<len2<<" ";
				len1=0;len2=0;
			
			}
			
			if(mp2[pp1[i].S]>1)
				len2++;
			len1++;
			pre=pp1[i].F;
		}
				if(len1==0||len2!=len1)
				ans1+=len2;
				else
				ans1+=len2-1;
				len1=0;len2=0;
		
		
		cout<<"Case #"<<ta<<": "<<max(ans,ans1)<<endl;
	}

	return 0;
}
