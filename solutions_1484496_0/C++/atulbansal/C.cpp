#include "../../jam.h"


long long sum(vector<int> &C, int s) {
   long long ret = 0;
   for(int i=0;i<20;i++) {
      if (s & (1<<i)) ret += C[i];
   }
   return ret;
}

void solve(int casenum) {
   int N;
   in >>  N;
   vector<int> C;
   int t;
   for(int i=0;i<N;i++) {
      in >> t;
      C.pb(t);
   }

   map<long long, int> mymap;

   out << "Case #" << casenum << ": " << endl;
   for (int i=0; i<(1<<20); i++) {
        if (mymap.find(sum(C,i)) != mymap.end()) {
            // found a match
            int first = mymap[sum(C,i)];
            int second = i;
            for (int j=0;j<20;j++) {
               if (first & (1<<j)) out << C[j] << " ";
            }
            out << endl;
            for (int j=0;j<20;j++) {
               if (second & (1<<j)) out << C[j] << " ";
            }
            out << endl;
            return;
        }
        else {
           // insert in the map
           mymap[sum(C,i)] = i;
        }
   }

   // here if match not found
   out << "Impossible" << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("C-small-attempt0.in");
	out.open("output.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
