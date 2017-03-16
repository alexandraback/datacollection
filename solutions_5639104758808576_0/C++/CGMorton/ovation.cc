#include <fstream>

using namespace std;

int main()
{
   std::ifstream in ("o.in", std::ifstream::in);
   std::ofstream out ("o.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {
      long max_shy;
      string s;
      in >> max_shy;
      in >> s;

      long need = 0;
      long standing = 0;
      for (int shy = 0; shy <= max_shy; ++shy) {
         char c = s.at(shy);
         int shy_guys = (int)(c - '0');
         if (standing >= shy)
            standing += shy_guys;
         else {
            long extra = (shy - standing);
            standing += shy_guys + extra;
            need += extra;
         }
      }

      out << "Case #" << i << ": " << need << endl;
   }
   return 0;
}




