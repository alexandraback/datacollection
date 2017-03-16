//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


#define NUM_TYPE	 int
struct Num{NUM_TYPE nVal;string sVal;Num(string str){sVal = str;istringstream stream(sVal);stream >> nVal;}Num(NUM_TYPE n){nVal = n;ostringstream stream(sVal);stream << fixed << n;sVal = stream.str();}};


int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	//freopen("C-small-attempt0.in", "rt", stdin);
	//freopen("C-small-attempt0.out", "wt", stdout);
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);

	int tt; cin >> tt;
	for(int t = 0 ; t < tt ; t++){
		cerr << "Solving testcase " << t+1 << endl;
		int A, B; cin >> A >> B;
		big res = 0;
		for(int i = A ; i <= B ; i++){
			Num n1(i);
			set<int> ss;
			for(int j = 0 ; j < s(n1.sVal) ; j++){
				string s = n1.sVal.substr(j, s(n1.sVal)-j);
				s += n1.sVal.substr(0, j);
				if(s[0] == '0')continue;
				Num n2(s);
				if(i < n2.nVal && n2.nVal >= A && n2.nVal <= B){
					ss.insert(n2.nVal);
				}
			}
			res += s(ss);
		}

		cout << "Case #" << t+1 << ": " << res << endl;
	}

	return 0;
}
