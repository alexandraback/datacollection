#include <iostream>
#include <string>

char transl[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
  int T;
  std::cin >> T;
  std::string line;
  std::getline(std::cin, line);
  for ( int t = 1; t <= T; ++t )
  {
    std::getline(std::cin, line);
    std::cout << "Case #" << t << ": ";
    for ( size_t i = 0; i < line.length(); ++i )
    {
      if ( line[i] < 'a' or line[i] > 'z' )
        std::cout << line[i];
      else
        std::cout << transl[line[i] - 'a'];
    }
    std::cout << '\n';
  }
  return 0;
}
