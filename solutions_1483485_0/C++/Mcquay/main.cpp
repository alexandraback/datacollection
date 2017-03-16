#include <fstream>
#include <map>

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   std::map<char, char> data;
   data[' '] = ' ';
   data['a'] = 'y';
   data['c'] = 'e';
   data['b'] = 'h';
   data['e'] = 'o';
   data['d'] = 's';
   data['g'] = 'v';
   data['f'] = 'c';
   data['i'] = 'd';
   data['h'] = 'x';
   data['k'] = 'i';
   data['j'] = 'u';
   data['m'] = 'l';
   data['l'] = 'g';
   data['o'] = 'k';
   data['n'] = 'b';
   data['q'] = 'z';
   data['p'] = 'r';
   data['s'] = 'n';
   data['r'] = 't';
   data['u'] = 'j';
   data['t'] = 'w';
   data['w'] = 'f';
   data['v'] = 'p';
   data['y'] = 'a';
   data['x'] = 'm';
   data['z'] = 'q';

   size_t T = 0;
   in >> T;
   std::string input;
   std::getline(in, input);

   for (size_t X = 0; X != T; ++X)
   {
      std::getline(in, input);
      for (size_t l = 0; l != input.size(); ++l)
         input[l] = data[input[l]];

      out << "Case #" << X + 1 << ": " << input << std::endl;
   }
   return 0;
}
