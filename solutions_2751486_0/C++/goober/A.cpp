#include <string>
#include <iostream>

int main()
{
  int T;
  std::cin >> T;
  
  for (int t=1; t<=T; t++)
  {
    std::string s;
    long long n;
    std::cin >> s >> n;


    long long res = 0;
    
    int L = s.size();
    int conso = 0;
    int last = 0;
    for (int i=0; i<L; i++)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        conso = 0;
      else
        conso++;
      
      if (conso >= n)
        last = i-(n-1) + 1;
      res += last;
    }
    std::cout << "Case #" << t << ": " << res << std::endl;
  }
  return 0;
}
