#include <algorithm>
#include <fstream>

using namespace std;

const int maxn=100;

int t1,t2,n,x,y,i,j,k,now,rest;
double ans;
ifstream fin("b.in");
ofstream fout("b.out");

void search(int dep,int left,double p)
{
	if(dep==rest)
	{
		if (left>=y+1)
			ans=ans+p;
		return;
	}
	if (left<2*k)
	{
		search(dep+1,left+1,p*0.5);
		search(dep+1,left,p*0.5);
	}
	else
		search(dep+1,left,p);

}

int main()
{
	fin>>t1;
	for(t2=1;t2<=t1;t2++)
	{
		fin>>n>>x>>y;
		fout<<"Case #"<<t2<<": ";

		if(x<0)
			x=-x;
		k=0;
		now=0;
		while(now<n)
		{
			k++;
			now+=4*k-3;
		}
		if(now>n)
		{
			now-=4*k-3;
			k--;
		}
		ans=0.0;
		rest=n-now;

		if ((x+y)%2==1 || y<0)
			fout<<"0.0";
		else if ((rest>0 && x+y>2*k) || (rest==0 && x+y>2*(k-1)))
			fout<<"0.0";
		else if (x+y<=2*(k-1))
			fout<<"1.0";
		else
		{
			search(0,0,1.0);
			fout<<ans;
		}

		
		fout<<endl;
	}

	return 0;
}