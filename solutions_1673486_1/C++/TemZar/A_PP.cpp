#include <cstdlib>
#include <iostream>

using namespace std;

double P[100000];

int main(int argc, char *argv[])
{int T,A,B,i,j;
 double ans,d,t,x,y;
 freopen("A-large.in","r",stdin);
 freopen("A.out","w",stdout);
 cin>>T;
 for(i=1;i<=T;i++)
 {cin>>A>>B;
  for(y=1,j=0;j<A;j++)
    {cin>>x;
     y*=x;
     P[j]=y;
    }
  ans=B+2;
  t=A+B+1;
  if(t<ans)ans=t;
  for(j=0,t-=2,x=2*B+A;j<A;j++,t-=2,x-=2)
    {d=P[j]*t+(1-P[j])*x;
     if(d<ans)ans=d;
    }
  printf("Case #%d: %.6f\n",i,ans);
  
  }
    
    return EXIT_SUCCESS;
}
