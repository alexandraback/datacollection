#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

#define REP(i,a,b)		for(i=(int)a ; i<=(int)b ; i++)
#define FOR(i,N)		REP(i,0,N-1)

#define VI				vector<double>
#define VVI				vector<VI>

using namespace std;

int A,B;
VI p;

int main(){
	ifstream cin("input.txt");
	ofstream cout("a.out");
	int T;
	cin >> T;
	int cnt;
	REP(cnt,1,T){
		int i,j,k;
		cin >> A >> B;
		p.resize(A);
		FOR(i,A)
			cin >> p[i];
		p.push_back(0);

		VI cp(A+1);
		cp[0]=1;
		FOR(i,A)
			cp[i+1] = cp[i]*p[i];
		FOR(i,A+1)
			cp[i] = cp[i]*(1-p[i]);

		VI cump(A+1);
		cump[0] = 1;
		FOR(i,A)
			cump[i+1] = cump[i] - cp[i];

		double ans = B+2;
		FOR(i,A+1){
			int n =  (A-i)+(A-i)+(B-A)+1;
			double exp = n*cump[i] + (n+B+1)*(1-cump[i]);
			if(exp < ans)
				ans = exp;
		}

		char out[100];
		sprintf(out,"%.6f",ans);

		cout << "Case #"<<cnt<<": "<< out <<endl;
	}
}