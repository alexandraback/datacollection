#include <iostream>
#include <string>


int main()
{
  int T;
  std::string G;
  char alphabets[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

  std::cin >> T;
  std::cin.ignore();

  for (int i = 1; i <= T; ++i)
  {
    std::getline(std::cin, G);
    for (unsigned j = 0; j < G.size(); ++j)
      if (G[j] >= 'a' && G[j] <= 'z')
        G[j] = alphabets[G[j] - 'a'];

    std::cout << "Case #" << i << ": " << G << std::endl;
  }
}
