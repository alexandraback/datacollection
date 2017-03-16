#include <iostream>
#include <string>

int main()
{
  //char map[] = "ynficwlbkuomxsevzpdrjgthaq";
  char map[] = "yhesocvxduiglbkrztnwjpfmaq";
  int n;
  std::string line;

  std::cin >> n;
  getline(std::cin, line);
  for (int i = 0; i < n; ++i) {
    getline(std::cin, line);
    for (int j = 0; j < line.size(); ++j)
      if (line[j] != ' ')
        line[j] = map[line[j] - 'a'];
    std::cout << "Case #" << (i + 1) << ": " << line << std::endl;
  }
  return 0;
}
