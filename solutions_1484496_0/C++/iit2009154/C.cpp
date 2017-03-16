#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long int pwr(int a)
{
	int res=1;
	for (int i=0; i<a; i++) {
		res *= 2;
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) {
		int n;
		cin >> n;
		vector<int> v;
		vector<vector<int> > sets;
		for (int j=0; j<n; j++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		long long int limit = pwr(n);
		for (long long int j=0; j<limit; j++) {
			int index = 0;
			int sum=0;
			vector<int> temp;
			long long int t = j;
			while (t) {
				if (t%2) {
					temp.push_back(v[index]);
					sum += v[index];
				}
				t = t/2;
				index++;
			}
			temp.push_back(sum);
			sets.push_back(temp);
		}
		printf("Case #%d:\n",i);
		bool cont = true;
		for (int j=0; j<limit && cont; j++) {
			for (int k=j+1; k<limit && cont; k++) {
				if (sets[j][sets[j].size()-1] == sets[k][sets[k].size()-1]) {
					for (int l=0; l<(sets[j].size()-1); l++) {
						cout << sets[j][l] << " ";
					}
					cout << endl;
					for (int l=0; l<(sets[k].size()-1); l++) {
						cout << sets[k][l] << " ";
					}
					cout << endl;
					cont = false;
				}
			}
		}
		if (cont) {
			cout << "Impossible\n";
		}
	}
	return 0;
}
