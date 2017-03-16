#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define E 0.000000001

int main()
{
  int t1;
  scanf("%d ",&t1);
  for(int i1=1; i1<=t1; i1++)
  {
    int n;
    scanf("%d ",&n);
    vector<int> S;
    int suma=0;
    for(int i=0; i<n; i++)
    {
      int x;
      scanf("%d ",&x);
      suma+=x;
      S.push_back(x);
    }
    vector<double> Vys; Vys.resize(n);
    for(int i=0; i<n; i++)
    {
      double zac=0.0,kon=1.0;
      while(kon-zac>E)
      {
	double stred=(zac+kon)/2.0;
	double score=S[i]+suma*stred;
	double celkovo=stred;
	for(int j=0; j<n; j++)
	{
	  if(i!=j)
	  {
	    if(S[j]-score<E) celkovo+=((score-S[j])/(double)suma);
	  }
	}
	//printf("%f %f %f\n",score,stred,celkovo);
	if(celkovo-1.0>E) kon=stred;
	else zac=stred;
      }
      Vys[i]=kon;
    }
    printf("Case #%d:",i1);
    for(int i=0; i<n; i++) printf(" %0.6f",Vys[i]*100);
    printf("\n");
  }
return 0;
}