
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("A.in", "r", stdin);
	freopen("Aout.txt", "w", stdout);

	vector<int> p[1001];
	int t, tcase;
	cin>>t;
	for (tcase=1; tcase<=t; tcase++){
		int n, m;
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>m;
			p[i].clear();
			while(m--){
				int tem;
				cin>>tem;
				p[i].push_back(tem);
			}
		}

		// start
		bool hasD = false;
		vector<int> or[10001];
		vector<int> temp1[10001];
		vector<int> temp2[10001];
		for(int i = 1; i <= n; i++){	
				or[i] = p[i];
				temp1[i] = p[i];
		}

		for(int round = 0; round < n; round++){
			
			for(int i = 1; i <= n; i++){	
				for(int j = 0; j < temp1[i].size(); j++){
					int v = temp1[i][j];
					for(int k = 0; k < or[v].size(); k++){
						vector<int>::iterator itr = find(p[i].begin(), p[i].end(), or[v][k]);
						if(itr != p[i].end()){
							hasD = true;
							goto here;
						}
						p[i].push_back(or[v][k]);
						temp2[i].push_back(or[v][k]);
					}
				} 
			}
			
			for(int i = 1; i <= n; i++){	
				temp1[i] = temp2[i];
				temp2[i].clear();
			}
		}

here:
		cout<<"Case #"<<tcase<<": ";
		if(hasD) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}