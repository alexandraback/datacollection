#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

//{{{ Predefined functions : read<T>() and readLine(bool newLine = true)
bool read_LastReadWasLine = true;
template <typename T>
T read() {
    T t;
    std::cin >> t;
    read_LastReadWasLine = false;
    return t;
}
std::string readLine(bool newLine = true) {
    std::string s;
    if (newLine && !read_LastReadWasLine) {
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    std::getline(std::cin, s);
    read_LastReadWasLine = true;
    return s;
}
//}}}

typedef std::vector<std::vector<int>> arcs;

std::unordered_multiset<int> Reachable(int i, const arcs &A) {
   std::unordered_multiset<int> res{i};
   for (int j : A[i]) {
      std::unordered_multiset<int> o = Reachable(j, A);
      res.insert(o.begin(), o.end());
   }
   return res;
}

bool Diamond(int i, const arcs &A) {
   int last = -1;
   for (int j : Reachable(i, A)) {
      if (j == last) return true;
      last = j;
   }
   return false;
}

std::string TestCase() {
   int N = read<int>();
   arcs A(N);
   for (int i = 0 ; i < N ; ++i)
      for (int j = 0, M = read<int>() ; j < M ; ++j)
         A[i].push_back(read<int>() - 1);

   for (int i = 0 ; i < N ; ++i)
      if (Diamond(i, A))
         return "Yes";
   return "No";
}

//{{{ Predefined function : main (should fit with GCJ's requirements)
int main(int, char**)
{
    int N = read<int>();
    for (int I = 1 ; I <= N ; ++I) {
        std::cout << "Case #" << I << ": " << TestCase() << std::endl;
    }
}
//}}}
