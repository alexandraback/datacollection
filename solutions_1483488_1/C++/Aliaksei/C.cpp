#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
using namespace std;
int p10[]={1, 10,100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int razm( int i) {
	int ret=0;
	while(i) {
		++ret;
		i/=10;
	}
return ret;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for (int cs=0; cs<t; ++cs)
	{
		int count=0;
		int a, b;
		cin>>a>>b;
		//set<int> us;
		int used[11];
		for (int i=a; i<=b; ++i) {
			//us.clear();
			for (int l=0; l<11; ++l) used[l]=-1;
			int t=razm(i), ind=0, cnt=0;
			int ii=i;
			for (int j=0; j<t-1; ++j) {
				bool flag=true;
				if (ii%10==0) flag=false;
				ii=(ii/10)+(ii%10)*p10[t-1];
				if (flag&&a<=ii&&b>=ii&&ii!=i) {
					for (int l=0; l<ind; ++l)
						if (ii==used[l])
							goto ptt;
					used[ind]=ii;
					++ind;
					++cnt;
				//us.insert(ii);
				//cout<<i<<" "<<ii<<endl;
				}
			}
ptt:			count+=cnt;
			//count+=us.size();
		}
		cout<<"Case #"<<cs+1<<": "<<count/2<<endl;

	}



}