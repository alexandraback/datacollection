#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
int w;
string dict[600000];
string s;
int n;
int dp[5000][6];

int main() {
	int t;
	int i, j, k, l, r;

	ifstream f("dict.txt");
	do {
		f>>dict[w];
		w++;
	} while(!f.eof());
	w--;

	//for(i=0; i<w; i++) cout<<dict[i]<<endl;

    cin>>T;
    for(t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": ";
		
		cerr<<t+1<<endl;

		cin>>s;
		n = s.size();

		for(i=0; i<=n; i++) for(j=0; j<6; j++) dp[i][j]=1000000;
		dp[0][5]=0;

		for(i=0; i<n; i++) {
			cerr<<"i: "<<i<<endl;			

			for(j=0; j<w; j++) {
				if(n<i+dict[j].size()) continue;
				int firstChange=-5, lastChange=-5, ok=1, numChange=0;				
				for(k=0; k<dict[j].size(); k++) {
					if(dict[j].at(k) != s.at(i+k)) {
						if(k-lastChange<5) {ok=0; break;}
						lastChange = k;
						numChange++;
						if(firstChange < 0) firstChange = lastChange;
					}
				}

				//if(dict[j]=="code" && i==0) cout<<"\t"<<firstChange<< " "<<lastChange<<" "<<ok<<" "<<numChange<<endl;

				if(ok) {
					int st = 4-firstChange;
					int end = dict[j].size()-(lastChange+1);
					if(st<0 || firstChange < 0) st=0;
					if(end>5 || lastChange < 0) end=5;

					cerr<<"\t"<<dict[j]<<" "<<st<<" "<<end<<endl;

					//if(dict[j]=="code" && i==0) cout<<"\t"<<st<<" "<<end<<endl;

					for(k=st; k<6; k++) dp[i+dict[j].size()][min(end, (int)dict[j].size()+k)] = min(dp[i+dict[j].size()][min(end, (int)dict[j].size()+k)], dp[i][k]+numChange);
				}
			}
		}

		//cout<<endl;
		//for(i=0; i<=n; i++) { for(j=0; j<6; j++) cout<<dp[i][j]<<" "; cout<<endl; }

		int res = 1000000;
		for(i=0; i<6; i++) res = min(res, dp[n][i]);
		cout<<res<<endl;
				
	}


	return 0;
}
