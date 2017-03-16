#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(

int main(void){
	int T;
	vector<string> v;
	vector<int> inc;
	int n, nfact;
	string ts;
	inc.resize(256);

	ifstream fin("B-small-attempt3.in");
	ofstream fout("out.txt");

	fin >> T;

	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		cout << "Case #" << t+1 << ": ";

		fin >> n;
		v.resize(n);
		REP(i, n) v[i] = "";

		int sz;
		REP(i, n){
			fin >> ts;
			v[i].push_back(ts[0]);
			sz = 0;
			REP(w, ts.size()){
				if(ts[w] != v[i][sz]){
					sz++;
					v[i].push_back(ts[w]);
				}
			}
		}

		int valid;
		valid = 1;
		FOR(i, 'a', 'z') inc[i] = 0;
		REP(i, n){
			inc[v[i][0]] = 1;
			inc[v[i].back()] = 1;
			FOR(w, 1, v[i].size()-2){
				if(inc[v[i][w]]){
					valid = 0;
					break;
				} else {
					inc[v[i][w]] = 1;
				}
			}
		}
		if(!valid) {
			fout << "0" << endl;
			cout << "0" << endl;
			continue;
		}

		REP(i, n){
			if(v[i].size() < 2){
				v[i].push_back(v[i][0]);
			} else {
				v[i][1] = v[i].back();
			}
			v[i].resize(2);
		}

		int res;
		res = 0;

		sort(v.begin(), v.end());
		int fact, col;
		fact = 1;
		col = 2;
		vector<string>::iterator it, itn;
		itn = it = v.begin();
		it++;
		while(it != v.end()){
			if((*it) == (*itn)){
				fact *= col;
				col++;
				v.erase(it);
				it = itn;
			} else {
				col = 2;
			}

			itn = it;
			it++;
		}

		n = v.size();
		nfact = 1;
		FOR(w, 2, n) nfact*=w;

		REP(i, nfact){
			valid = 1;
			FOR(i, 'a', 'z') inc[i] = 0;
			inc[v[0][0]] = 1;
			inc[v[0][1]] = 1;
//cout << "| " << v[0][0] << v[0][1] << " ";
			FOR(w, 1, n-1){
//cout << v[w][0] << v[w][1] << " ";
				if(v[w][0] != v[w-1][1]){
					if(inc[v[w][0]]){
						valid = 0;
						break;
					}
					inc[v[w][0]] = 1;
				}
				if(v[w][1] != v[w][0]){
					if(inc[v[w][1]]){
						valid = 0;
						break;
					}
					inc[v[w][1]] = 1;
				}
			}
			if(valid) res++;
//cout << "|" << endl;
			std::next_permutation(v.begin(),v.end());
		}


		fout << res*fact << endl;
		cout << res*fact << endl;
	}

system("pause");

	fout.close();
	return 0;
}
