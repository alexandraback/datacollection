#include "jam.h"

map<char, char> mapping;

void solve(int casenum) {
   int N,S,p;
   in >> N; //cout << N << endl;
   in >> S; //cout << S << endl;
   in >> p; //cout << p << endl;
   vector<int> tot_scores;
   int t;
   for (int i = 0; i < N; i++) {
      in >> t;
      tot_scores.push_back(t);
   }
   int ans = 0;

   for(int i=0; i<N; i++) {
      if (tot_scores[i] >= 3*p) { ans++; }
      else if (tot_scores[i] >= 3*p - 2 && (tot_scores[i] >=1)) { ans++; }
      else if ((tot_scores[i] >= 3*p - 4) && S > 0 && (tot_scores[i] >=2)) { S--; ans++;  }
   }

   out << "Case #" << casenum << ": " << ans << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("B-small-attempt1.in");
	out.open("output.txt");
	int T;
	in >> T;
    //cout << T << endl;
	for (int i=0;i<T;i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
