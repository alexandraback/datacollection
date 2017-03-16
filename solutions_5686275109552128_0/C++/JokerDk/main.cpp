#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 11;
const int INF = 100000000;


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	int N;
	cin>>N;
	FILE * p; p = fopen ("result.txt","w"); 
	for( int i=0; i<N; ++i)
	{
		//solve one case
		int D;
		cin>>D;
		vector< int> arrs( D, 0);
		int minRet = INF;
		for( int j=0; j<D; ++j)
		{
			cin>>arrs[j];
		}
		
		for( int k=1; k<=MAX; ++k)
		{
			int slices = 0;
			for( int j=0; j<D; ++j)
			{
				if(arrs[j]%k==0)
				{
					slices += (arrs[j]/k)-1;
				}
				else
				{
					slices += arrs[j]/k;
				}
				
			}
			if( slices+k<minRet)
			{
			minRet = slices+k;
			}		
		}
		
		fprintf(p, "Case #%d: %d\n", i+1, minRet);

	}
}
