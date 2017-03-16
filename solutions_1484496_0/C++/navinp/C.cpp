#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int tc,no;
	scanf(" %d",&no);
	for(tc=1;tc<=no;tc++)
	{
	int n,i,x,j;
	scanf(" %d",&n);
	vector<int> v;
	for(i=0;i<n;i++) { scanf(" %d",&x); v.push_back(x); }
	sort(v.begin(),v.end());
	map<int,set<int> > M;
	printf("Case #%d:\n",tc);
	for(i=0;i<(1<<n);i++){
		int sum=0;
		for(j=0;j<n;j++)
		if(i&(1<<j)) sum+=v[j];
		M[sum].insert(i);
		if(M[sum].size() >=2 ) {
			set<int>::iterator it=M[sum].begin();
			int x=*it;
			it++;
			int y=*it;
			if(x!=y){
				for(j=0;j<n;j++)
				if(x&(1<<j))
					printf("%d%c",v[j],(j<n)?' ':0);
				printf("\n");
				for(j=0;j<n;j++)
				if(y&(1<<j))
					printf("%d%c",v[j],(j<n)?' ':0);
				printf("\n");
				break;
			}
			
		}
	}
	
	}
	return 0;
}
