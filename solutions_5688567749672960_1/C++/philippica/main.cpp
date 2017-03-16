#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#define maxn 500
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
//#define fin cin
//#define fout cout
int deg[100]={0,1,10,29,138,337,1436,3435,14434,34433,144432,344431,1444430,3444429,14444428};
int main()
{
	long long t,n,cas=0;
	fin>>t;
	while(t--)
	{
		long long ans=0;
		fin>>n;
		int flag=0;
		if(n<=20)
		{
			fout<<"Case #"<<++cas<<": "<<n<<endl;
		}
		else
		{
            if(n%10==0)
            {
                n--;
                flag=1;
            }
            long long temp=n;
			int a[100],h=0;
			while(n)
			{
				a[++h]=n%10;
				n/=10;
			}
			int u=h>>1;
			ans += deg[h];
			long long v=0;
			for(int i=h-u+1;i<=h;i++)
			{
				v = v * 10 + a[i];
			}
			ans  += v;
			v=0;
			for(int i=h-u;i>=1;i--)
			{
				v= v*10 +a[i];
			}
			ans+=v;
			v=1;
			for(int i=1;i<h;i++)v*=10;
			if(flag)ans++;
			fout<<"Case #"<<++cas<<": "<<min(ans,temp-v+deg[h])<<endl;
		}
	}
	return 0;
}
