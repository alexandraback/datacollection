
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;







int main()
{

	


	freopen("B-small-attempt8.in","r", stdin);
	freopen("b.out","w", stdout);

	int T,S,p,N;
	int i,j,k,l;
	cin>>T;

	int a[102];

	for (i=1;i<=T;i++)
	{
		cin>>N;
		cin>>S;
		cin>>p;
		
		int total = 0;
	
		for(j=0;j<N;j++)
			cin>>a[j];

		if (p==0)
			total = N;
		else if (p==1)
		{
			for(j=0;j<N;j++)
				if (a[j]>=1) total++;
		}

		else  // p>=2
		{
			for (j=0;j<N;j++)
			{
				if (a[j]>= (3*p -2))
					total++;
				else
					if (a[j]>=(3*p -4) && S>0)
					{total++; S--;}
			}

		}


	cout<<"Case #"<<i<<": " <<total<<endl;

	

	}





	fclose(stdin);
	fclose(stdout);
	
	
	


}
