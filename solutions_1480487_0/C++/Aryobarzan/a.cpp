//Im namen Gottes
#include <iostream>
#include <iomanip>
using namespace std;

void solve()
{
  int n;
  cin>>n;
  double p[n];
  double sum=0;
  for(int i=0;i<n;++i)
    {
      cin>>p[i];
      sum+=p[i];
    }
  for(int i=0;i<n;++i)
    {
      double up=1,down=0;
      while(up>=down+1e-9)
	{
	  double mid=(up+down)/2;
	  double thiso=p[i]+mid*sum;
	  double rem=sum-(mid*sum);
	  int badcnt=0;
	  for(int j=0;j<n;++j)
	    {
	      if(j==i)
		continue;
	      if(p[j]>thiso)
		badcnt++;
	      else
		rem-=(thiso-p[j]);
	    }
	  if(badcnt==n-1 or rem>0)
	    down=mid;
	  else
	    up=mid;
	}
      cout<<fixed<<setprecision(7)<<(up+down)/2*100;
      if(i!=n-1)
	cout<<" ";
    }
}

int main()
{
  int t;
  cin>>t;
  for(int i=1;i<=t;++i)
    {
      cout<<"Case #"<<i<<": ";
      solve();
      cout<<endl;
    }
  return 0;
}
