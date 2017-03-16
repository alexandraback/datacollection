#include <fstream>

#define M 2013

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

int s[M],n,r,t,f;
double d[M][M];

void pre(void){
	s[0]=1;
	for (int i=1; i<M; ++i)
	s[i]=4*i+1;
}

void read(void){
	cin>>n;
	int x,y;
	cin>>x>>y;
	if (x<0)
	x=-x;
	r=(x+y)/2;
	t=y;
}

void kill(void){
	f=0;
	while (n>=s[f])
	n-=s[f],f++;
	
	if (r<f){
		cout<<1.0<<"\n";
		return ;
	}
	if (r>=f+1){
		cout<<0.0<<"\n";
		return;
	}
	
	f*=2;
	t++;
	
	for (int i=0; i<=f; ++i)
	for (int j=0; j<=f; ++j)
	if (i==0 && j==0)
	d[i][j]=1;
	else{
		double s=0;
		if (i>0)
		s=s+d[i-1][j]*(j==f ? 1:0.5);
		if (j>0)
		s=s+d[i][j-1]*(i==f ? 1:0.5);
		d[i][j]=s;
	}
	
	double ans=0;
		
	for (int i=t; i<=n && i<=f; ++i)
	if (n-i<=f)
	ans+=d[i][n-i];
	cout<<ans<<"\n";
	
}

int main()
{
	pre();
	cout.precision(10);
	cout<<fixed;
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		read();
		cout<<"Case #"<<i<<": ";
		kill();
	}
	return 0;
}

