#include <iostream>
using namespace std;

int min(int e,int r,int t,int a[10],int p,int emax)
{
	if(p>=t)
	return 0;
	
	int mi=0;
	for(int i=e;i>=0;i--)
	{
		if(e-i>=0){
	    int ei=(emax<e-i+r)?emax:e-i+r;
		int cur=min(ei,r,t,a,p+1,emax)+i*a[p];
		if(cur>mi)
		mi=cur;
	    }
	}
		
	return mi;
	
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int e,r,t,a[10];
		cin>>e>>r>>t;
		for(int j=0;j<t;j++)
		cin>>a[j];
		cout<<"Case #"<<i<<": "<<min(e,r,t,a,0,e)<<endl;
	}
}
