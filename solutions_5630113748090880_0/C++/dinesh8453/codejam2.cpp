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
	ll t,n,j,i,p,k,l;
	FILE *wfile;
	
	cin>>t;
//	string str,str1;
	wfile=fopen("output2.txt","w");
	j=0;
while(t--)
{
	//string str,str1;
	cin>>n;
		ll arr[3000]={0};
	
	j++;
	fprintf(wfile,"Case #%lld: ",j);
	
//	cout<<"1"<<endl;
//	cout<<str1<<endl;
	for(i=1;i<2*n;i++)
	{
		for(k=0;k<n;k++)
		{
			cin>>l;
			arr[l]++;
		}
	}
	for(i=0;i<3000;i++)
	{
		
	if(arr[i]%2==1)
	fprintf(wfile,"%lld ",i);
	}
	fprintf(wfile,"\n");
}
	
	return 0;
}
