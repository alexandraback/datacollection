#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;


int main(){
	int tc, tcn;
	cin >> tcn;
	for(tc=0; tc<tcn; ++tc){
		int n;
		cin >> n;
		set<long long> s[n];
		vector<long long> nu(n);
		for(int i=0; i<n; ++i){
			cin >> nu[i];
			if(i){
				for(set<long long>::iterator iter = s[i-1].begin(); iter != s[i-1].end(); ++iter){
					s[i].insert(*iter + nu[i]);
					s[i].insert(*iter - nu[i]);
					s[i].insert(*iter);
				}
			}
			s[i].insert(nu[i]);
			s[i].insert(nu[i]);
		}

		printf("Case #%d:\n", tc+1);
		if(s[n-1].find(0) == s[n-1].end())
			puts("Impossible");
		else{
			vector<long long> a;
			vector<long long> b;
			long long mu = 0;
			for(int i=n; i-->1;){
				set<long long>::iterator iter;
				iter = s[i-1].find(mu - nu[i]);
				if(iter != s[i-1].end()){
					//cerr << "f " << i << " " << mu << " " << -nu[i] << endl;
					a.push_back(nu[i]);
					mu -= nu[i];
				}else{
					iter = s[i-1].find(mu + nu[i]);
					if(iter != s[i-1].end()){
						//cerr << "f " << i << " " << mu << " " << nu[i] << endl;
						b.push_back(nu[i]);
						mu += nu[i];
					}
					/*
					else{
						iter = s[i-1].find(mu);
						if(iter != s[i-1].end()){
							cerr << "f " << i << " " << mu << endl;
						}else{
							cerr << "nf " << i << " " << mu << endl;
						}
					}
					*/
				}
			}
			if(mu > 0){
				a.push_back(nu[0]);
				mu -= nu[0];
			}else if(mu < 0){
				b.push_back(nu[0]);
				mu += nu[0];
			}
			/*
			long long sa=0, sb=0;
			for(int i=0; i<a.size(); ++i)
				sa += a[i];
			for(int i=0; i<b.size(); ++i)
				sb += b[i];
			cerr << sa << " " << sb << " " << mu << endl;
			*/

			cout << a[0];
			for(int i=1; i<a.size(); ++i)
				cout << " " << a[i];
			cout << endl;
			cout << b[0];
			for(int i=1; i<b.size(); ++i)
				cout << " " << b[i];
			cout << endl;
		}
	}
}
