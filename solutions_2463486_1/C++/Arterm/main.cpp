#include <fstream>
#include <vector>

#define M 200
#define long long long

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

int a[M];
vector<long> t;

bool pal(long x){
	int n=0;
	while (x){
		a[n++]=x%10;
		x/=10;
	}
	for (int l=n-1,r=0; l>r; l--,r++)
	if (a[l]!=a[r])
	return 0;
	return 1;
}

void pre(void){
	for (long i=0; i<=10000000; ++i)
	if (pal(i) && pal(i*i))
	t.push_back(i*i);
	//cout<<t[t.size()-1]<<"\n";
	//cout<<i<<" -> "<<i*i<<"\n";
}

long ans(long r){
	long i=0;
	while (i<t.size() && t[i]<=r)
	++i;
	return i;
}

void kill(void){
	long a,b;
	cin>>a>>b;
	cout<<ans(b)-ans(a-1)<<"\n";
	
}

int main()
{
	pre();
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		cout<<"Case #"<<i<<": ";
		kill();
	}
	return 0;
}

