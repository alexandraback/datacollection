#include<iostream>
#include<algorithm>
#define X first
#define Y second

using namespace std;

typedef long double ld;
typedef pair<ld,ld> pii;
pii P[3];
int n,ans;

bool cmp(pii A,pii B)
{
  if(A.X!=B.X)
    return A.X<B.X;
  return A.Y>B.Y;
}

int main()
{
  int qw;
  cin>>qw;
  for(int q=1;q<=qw;q++)
    {
      int ind;
      cin>>ind;
      n=0;
      for(int i=0;i<ind;i++)
	{
	  ld t1,aa,ab;
	  cin>>aa>>t1>>ab;
	  for(ld j=0;j<t1;j++)
	    P[n++]=pii(aa,(ab+j)/360.0);
	}
      sort(P,P+n,cmp);
      ans=1;
      if(n<2 || ((720.0-P[1].X)*P[1].Y>(360.0-P[0].X)*P[0].Y && (720.0-P[0].X)*P[0].Y>(360.0-P[1].X)*P[1].Y))
	ans=0;
      cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}
