#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

const double eps=1e-9;

int main()
{
  int t;
  cin>>t;
  for(int q=1;q<=t;q++)
  {
    cout<<"Case #"<<q<<": ";
    int n;
    cin>>n;
    vector<double> points(n);
    double totpoints=0;
    vector<double>y(n);
    for(int i=0;i<n;i++)
    {
      cin>>points[i];
      totpoints+=points[i];
    }
    for(int i=0;i<n;i++)
    {
      double lo=0.0,hi=1.0;
      y[i]=1.0;
      while(hi-lo>eps)
      {
	double m=(lo+hi)/2.0,tot=0;
	int temp=points[i]+totpoints*m;
	for(int j=0;j<n;j++)
	{
	  if(j!=i)
	    tot+=((temp+1e-5-points[j])/totpoints);
	}
	if(tot<=1.0-m || temp<0.0)
	{
	  lo=m;
	}
	else
	{
	  hi=m;
	  y[i]=m;
	}
	//cout<<i<<" "<<lo<<" "<<hi<<" "<<m<<" "<<tot<<"\n";
      }
      //cout<<"\n";
    }
    for(int i=0;i<n;i++)
      printf("%.6lf ",y[i]*100.0);
    cout<<"\n";
  }
  return 0;
}
