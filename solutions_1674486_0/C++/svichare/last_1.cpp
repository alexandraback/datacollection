
#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

using namespace std;

#define DEBUG 0
#define my_cout if (DEBUG) cout 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream ss;

void proc_1(string s)
{
	cout << fixed;
	cout << setprecision(12) ;

	cout << "result" << endl;
	return;
}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if(argc == 1)
		is.open("input.txt");
	else
		is.open(argv[1]);

	string s;
	getline(is,s); 
	istringstream iss(s);
	iss >> tc;
	vector<int> paths[1000];
	bool found;

	for(int i = 1; i <= tc; i++)
	{
		found = false;
		printf("Case #%d: ",i);
		getline(is,s);
		int nodes;
		istringstream iss2(s);
		iss2 >> nodes;
		my_cout <<  "Number of nodes : " << nodes;
		int cur = 1;
		for (cur = 1; cur <= nodes ; cur++) {
			paths[cur].clear();
			getline(is,s);
			istringstream iss3(s);
			int num_parents;
			iss3 >> num_parents;

			for (int k = 0 ; k < num_parents; ++k) {
				int cur_parent;
				iss3 >> cur_parent;
				paths[cur].push_back(cur_parent);
				my_cout << "inserting :" << cur_parent << " as parent of " << cur << endl;
			}
		}

		for (int k = 1 ; k <= nodes ; ++k) {
			bool additions = true;
			vector<int> cur_disc;
			for (int l = 0 ; l < paths[k].size(); l++) {
				cur_disc.push_back(paths[k][l]);
			}
			vector<int>::iterator it = cur_disc.begin();
			while (it != cur_disc.end()) {
				my_cout  << "Now traversing for : " << *it << endl;
				for(vector<int>::iterator parent_itr = paths[*it].begin() ; parent_itr != paths[*it].end(); ++parent_itr) {
					if ( find(cur_disc.begin(), cur_disc.end(), *parent_itr) != cur_disc.end() ) {
						found = true;
						my_cout << "Find duplicate : " << *parent_itr;
						goto bail;
						break;
					} else {
						int temp = *it;
						cur_disc.push_back(*parent_itr);
						it = find (cur_disc.begin(), cur_disc.end(), temp);
					}
				}
				++it;
			}
			if (found)
				break;
		}
bail:
		if (found == false) {
			cout << "No" << endl;
		} else {
			cout  << "Yes" << endl;
		}
	}
	is.close();
	return 0;
}