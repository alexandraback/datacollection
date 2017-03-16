#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>


using namespace std;

int main()
{
	int t, n, m, i, j, k, x, p, q;
	cin>>t;
	for(int i=1;i<=t;i++ ) {
		vector<int> v(1,0);
		vector< vector<int> > vov(1,v);
		v.clear();
		cin>>n;
		for(int j=0;j<n;j++ ) {
			cin>>m;
			while( m > 0 ) {
				cin>>x;
				v.push_back(x);
				m--;
			}
			if( v.size() == 0 ) v.push_back(-1);
			vov.push_back( v );
			v.clear();
		}
		p = 0;
		for(int j=1;j<=n;j++ ) {
			if( vov[j][0] != -1 ) {
				//puts("***");
				int a[2000] = {0};
				vector<int> tmp;
				tmp = vov[j];
				for(int k=0;k<tmp.size();k++ ) a[tmp[k]] = 1;
				while( tmp.size() > 0 ) {
					x = tmp[0];
					tmp.erase( tmp.begin() );
					if( vov[x][0] > 0 ) {
						for(int  k=0;k<vov[x].size();k++ ) {
							q = vov[x][k];
							if( a[q] == 1 ) {
								p = 1;
								break;
							}
							a[q] = 1;
							tmp.push_back( q );
						}
					}
				}
				if( p == 1 ) break;
			}
		}
		string ans="No";
		if( p == 1 ) ans="Yes";
		cout<<"Case #"<<i<<": "<<ans<<endl;
		
	}
	return 0;
}
