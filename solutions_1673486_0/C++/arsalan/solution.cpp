#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

#define For(I,A,B) for(int I = A; I < B; ++I)

int main(){
	ifstream cin ("A-small-attempt0 (1).in");
	ofstream cout ("out.txt");
	int T,t=0;
	cin >> T;
	while (T--){
		int a,b;
		cin >> a >> b;
		vector<double> P(a);
		For(i,0,a)
			cin >> P[i];
		vector <double> pr (a+1);
		long double p=1,q=0;
		For (k,1,a+1){
			p *= P[k-1];
			q = 1 - p;
			pr[k-1] = p * (2 * (a - k) + b - a + 1) + q * (2 * (a - k) + b - a + 1 + b + 1);
		}
		pr[a] = 1 + b + 1;
		cout << "Case #" << ++t << ": " << fixed << setprecision(6) << *(min_element(pr.begin(),pr.end())) << endl;
	}
	return 0;
}

