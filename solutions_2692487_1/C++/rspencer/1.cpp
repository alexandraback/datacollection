#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

#define FORI(_q) for(int i = 0; i<(_q);i++)
#define FORJ(_q) for(int j = 0; j<(_q);j++)
#define PUHEAP(_q) push_heap((_q).begin(),(_q).end())
#define POHEAP(_q) pop_heap((_q).begin(),(_q).end())
#define SORT(_q)sort((_q).begin(),(_q).end())
#define DEBUG cout<<"DEBUG"<<endl;

using namespace std;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))


int main()
{
	int T;
	cin>>T;
	for (int t= 0;t<T;t++)
	{
		
		int A,n;
		cin>>A>>n;
		int ans = n;
		vector<int> sizes (n);
		FORI(n)
			cin>>sizes[i];
		sort(sizes.begin(),sizes.end());
		if (A>1)
		{
			int toAdd = 0;
			FORI(n)
			{
				while (A <= sizes[i])
				{
					toAdd++;
					A+=A-1;
				}
				A+=sizes[i];
				ans = min(ans,toAdd+n-i-1);
			}
		}
		else
			ans = n;
		
		
		
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
}