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
#include<cassert>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


#define NUM_TYPE	 int
struct Num{NUM_TYPE nVal;string sVal;Num(string str){sVal = str;istringstream stream(sVal);stream >> nVal;}Num(NUM_TYPE n){nVal = n;ostringstream stream(sVal);stream << fixed << n;sVal = stream.str();}};

string a[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string b[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities","so it is okay if you want to just give up"};
map<char, char> m;

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	m[' '] = ' ';
	m['q'] = 'z';
	m['z'] = 'q';
	for(int i = 0 ; i < 3 ; i++){
		int s = s(a[i]);
		for(int j = 0 ; j < s ; j++){
			if(a[i][j] == ' ')continue;
			if(m.count(a[i][j]) && m[a[i][j]] != b[i][j]){
				cout << i << " " << j << " " << a[i][j] << " " << b[i][j] << " " << m[a[i][j]] << endl;
				assert(false);
			}
			m[a[i][j]] = b[i][j];
		}
	}

//	for(char i = 'a' ; i <= 'z' ; i++)
//		cout << i << " " << m[i] << endl;

	int tt; scanf("%d ", &tt);
	for(int t = 0 ; t < tt ; t++){
		cerr << "Solving testcase " << t+1 << endl;

		string str; getline(cin, str);
		string res = "";
		for(int i = 0 ; i < s(str) ; i++){
			res += m[str[i]];
		}

		cout << "Case #" << t+1 << ": " << res << endl;
	}

	return 0;
}
