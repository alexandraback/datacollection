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
	wfile=fopen("output2.txt","w");
	j=0;
	ll arr[15];
	ll fre[26];
while(t--)
{
	string str,str1;
	cin>>str;
	
	j++;
	fprintf(wfile,"Case #%lld: ",j);
	n=str.size();
	memset(fre,0,sizeof(fre));
	memset(arr,0,sizeof(arr));
	for(i=0;i<n;i++)
	{
		fre[str[i]-'A']++;
	}
	if(fre['Z'-'A'])
	{
		arr[0]=fre['Z'-'A'];
		fre['E'-'A']-=fre['Z'-'A'];
		fre['R'-'A']-=fre['Z'-'A'];
		fre['O'-'A']-=fre['Z'-'A'];
		fre['Z'-'A']=0;
	}
	if(fre['W'-'A'])
	{
		arr[2]=fre['W'-'A'];
		fre['T'-'A']-=fre['W'-'A'];
		fre['O'-'A']-=fre['W'-'A'];
		fre['W'-'A']=0;
	}
	if(fre['G'-'A'])
	{
		arr[8]=fre['G'-'A'];
		fre['E'-'A']-=fre['G'-'A'];
		fre['I'-'A']-=fre['G'-'A'];
		fre['H'-'A']-=fre['G'-'A'];
		fre['T'-'A']-=fre['G'-'A'];
		fre['G'-'A']=0;
	}
	if(fre['U'-'A'])
	{
		arr[4]=fre['U'-'A'];
		fre['F'-'A']-=fre['U'-'A'];
		fre['O'-'A']-=fre['U'-'A'];
		fre['R'-'A']-=fre['U'-'A'];
		fre['U'-'A']=0;
	}
	if(fre['X'-'A'])
	{
		arr[6]=fre['X'-'A'];
		fre['S'-'A']-=fre['X'-'A'];
		fre['I'-'A']-=fre['X'-'A'];
		fre['X'-'A']=0;
	}
	if(fre['R'-'A'])
	{
		arr[3]=fre['R'-'A'];
		fre['T'-'A']-=fre['R'-'A'];
		fre['H'-'A']-=fre['R'-'A'];
		fre['E'-'A']-=fre['R'-'A'];
		fre['E'-'A']-=fre['R'-'A'];
		fre['R'-'A']=0;
	}
	if(fre['F'-'A'])
	{
		arr[5]=fre['F'-'A'];
		fre['I'-'A']-=fre['F'-'A'];
		fre['V'-'A']-=fre['F'-'A'];
		fre['E'-'A']-=fre['F'-'A'];
		fre['F'-'A']=0;
		
	}
	if(fre['V'-'A'])
	{
		arr[7]=fre['V'-'A'];
		fre['S'-'A']-=fre['V'-'A'];
		fre['E'-'A']-=fre['V'-'A'];
		fre['E'-'A']-=fre['V'-'A'];
		fre['N'-'A']-=fre['V'-'A'];
		fre['V'-'A']=0;
	}
	
	if(fre['I'-'A'])
	{
		arr[9]=fre['I'-'A'];
		fre['N'-'A']-=	fre['I'-'A'];
		fre['N'-'A']-=fre['I'-'A'];
		fre['E'-'A']-=fre['I'-'A'];
		fre['I'-'A']=0;
		
	}
	if(fre['O'-'A'])
	{
		arr[1]=fre['O'-'A'];
		fre['N'-'A']-=fre['O'-'A'];
		fre['E'-'A']-=fre['O'-'A'];
		fre['O'-'A']=0;
	}
	for(i=0;i<10;i++)
	if(arr[i])
	while(arr[i]--)
	fprintf(wfile,"%lld",i);

	fprintf(wfile,"\n");
}
	
	return 0;
}
