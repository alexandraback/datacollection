#include<bits/stdc++.h>
#define	    ll		    long long int
#define     D               double
#define     LD              long double
#define     max(a,b)	    ((a)>(b)?(a):(b))
#define     min(a,b)	    ((a)<(b)?(a):(b))
#define     mp              make_pair
#define     vi              vector<ll>
#define     pb              push_back
#define     s               second
#define     f               first
#define     mod             1000000007
using namespace std;
inline ll getn(){
	ll n=0, c=getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = getchar();
	return n;
}

int main()
{
	//	std::ios_base::sync_with_stdio(0);
	ll t,n,j,i;
	FILE *wfile;
	
	cin>>t;
//	string str,str1;
	wfile=fopen("output3.txt","w");
	ll ji;
	ji=0;
while(t--)
{
	string str,str1;
	cin>>str;
	cin>>str1;
	ji++;
	ll m,p;
	fprintf(wfile,"Case #%lld: ",ji);
	vector<ll> kl[1000];
	n=str.size();
	m=str1.size();
	if(n<4 && m< 4)
	{
		for(i=0;i<1000;i++)
		{
			j=i;
			p=3;
			while(p--)
			{
				kl[i].pb(j%10);
				j/=10;
			}
			
		}
		if(n==1)
		str="00"+str;
		else if(n==2)
		str="0"+str;
		
		if(m==1)
		str1="00"+str1;
		else if(n==2)
		str1="0"+str1;
	//	cout<<str<<" "<<str1<<endl;
		vector<ll> kl1,kl2;
		for(i=0;i<1000;i++)
		{
			for(j=0;j<3;j++)
			if(str[j]!='?' && (str[j]-'0')!=kl[i][2-j])
			break;
			
			if(j==3)
			kl1.pb(i);
			
			for(j=0;j<3;j++)
			if(str1[j]!='?' && (str1[j]-'0')!=kl[i][2-j])
			break;
			if(j==3)
			kl2.pb(i);
			
		}
	/*	for(i=0;i<kl1.size();i++)
		{
			cout<<kl1[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<kl2.size();i++)
		{
			cout<<kl2[i]<<" ";
		}
		cout<<endl;
		*/
		ll maxi=mod;
		ll ans1,ans2;
		for(i=0;i<kl1.size();i++)
		{
			for(j=0;j<kl2.size();j++)
			{
				if(abs(kl1[i]-kl2[j])<maxi)
				{
					ans1=kl1[i];
					ans2=kl2[j];
					maxi=abs(kl1[i]-kl2[j]);
				}
			}
		}
		p=n-1;
		while(n)
		{
			n--;
			fprintf(wfile,"%lld",kl[ans1][p]);
		//	cout<<kl[ans1][p];
			p--;
		}
	//	cout<<" ";
		fprintf(wfile," ");
		p=m-1;
		while(m)
		{
			m--;
			fprintf(wfile,"%lld",kl[ans2][p]);
		//	cout<<kl[ans2][p];
			p--;
		}
	//	cout<<endl;
			fprintf(wfile,"\n");
	//	cout<<ans1<<" "<<ans2<<endl;
		
		
	}
	
}
	
	return 0;
}
