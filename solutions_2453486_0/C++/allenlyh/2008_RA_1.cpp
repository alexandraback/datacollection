#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ofstream fout("a.out");
const int maxn=800+10;
int n;
long long a[maxn],b[maxn];
long long res=0;

bool cmp(long long a,long long b) {return a>b;}


void work()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int j=1;j<=n;j++) cin>>b[j];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	res=0;
	for (int i=1;i<=n;i++) res+=a[i]*b[i];
	fout<<res<<endl;
	return;
}


int main()
{
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		fout<<"Case #"<<i<<": ";
		work();
	}
	return 0;
}
