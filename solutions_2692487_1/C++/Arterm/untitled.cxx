#include <fstream>
#include <algorithm>

#define M 200

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

int n,a,s[M],d[M];

void read(void){
	cin>>a>>n;
	for (int i=0; i<n; ++i)
	cin>>s[i];
	sort(s,s+n);
}

void kill(void){
	if (a==1){
		cout<<n<<"\n";
		return ;
	}
	for (int i=0; i<n; ++i){
		if (i>0)
		d[i]=d[i-1];
		else
		d[i]=0;
		
		while (a<=s[i])
		a=2*a-1,d[i]++;
		a+=s[i];
	}
	int ans=n;
	for (int i=0; i<n; ++i)
	ans=min(ans,(d[i]+n-1-i));
	cout<<ans<<"\n";
}


int main()
{
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		read();
		cout<<"Case #"<<i<<": ";
		kill();
	}	
	return 0;
}

