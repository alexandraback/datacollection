#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class ProblemSolver {
public:
   ProblemSolver(istream& in, ostream& out) :
      in(in), out(out) {}

   void solve() {
      int T;
      in >> T;

      for (int t = 1; t <= T; t++) {
         solve_case(t);
      }
   }

private:
   void solve_case(int t);

   istream& in;
   ostream& out;
};

void ProblemSolver::solve_case(int t)
{
   int J, P, S, K_in;
   in >> J >> P >> S >> K_in;
   const int K = min(S, K_in);
   out << "Case #" << t << ": " << J*P*K << endl;

   for (int j = 0; j < J; j++) {
      for (int p = 0; p < P; p++) {
         for (int k = 0; k < K; k++) {
            int s = (j + p + k) % S;
            out << j + 1 << " " << p + 1 << " " << s + 1 << endl;
         }
      }
   }

}

int main()
{
//   istream& in = cin;
   ifstream in;
   in.open("../instances/C-small-attempt0.in");
//   in.open("../instances/C-small.in");
//   in.open("../instances/C-large.in");

//   ostream& out = cout;
   ofstream out;
   out.open("../instances/C-small.out");
//   out.open("../instances/C-large.out");

   if (not in) {
      cout << "could not open file!" << endl;
      return 1;
   }

   ProblemSolver solver{in, out};
   solver.solve();

   return 0;
}

