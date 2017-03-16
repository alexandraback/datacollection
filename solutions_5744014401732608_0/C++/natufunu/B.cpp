#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class ProblemSolver {
public:
   ProblemSolver(istream& in, ostream& out) :
      in(in),
      out(out) { }

   void solve()
   {
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

vector<int> to_binary(long long num)
{
   if (num == 0) {
      return {0};
   }
   else if (num == 1) {
      return {1};
   }

   long long new_num = num;
   if (new_num % 2 == 1) {
      auto vec = to_binary((num - 1) / 2);
      vec.push_back(1);
      return vec;
   }
   else {
      auto vec = to_binary(num / 2);
      vec.push_back(0);
      return vec;
   }
}

vector<int> to_length_k_binary(long long num, size_t k) {
   auto vec = to_binary(num);
   vector<int> zeros;
   for (size_t i = 0; i < k - vec.size(); i++) {
      zeros.push_back(0);
   }

   zeros.insert(zeros.end(), vec.begin(), vec.end());
   return zeros;
}

void ProblemSolver::solve_case(int t)
{
   size_t B;
   long long M;
   in >> B >> M;
   out << "Case #" << t << ": ";

   if (M <= pow(2, B - 2)) {
      out << "POSSIBLE" << endl;

      if (M == pow(2, B-2)) {
         out << 0;
         for (int i = 2; i <= B; i++) {
            out << 1;
         }
         out << endl;
      }
      else {
         out << 0;
         for (int i : to_length_k_binary(M, B - 2)) {
            out << i;
         }
         out << 0 << endl;
      }

      for (int b = 2; b <= B; b++) {
         for (int i = 1; i <= B; i++) {
            out << (i <= b ? 0 : 1);
         }
         out << endl;
      }
   }
   else {
      out << "IMPOSSIBLE" << endl;
   }
}

int main()
{
//   istream& in = cin;
   ifstream in;
//   in.open("../instances/B-small-practice.in");
   in.open("../instances/B-small-attempt1.in");
//   in.open("../instances/B-small.in");
//   in.open("../instances/B-large.in");

//   ostream& out = cout;
   ofstream out;
   out.open("../instances/B-small.out");
//   out.open("../instances/B-large.out");

   if (not in) {
      cout << "could not open file!" << endl;
      return 1;
   }

   ProblemSolver solver{in, out};
   solver.solve();

   return 0;
}

