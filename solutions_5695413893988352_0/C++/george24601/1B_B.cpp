#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
unknown: phone #
length unknown
condition: non-decreasing number
S, completely reordered => i.e., can reorder whichever way we want
S < 2000

500 digits, each has 9 choices => bad!

# of Z = # of 0s
# of U = # of 4s
# of X  = # of 6s
pretty much a linear equation!

 */

string C;
string J;
int N;
int const MaxSize = 20;

bool possible(int nn, string s){
//	cout << nn << " " << s << endl;

	int num = nn;
	for(int i = s.length() - 1; i >= 0; i--){
		int digit = num % 10;
		num = (num / 10);
		char c = s[i];

		//cout << c << " " << digit << endl;


		if('?' == c || digit == (c - '0')){
			continue;
		}else{
			return false;
		}

	}

//	cout << "good!!" << endl;

	return true;
}

void p(int num){
	cout << " ";

	string os = std::to_string(num);

	LP(i, 0, N - os.length())
		cout << "0";

	cout << os;
	//cout << num;
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	freopen("/Users/georgeli/B_1.out", "w", stdout);

	int T;

	scanf("%d", &T);

	//cout << T << endl;

	LPE(cn, 1, T)
	{
		cin >> C >> J;

		//cout << C << " " << J;

		N = C.length();

		int minDiff = INF;

		int minC = -1;
		int minJ = -1;

		int maxV = pow(10, N);

		LP(c, 0, maxV){
			LP(j, 0, maxV){

//				cout << "-----" << endl;

				if(possible(c, C) && possible(j, J)){
//					cout << c << " " << j << endl;

					if(abs(c - j) < minDiff){
						minC = c;
						minJ = j;
						minDiff = abs(c - j);
					}
				}
			}
		}

		printf("Case #%d:", cn);
		p(minC);
		p(minJ);
		printf("\n");
	}

	return 0;

}
