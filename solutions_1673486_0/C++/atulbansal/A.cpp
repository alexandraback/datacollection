#include "../jam.h"

// finish typing
double solve1(int A, int B, vector<double> &p) {
   double correct_first = 1; // prob. of correct first time
   for (int i=0;i<A;i++) {
      correct_first = correct_first*p[i];
   }
   
   return correct_first*(B-A+1) + (1-correct_first)*(B-A+1+B+1);
}

// pressing backspace
double solve2(int A, int B, vector<double> &p) {
   double ret = 100*B;
   // press bs j times
   for (int j=1;j<=A;j++) {
      double correct = 1.0;
      for (int i=0;i<A-j;i++) {
         correct = correct * p[i];
      }
      double val = correct*(j+B-A+j+1) + (1-correct)*((j+B-A+j+1)+B+1);
      //cout << " back " << j << "val " << val << "\n";
      ret = min(ret, val);
   }

   return ret;
}

// pressing enter
double solve3(int A, int B, vector<double> &p) {
   return 2+B;
}



void solve(int casenum) {
   int A,B;
   in >>  A >> B;
   vector<double> p;
   double t;
   for (int i=0; i<A ;i++) {
      in >> t;
      p.push_back(t);
   }

   double ret1 = solve1(A,B,p);
   double ret2 = solve2(A,B,p);
   double ret3 = solve3(A,B,p);
 
   // cout << ret1 << " " << ret2 << " " << ret3 << "\n";
 
   double ret = min(min(ret1, ret2), ret3);

   out << "Case #" << casenum << ": " << ret << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("small.in");
	out.open("output.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
