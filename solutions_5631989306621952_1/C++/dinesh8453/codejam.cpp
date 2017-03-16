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
	wfile=fopen("output1.txt","w");
	j=0;
while(t--)
{
	string str,str1;
	cin>>str;
		char arr[5000];
	str1+=str[0];
	j++;
	fprintf(wfile,"Case #%lld: ",j);
	n=str.size();
//	cout<<"1"<<endl;
//	cout<<str1<<endl;
	for(i=1;i<n;i++)
	{
		if(str1[0]<=str[i])
		str1=str[i]+str1;
		else
		str1=str1+str[i];
	//	cout<<str1<<endl;
	}
///	cout<<endl;
	for(i=0;i<n;i++)
	{
		arr[i]=str1[i];
	}
	arr[i]='\0';
	fprintf(wfile,"%s\n",arr);

	
}
	
	return 0;
}
