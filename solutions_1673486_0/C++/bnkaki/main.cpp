#include <iostream> 
#include <queue> 
#include <vector> 
#include <string> 
#include <string.h> 
#include <algorithm> 
#include <cmath> 
#include <iomanip> 
#include <functional> 
#include <set> 
#include <map> 
#include <sstream> 

using namespace std; 

typedef long long ll; 
typedef pair<int,int> P; 


int T;
int a,b;
double prob[200000];

int main()
{
	cin>>T;
	for (int tt = 1; tt <= T; tt++)
	{
		cin>>a>>b;
		for (int i=0;i<a;i++) cin>>prob[i];

		double ans=min((double)(2+b),(double)(a+b+1));

		for (int i = 1; i <= a; i++)
		{
			double perfProb=1.0;
			for (int j=0;j<i;j++) perfProb*=prob[j];

			ans=min(ans,perfProb*(b-i+1)+(1.0-perfProb)*(b-i+1+b+1)+(a-i));
		}

		printf("Case #%d: %.6f\n",tt,ans);
	}

	return 0;
}